#include<stdio.h>

int value[100]; //profits of items
int weight[100]; //weights of items
int dp[100][100]; //value x weight table
int n; //no of objects
int M; //maximum knapsack capacity

int max(int a, int b){
    return (a > b) ? a : b;
}

void knapsack(){
    int i,j;
    for(i=0; i<=n; i++){  //loop for no of items
        for(j=0; j<=M; j++){  //loop for weights 
            if(i==0 || j==0){  //base condition
                dp[i][j] = 0;
            }
            
            else if(weight[i-1] <= j){  //when available weight < total capacity
                dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j - weight[i-1]]);
            }
            
            else{
                dp[i][j] = dp[i-1][j];  
            }
        }
    }
    
    printf("Maximum Profit = %d\n", dp[n][M]);
    
    //selected items
    j = M;
    printf("Selected Items : \n");
    for(i=n; i>0 && j>0; i--){
        if(dp[i][j] != dp[i-1][j]){
            printf("Item %d\n", i);
            j -= weight[i-1];
        }
    }
}

void main(){
    int i,j;
    printf("Enter the no of items-");
    scanf("%d", &n);
    
    printf("Enter the knapsack capacity-");
    scanf("%d", &M);
    
    printf("Enter the profits and weights of each items-\n");
    for(i=0; i<n; i++){
        printf("Profit and Weight of Item %d - ", i+1);
        scanf("%d %d", &value[i], &weight[i]);
    }
    
    knapsack();
}