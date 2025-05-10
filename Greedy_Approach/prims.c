#include<stdio.h>

int graph[100][100]; //adjacency matrix
int visited[100] = {0}; //by-default, none of the vertices are visited
int key[100]; //store the minimum weight
int parent[100]; //stores parent node
int V; //no of vertices
int totalWeight = 0; //total weight of MST

//find minimum node
int minKey(){
    int i;
    int index = -1;
    int min = 9999;
    for(i=0; i<V; i++){
        if(visited[i]==0 && key[i]<min){
            min = key[i];
            index = i;
        }
    }
    return index;
}

void primsMST(){
    int i,j,k;
    for(i=0; i<V; i++){
        key[i] = 9999;
    }
    key[0] = 0; //start with vertex 0
    parent[0] = -1;
    
    for(i=0; i<V-1; i++){  //MST has V-1 edges
        k = minKey();
        visited[k] = 1;
        for(j=0; j<V; j++){
            if(visited[j] == 0 && graph[k][j] < key[j]){
                parent[j] = k;
                key[j] = graph[k][j];
            }
        }
    }
    
    //print MST
    printf("Edge \tWeight\n");
    for(i=1; i<V; i++){
        printf("%d - %d \t %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("\nTotal Weight = %d", totalWeight);
}

void main(){
    int i,j;
    printf("Enter no of vertices - ");
    scanf("%d", &V);
    
    printf("Enter Adjacency Matrix -\n");
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            scanf("%d", &graph[i][j]);
        }
    }
    
    primsMST();
}