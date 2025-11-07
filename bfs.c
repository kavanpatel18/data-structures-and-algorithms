#include <stdio.h>
#include <stdlib.h>

#define MAX 100   // Maximum number of vertices

// Global variables for queue, graph, and visited array
int queue[MAX], front = -1, rear = -1;  // Queue and its front/rear pointers
int visited[MAX];                        // Visited array to track visited vertices
int graph[MAX][MAX];                     // Adjacency matrix representation of graph
int n;                                   // Number of vertices (assigned in main)

// Function to insert (enqueue) a vertex into the queue
void enqueue(int vertex)
{
    if (rear == MAX - 1) {
        // If queue is full
        printf("Queue is full\n");
    } else {
        // If queue is empty, initialize front
        if (front == -1) front = 0;
        // Increment rear and add vertex
        rear++;
        queue[rear] = vertex;
    }
}

// Function to remove (dequeue) a vertex from the queue
int dequeue()
{
    int vertex;
   
    if (front == -1) {
        // If queue is empty
        printf("Queue is empty\n");
        return -1;
    } else {
        // Get the front element
        vertex = queue[front];
        front++;
       
        // If all elements are dequeued, reset front and rear
        if (front > rear) front = rear = -1;
    }
    return vertex;
}

// Breadth First Search function
void bfs(int start)
{
    enqueue(start);         // Enqueue the starting vertex
    visited[start] = 1;     // Mark start vertex as visited
   
    while (front != -1) {   // Continue until queue becomes empty
        int i;
        int current = dequeue();   // Dequeue a vertex
        printf("%d ", current);    // Print the current vertex
       
        // Explore all adjacent vertices of the current vertex
        for (i = 0; i < n; i++) {
            // If there is an edge and vertex not yet visited
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);        // Enqueue the vertex
                visited[i] = 1;    // Mark it as visited
            }
        }
    }
    printf("\n");
}

int main()
{
    int edges, src, dest, i;
   
    // Input number of vertices
    printf("Enter number of vertices - ");
    scanf("%d", &n);
   
    // Initialize graph (adjacency matrix) and visited arrays
    for (i = 0; i < n; i++) {
        visited[i] = 0;             // Mark all vertices as unvisited
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;        // Initialize adjacency matrix with 0s
        }
    }
   
    // Input number of edges
    printf("Enter number of edges - ");
    scanf("%d", &edges);
   
    // Input all edges of the graph
    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest) - ");
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < n && dest >= 0 && dest < n) {
            // Since graph is undirected, set both directions
            graph[src][dest] = graph[dest][src] = 1;
        } else {
            // Handle invalid vertex numbers
            printf("Invalid edge! Try again.\n");
            i--;  // Retry the current iteration
        }
    }
   
    // Start BFS traversal from vertex 0
    printf("BFS starting from vertex 0:\n");
    bfs(0);
   
    return 0;
}
