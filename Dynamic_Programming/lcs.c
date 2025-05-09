#include<stdio.h>
#include<string.h>

int c[100][100]; //stores the cost of comparison of srings
char b[100][100]; //stores the backtracking path
char X[100]; //string 
char Y[100]; //string

void LCS(char X[], char Y[], int m, int n){
    int i,j;
    
    //initial rows = 0
    for(i=1; i<=m; i++){
        c[i][0] = 0;
    }
    
    //inital columns = 0
    for(j=1; j<=n; j++){
        c[0][j] = 0;
    }
    
    //compute LCS table
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){ 
            if(X[i] == Y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'd'; //diagnol track
            }
            else if(c[i-1][j] > c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'u'; //up track
            }
            else{
                c[i][j] = c[i][j-1];
                b[i][j] = 'l'; //left track
            }
        }
    }
}

void printLCS(char X[], char b[100][100], int i, int j){
    if(i==0 || j==0){
        return;
    }
    if(b[i][j] == 'd'){
        printLCS(X,b,i-1,j-1);
        printf("%c", X[i]);
    }
    else if(b[i][j] == 'u'){
        printLCS(X,b,i-1,j);
    }
    else{
        printLCS(X,b,i,j-1);
    }
}

void main(){
    int m,n;
    
    printf("Enter string 1 - ");
    scanf("%s", X);
    
    printf("Enter string 2 - ");
    scanf("%s", Y);
    
    m = strlen(X);
    n = strlen(Y);
    
    LCS(X,Y,m,n);
    
    printf("\nCost Matrix :\n");
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    
    printf("\nBacktracking Matrix :\n");
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            printf("%c ", b[i][j]);
        }
        printf("\n");
    }
    
    printf("\nLCS : ");
    printLCS(X,b,m,n);
}