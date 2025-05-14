#include<stdio.h>

int arr[100];
int search; //element to search in array

void binary_search(int l, int h){
    int mid;
    if(l>h){
        printf("Element not found");
    }
    else{
        mid = (l+h)/2;
        if(arr[mid] == search){
            printf("Element found at position %d", mid);
        }
        else if(search < arr[mid]){
            binary_search(l,mid-1);
        }
        else{
            binary_search(mid+1,h);
        }
    }
}

void main(){
    int n,i,j,temp;
    
    printf("Enter the no of elements in array-");
    scanf("%d", &n);
    printf("Enter the array elements-");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    //sort the array
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array elements-");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
    printf("\nEnter the element to search-");
    scanf("%d", &search);
    binary_search(0,n-1);
}