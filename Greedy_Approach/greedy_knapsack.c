#include<stdio.h>

int profit[100]; //profit of objects
int weight[100]; //weight of objects
float ratio[100]; //p/w ratio of all objects
float selected[100]; //selected objects
int m; //maximum knapsack capacity
int n; //no of objects
float total_profit = 0;

void greedy_knapsack(){
    int i,j;
    float temp;
    int tempP,tempW;
    
    //calculate profit/weight ratio
    for(i=0; i<n; i++){
        ratio[i] = (float)profit[i]/weight[i];
    }
    
    //sort the items according to the ratio
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(ratio[j] < ratio[j+1]){
                temp = ratio[j+1];
                ratio[j+1] = ratio[j];
                ratio[j] = temp;
                
                tempP = profit[j+1];
                profit[j+1] = profit[j];
                profit[j] = tempP;
                
                tempW = weight[j+1];
                weight[j+1] = weight[j];
                weight[j] = tempW;
            }
        }
    }
    
    //taking items
    for(i=0; i<n && m>0; i++){
        if(weight[i] <= m){
            total_profit += profit[i];
            selected[i] = 1.0;
            m -= weight[i];
        }
        else{
            total_profit += (ratio[i] * m);
            selected[i] = (float)m/weight[i];
            m = 0;
        }
    }
}

void main(){
    int i;
    printf("Enter the no of items : ");
    scanf("%d", &n);
    
    printf("Enter the knapsack capacity : ");
    scanf("%d", &m);
    
    printf("Enter the profit and weight of items :\n");
    for(i=0; i<n; i++){
        printf("Item %d : ", i+1);
        scanf("%d %d", &profit[i], &weight[i]);
    }
    
    greedy_knapsack();
    
    printf("Profits : ");
    for(i=0; i<n; i++){
        printf("%d ", profit[i]);
    }
    printf("\n");
    
    printf("Weights : ");
    for(i=0; i<n; i++){
        printf("%d ", weight[i]);
    }
    printf("\n");
    
    printf("P/W Ratio : ");
    for(i=0; i<n; i++){
        printf("%.2f ", ratio[i]);
    }
    
    printf("\nTotal Profit = %.2f", total_profit);
    
    printf("\nItems Selected :\n");
    for(i=0; i<n; i++){
        printf("Item %d : %.2f\n", i+1, selected[i]);
    }
    
}