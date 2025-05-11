#include<stdio.h>

int arr[100]; //array of elements
int key = 0; //key element to be swapped recursively

void insertion_sort(int n){
    int i,j;
    for(j=1; j<n; j++){
        key = arr[j];
        i = j-1;
        while(i>=0 && arr[i] > key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

void main(){
    int i,n;
    printf("Enter the no of elements in array : ");
    scanf("%d", &n);
    
    printf("Enter the elements of array : ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    insertion_sort(n);
    
    printf("Sorted Array : ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}