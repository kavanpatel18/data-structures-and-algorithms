#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum number of vertices allowed

// Node structure for the adjacency list
struct Node {
    int vertex;           // Stores the adjacent vertex number
    struct Node* next;    // Pointer to the next node in the list
};

// Array of pointers representing the adjacency list
struct Node* adjList[MAX];
int visited[MAX];         // Array to mark visited vertices
int stack[MAX], top = -1; // Stack and top pointer for DFS traversal
int n;                    // Number of vertices

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge between two vertices (undirected graph)
void addEdge(int src, int dest) {
    // Add edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge from dest to src (since undirected)
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Function to push a vertex onto the stack
void push(int vertex) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = vertex;
}

// Function to pop a vertex from the stack
int pop() {
    if (top == -1)
        return -1; // Return -1 if stack is empty
    else
        return stack[top--];
}

// Depth First Search using adjacency list
void dfs(int start) {
    push(start);           // Push starting vertex
    visited[start] = 1;    // Mark it as visited

    printf("DFS Path: ");

    while (top != -1) {
        int current = pop();    // Pop a vertex from the stack
        printf("%d ", current);

        // Traverse the adjacency list of the current vertex
        struct Node* temp = adjList[current];
        while (temp != NULL) {
            int adjVertex = temp->vertex;

            // If vertex not visited, push onto stack and mark visited
            if (!visited[adjVertex]) {
                push(adjVertex);
                visited[adjVertex] = 1;
            }
            temp = temp->next;  // Move to next adjacent vertex
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list and visited array
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);   // Add edge to adjacency list
    }

    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    dfs(start);   // Perform DFS
    printf("\n");

    return 0;
}
