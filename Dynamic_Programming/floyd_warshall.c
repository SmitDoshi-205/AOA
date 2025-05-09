#include<stdio.h>

int graph[100][100]; //adjacency matrix
int dist[100][100]; //calculating final distance matrix
int V; //no of vertices
#define INF 99999

void floyd_warshall(){
    int i,j,k;
     //copying original content to dist array
     for(i=0; i<V; i++){
         for(j=0; j<V; j++){
             dist[i][j] = graph[i][j];
         }
     }
     
     //floyd_warshall
     for(k=0; k<V; k++){
         for(i=0; i<V; i++){
             for(j=0; j<V; j++){
                 if(dist[i][k] + dist[k][j] < dist[i][j]){
                     dist[i][j] = dist[i][k] + dist[k][j];
                 }
             }
         }
     }
}

void main(){
    int i,j;
    printf("Enter the no of vertices-");
    scanf("%d", &V);
    
    printf("Enter the adjacency matrix (-1 for no direct path)-\n");
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            scanf("%d", &graph[i][j]);
            if(i != j && graph[i][j] == -1) {
                graph[i][j] = INF;
            }
        }
    }
    
    floyd_warshall();
    
    //printing final matrix
    printf("\nFinal Matrix : \n");
    for(i=0; i<V; i++){
        for(j=0; j<V; j++){
            if(dist[i][j] == INF){
                printf("%d ", INF);
            }
            else{
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}