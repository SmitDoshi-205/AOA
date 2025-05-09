#include<stdio.h>
#include<string.h> //to calculate length of text and pattern

char text[50];
char pattern[50];

//finding the longest-prefix-suffix table
int computePrefix(char pattern[], int m, int pi[]){
    int temp_lps[50];
    temp_lps[0] = 0;
    int k = 0;
    int j;
    for(j=1; j<m; j++){
        while(k>0 && pattern[k] != pattern[j]){
            k = temp_lps[k-1];
        }
        if(pattern[k] == pattern[j]){
            k += 1;
        }
        temp_lps[j] = k;
    }
    for(j = 0; j < m; j++){
        pi[j] = temp_lps[j];
    }
    
    printf("LPS Table:\n");
    for(j = 0; j < m; j++){
        printf("%c : %d\n", pattern[j], pi[j]);
    }
    
    return 0;
}

//knuth-morris-pratt
void kmp(char text[], char pattern[], int n, int m){
    int pi[50];
    computePrefix(pattern, m, pi);
    int j = 0;
    int i;
    for(i=0; i<n; i++){
        while(j > 0 && pattern[j] != text[i]){
            j = pi[j-1];
        }
        if(pattern[j] == text[i]){
            j += 1;
        }
    }
    
    if(j == m){
        printf("\nPattern occurs in \"%s\" with shift %d", text, (i - m+1));
        j = pi[j-1];
    }
}

int main(){
    int n;
    int m;
    printf("Enter text:");
    scanf("%s", text);
    printf("Enter pattern:");
    scanf("%s", pattern);
    n = strlen(text); //length of text
    m = strlen(pattern); //length of pattern
    
    kmp(text, pattern, n, m);
}