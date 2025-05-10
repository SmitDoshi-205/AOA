#include<stdio.h>

int m[100][100]; //stores minimum multiplication
int s[100][100]; //stores index for parenthesization
int d[100]; //stores dimensions of 'n' matrix
int n; //no of matrix

void matrix_chain_multiplication(){
    int i,j,k,l;
    int min_mul;
    //same index = 0 multiplications
    for(i=1; i<=n; i++){
        m[i][i] = 0;
    }
    
    for(l=2; l<=n; l++){  //matrix chain length
        for(i=1; i<=n-l+1; i++){
            j = i+l-1;   
            m[i][j] = 9999;
            for(k=i; k<j; k++){
               min_mul = m[i][k] + m[k+1][j] + (d[i-1] * d[k] * d[j]);
               if(min_mul < m[i][j]){
                   m[i][j] = min_mul;
                   s[i][j] = k;
               }
            }
        }
    }
}

void parenthesization(int i, int j){
    if(i == j){
        printf("A%d", i);
    }
    
    else{
        printf(" ( ");
        parenthesization(i, s[i][j]);  //left sub-chain
        parenthesization(s[i][j]+1, j);  //right sub-chain
        printf(" ) ");
    }
}

void main(){
    int i;
    printf("Enter the no of matrix-");
    scanf("%d", &n);
    
    printf("Enter the dimensions of matrix-\n");
    for(i=0; i<=n; i++){
        printf("Dimension d%d = ", i);
        scanf("%d", &d[i]);
    }
    
    matrix_chain_multiplication();
    printf("Minimum Multiplications = %d\n", m[1][n]);
    
    parenthesization(1, n);
}