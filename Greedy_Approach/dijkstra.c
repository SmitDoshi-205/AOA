#include<stdio.h>

#define INF 9999
int V, E; //vertices and edges
int graph[100][100];
int dist[100]; //final shortest distance
int visited[100];
int src; //source vertex

void dijkstra(){
    int i, j, u, min;

    for(i=0; i<V; i++){
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for(i=0; i<V; i++){
        // pick unvisited vertex with minimum distance
        min = INF;
        for(j=0; j<V; j++){
            if(!visited[j] && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // relax nodes connected to u
        for(j=0; j<V; j++){
            if(graph[u][j] && !visited[j] && dist[u] + graph[u][j] < dist[j]){
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    // final answer
    for(i=0; i<V; i++){
        if(dist[i] == INF)
            printf("Vertex %d : INF\n", i);
        else
            printf("Vertex %d : %d\n", i, dist[i]);
    }
}

void main(){
    int i, u, v, w;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    // initialize graph
    for(i=0; i<V; i++)
        for(int j=0; j<V; j++)
            graph[i][j] = 0;

    printf("Enter edges (source destination weight format):\n");
    for(i=0; i<E; i++){
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;  
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra();
}