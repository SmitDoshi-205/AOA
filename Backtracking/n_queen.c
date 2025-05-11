#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int x[100]; //stores the position of queens

//tells whether queen can be place in a particular position or not
bool place(int k, int i){
    int j;
    for(j=0; j<k; j++){
        //queen cannot be placed in same column or diagnol
        if(x[j] == i || abs(x[j]-i) == abs(j-k)){
            return false;
        }
    }
    return true;
}

//backtracking
void nQueens(int k, int n){
    int i,j;
    for(i=0; i<n; i++){
        if(place(k,i)){
            x[k] = i;
            if(k == n-1){
                for(j=0; j<n; j++){
                    printf("%d ", x[j]);
                }
                printf("\n");
            }
            else{
                nQueens(k+1, n);
            }
        }
    }
}

void main(){
    int n;
    printf("Enter number of queens: ");
    scanf("%d", &n);
    nQueens(0, n);
}