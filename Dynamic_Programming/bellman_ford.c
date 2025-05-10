#include<stdio.h>

int V; //vertices
int E; //edges
int u[100]; //edges u --> v with weight = w
int v[100];
int w[100]; //weight/distance
int dist[100]; //shortest path from source to all nodes
int src; //source node
#define INF 9999

void bellmanFord(){
    int i,j;
    for(i=0; i<V; i++){
        dist[i] = INF; //initial condition
    }
    dist[src] = 0;
    
    for(i=0; i<=V-1;i++){ //relaxing V-1 times
        for(j=0; j<E; j++){
            if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]){
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }
    
    //negative weight cycle
    for(j=0; j<E; j++){
       if(dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]){
           printf("\nNegative Weight Cycle Detected");
           return;
       } 
    }
    
    //final answer
    for(i=0; i<V; i++){
        if(dist[i] == INF){
            printf("Vertex %d : INF\n", i);
        }
        else{
            printf("Vertex %d : %d\n", i, dist[i]);
        }
    }
}

void main(){
    int i;
    printf("Enter the no of vertices and edges-");
    scanf("%d %d", &V, &E);
    
    printf("Enter the edges (source destination weight format) - \n");
    for(i=0; i<E; i++){
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }
    
    printf("Enter the source vertex - ");
    scanf("%d", &src);
    
    bellmanFord();
}