#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];  // Adjacency matrix
int path[MAX];        // Stores the path of the cycle
int V;                // Number of vertices

// Check if vertex v can be added at position pos in the path
int isSafe(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0) // Not connected to previous vertex
        return 0;

    for (int i = 0; i < pos; i++)     // Check if already in path
        if (path[i] == v)
            return 0;

    return 1;
}

// Recursive utility to build Hamiltonian Cycle
int hamCycleUtil(int pos) {
    if (pos == V) {  // All vertices are included
        if (graph[path[pos - 1]][path[0]] == 1) // Check if last connects to first
            return 1;
        else
            return 0;
    }

    for (int v = 1; v < V; v++) {  // Try all vertices except starting one
        if (isSafe(v, pos)) {
            path[pos] = v;  // Include vertex in path
            if (hamCycleUtil(pos + 1)) // Recur for next position
                return 1;
            path[pos] = -1; // Backtrack
        }
    }
    return 0;
}

int main() {
    // User input for number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Initialize the path with -1 (not visited)
    for (int i = 0; i < V; i++) path[i] = -1;
    path[0] = 0; // Start from vertex 0

    // Try to find Hamiltonian Cycle
    if (hamCycleUtil(1)) {
        printf("Hamiltonian Cycle Found:\n");
        for (int i = 0; i < V; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]); // Complete the cycle
    } else {
        printf("No Hamiltonian Cycle exists.\n");
    }

    return 0;
}