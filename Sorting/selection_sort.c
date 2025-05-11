#include<stdio.h>

int arr[100]; //array of elements

void selection_sort(int n){
    int i,j,k,temp;
    for(i=0; i<n; i++){
        j = i;
        for(k=i+1; k<n; k++){
            if(arr[k] < arr[j]){
                j=k;
            }
        }
        //swap the elements
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
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
    
    selection_sort(n);
    
    printf("Sorted Array : ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}