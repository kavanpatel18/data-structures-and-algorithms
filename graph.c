#include <stdio.h>
#include <stdlib.h>

// Node structure for Graph using Adjacency List
struct Node {
    int data;               // Vertex number
    struct Node* next;      // Pointer to the next vertex (connected edge)
};

// Function to create a new node for adjacency list
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an edge in the adjacency list
// For an undirected graph, edges are added both ways (src -> dest and dest -> src)
void insertEdge(struct Node* adj[], int src, int dest) {
    // Add destination vertex to the source’s list
    struct Node* newNode = createNode(dest);
    newNode->next = adj[src];
    adj[src] = newNode;

    // Add source vertex to the destination’s list
    newNode = createNode(src);
    newNode->next = adj[dest];
    adj[dest] = newNode;
}

// Function to delete an edge from the graph (for both directions)
void deleteEdge(struct Node* adj[], int src, int dest) {
    struct Node *temp = adj[src], *prev = NULL;

    // Step 1: Remove 'dest' from 'src' adjacency list
    if (temp != NULL && temp->data == dest) { // Edge found at head
        adj[src] = temp->next;
        free(temp);
    } else {
        // Traverse to find 'dest'
        while (temp != NULL && temp->data != dest) {
            prev = temp;
            temp = temp->next;
        }
        // If found, unlink and free the node
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }

    // Step 2: Remove 'src' from 'dest' adjacency list (since undirected)
    temp = adj[dest];
    prev = NULL;
    if (temp != NULL && temp->data == src) { // Edge found at head
        adj[dest] = temp->next;
        free(temp);
    } else {
        // Traverse to find 'src'
        while (temp != NULL && temp->data != src) {
            prev = temp;
            temp = temp->next;
        }
        // If found, unlink and free the node
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }
}

// Function to display the adjacency list of the graph
void displayList(struct Node* adj[], int V) {
    for (int i = 0; i < V; i++) {
        struct Node* temp = adj[i];
        printf("Adjacency list of vertex %d\n head", i);
        while (temp) {
            printf(" -> %d", temp->data);  // Add spaces around the arrow
            temp = temp->next;
        }
        printf(" -> NULL\n");  // Add arrow before NULL for clarity
    }
}


int main() {
    int V, E;

    // Input number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Allocate memory for adjacency list array
    struct Node** adj = (struct Node**)malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++)
        adj[i] = NULL;  // Initialize all heads to NULL

    // Input number of edges
    printf("Enter number of edges: ");
    scanf("%d", &E);

    // Input all edges
    for (int i = 0; i < E; i++) {
        int src, dest;
        printf("Enter edge (source destination): ");
        scanf("%d %d", &src, &dest);

        // Validate vertex range
        if (src >= 0 && src < V && dest >= 0 && dest < V)
            insertEdge(adj, src, dest);
        else {
            printf("Invalid edge! Try again.\n");
            i--; // Repeat this iteration
        }
    }

    int choice, src, dest;

    // Menu-driven interface for graph operations
    do {
        printf("\n---- Graph Operations ----\n");
        printf("1. Insert Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Display Graph\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add a new edge
                printf("Enter source and destination vertices: ");
                scanf("%d %d", &src, &dest);
                insertEdge(adj, src, dest);
                break;

            case 2:
                // Delete an existing edge
                printf("Enter source and destination vertices to delete edge: ");
                scanf("%d %d", &src, &dest);
                deleteEdge(adj, src, dest);
                break;

            case 3:
                // Display current adjacency list
                displayList(adj, V);
                break;

            case 4:
                // Exit the program
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    // Free memory before exit
    for (int i = 0; i < V; i++) {
        struct Node* temp = adj[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adj);

    return 0;
}
