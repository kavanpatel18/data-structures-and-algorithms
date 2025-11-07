#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of vertices

int adjMatrix[MAX][MAX];  // Adjacency matrix
int visited[MAX];         // Array to track visited vertices
int stack[MAX], top = -1; // Stack and top pointer
int n;                    // Number of vertices

// Function to push an element onto the stack
void push(int vertex) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = vertex;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1)
        return -1; // Stack is empty
    else
        return stack[top--];
}

// Function to add an edge to the adjacency matrix (undirected graph)
void addEdge(int src, int dest) {
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1; // For undirected graph
}

// Depth First Search using adjacency matrix
void dfs(int start) {
    push(start);
    visited[start] = 1;

    printf("DFS Path: ");

    while (top != -1) {
        int current = pop();
        printf("%d ", current);

        // Check all adjacent vertices of 'current'
        for (int i = 0; i < n; i++) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;
    }

    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    int start;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &start);

    dfs(start);
    printf("\n");

    return 0;
}
