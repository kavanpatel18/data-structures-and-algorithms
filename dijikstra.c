#include <stdio.h>
#include <stdbool.h>
#define MAX 10      // Maximum number of vertices
#define INF 9999    // Representation of infinity (no connection)

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX];               // dist[i] stores the shortest distance from source to vertex i
    bool visited[MAX] = {false}; // visited[i] is true if shortest distance to i is finalized

    // Step 1: Initialize all distances as infinity
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0; // Distance to source itself is always 0

    // Step 2: Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        int minDist = INF;  // Store the minimum distance value
        int minIndex = -1;  // Store the index of the vertex with the minimum distance

        // Step 2.1: Pick the unvisited vertex with the smallest distance
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minIndex = v;
            }
        }

        // If no vertex is reachable (disconnected graph), break the loop
        if (minIndex == -1)
            break;

        // Mark the selected vertex as visited
        visited[minIndex] = true;

        // Step 2.2: Update distance values of adjacent vertices
        for (int v = 0; v < n; v++) {
            // Conditions to update:
            // 1. Vertex v is not visited
            // 2. There is an edge between minIndex and v (graph[minIndex][v] != 0)
            // 3. Total weight of path through minIndex is smaller than current dist[v]
            if (!visited[v] && graph[minIndex][v] && dist[minIndex] != INF
                && dist[minIndex] + graph[minIndex][v] < dist[v]) {
                dist[v] = dist[minIndex] + graph[minIndex][v];
            }
        }
    }

    // Step 3: Print the final shortest distances
    printf("\nVertex\tDistance from Source (%d)\n", start);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d\tNo Path\n", i); // No connection found
        else
            printf("%d\t%d\n", i, dist[i]); // Print distance
    }
}

int main() {
    int graph[MAX][MAX], n, start;

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input adjacency matrix
    // 0 indicates no edge between vertices
    printf("\nEnter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the starting vertex
    printf("\nEnter the starting vertex: ");
    scanf("%d", &start);

    // Call Dijkstra's algorithm
    dijkstra(graph, n, start);

    return 0;
}
