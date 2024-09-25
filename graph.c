#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to find the minimum number of colors required to color the graph
void greedyColoring(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int result[numVertices];

    result[0] = 0; // Assign the first color to the first vertex

    for (int i = 1; i < numVertices; i++) {
        result[i] = -1; // No color is assigned to vertex i initially
    }

    bool available[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        available[i] = true; // Initially, all colors are available
    }

    for (int u = 1; u < numVertices; u++) {
        for (int i = 0; i < numVertices; i++) {
            if (graph[u][i] && result[i] != -1) {
                available[result[i]] = false; // Mark the color as unavailable
            }
        }

        int cr;
        for (cr = 0; cr < numVertices; cr++) {
            if (available[cr]) {
                break;
            }
        }

        result[u] = cr; // Assign the found color to vertex u

        for (int i = 0; i < numVertices; i++) {
            if (graph[u][i]) {
                available[result[i]] = true; 
            }
        }
    }

    // Print the result
    printf("Vertex\tColor\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\n", i, result[i]);
    }
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (format: u v) where u and v are vertices connected by an edge:\n");
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    greedyColoring(graph, numVertices);

    return 0;
}
