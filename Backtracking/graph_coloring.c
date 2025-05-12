#include <stdio.h>
#define MAX 20  // Max number of vertices

int graph[MAX][MAX];   // Adjacency matrix
int colors[MAX];       // Colors assigned to each vertex
int V;                 // Number of vertices

// Check if it's safe to assign color c to vertex v
int isSafe(int v, int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && colors[i] == c) // Adjacent vertex has same color
            return 0;
    return 1;
}

// Try to assign colors to vertices starting from vertex v
int graphColoring(int v, int m) {
    if (v == V)  // All vertices are colored
        return 1;

    for (int c = 1; c <= m; c++) {  // Try all colors
        if (isSafe(v, c)) {
            colors[v] = c; // Assign color
            if (graphColoring(v + 1, m)) // Recur for next vertex
                return 1;
            colors[v] = 0; // Backtrack
        }
    }
    return 0;
}

int main() {
    int m;  // Number of colors

    // User input for number of vertices and colors
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of colors: ");
    scanf("%d", &m);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    // Initialize all vertex colors to 0 (no color)
    for (int i = 0; i < V; i++) colors[i] = 0;

    // Try coloring the graph
    if (graphColoring(0, m)) {
        printf("Coloring possible:\n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i, colors[i]);
    } else {
        printf("Coloring not possible with %d colors.\n", m);
    }

    return 0;
}