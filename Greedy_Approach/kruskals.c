#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define max 100
int parent[max]; //stores the parent for each node

//finds the root of the vertex; checks for cycles in the MST
int find(int x) {
    while(parent[x] != x) {
        x = parent[x];
    }
    
    return x;
}

//merges the sets
void unionSet(int x, int y) {
    int a = find(x);
    int b = find(y);
    
    parent[a] = b;
}

int main() {
    int n, e;
    int u[max], v[max], w[max];
    
    printf("Enter number of Vertices: ");
    scanf("%d", &n);
    printf("Enter number of Edges: ");
    scanf("%d", &e);
    
    printf("Enter %d edges (u v w): \n", e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    
    // initialize parent array
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    // bubble sort edges by weight
    for(int i = 0; i < e - 1; i++) {
        for(int j = 0; j < e - i - 1; j++) {
            if(w[j] > w[j + 1]) {
                // swap u v w
                int tempW = w[j];
                w[j] = w[j + 1];
                w[j + 1] = tempW;
                
                int tempU = u[j];
                u[j] = u[j + 1];
                u[j + 1] = tempU;
                
                int tempV = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tempV;
            }
        }
    }
    
    printf("\nMinimum Spanning Tree:\n");
    int totalWt = 0;
    for(int i = 0; i < e; i++) {
        int a = find(u[i]);
        int b = find(v[i]);
        
        // if same then they already are in same set
        if(a != b) {
            printf("%d - %d : %d\n", u[i], v[i], w[i]);
            totalWt += w[i];
            unionSet(a, b);
        }
    }
    
    printf("\nTotal Weight: %d", totalWt);
}