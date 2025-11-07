
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5 // Number of vertices

// Find vertex with minimum key value from vertices not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == false && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Print the constructed MST
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Implement Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];    // Array to store constructed MST
    int key[V];       // Key values used to pick minimum weight edge
    bool mstSet[V];   // To track vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Always include first vertex in MST
    key[0] = 0;       // Make key 0 to pick first vertex
    parent[0] = -1;   // First node is always root of MST

    // MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick minimum key vertex not yet included in MST
        int u = minKey(key, mstSet);

        // Add picked vertex to MST
        mstSet[u] = true;

        // Update key and parent index of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph);
}

int main() {
    // Example graph
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);
    return 0;
}           