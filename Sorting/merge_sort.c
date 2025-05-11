#include<stdio.h>

int arr[100]; //array of elements

//merge array
void merge(int l, int m, int h){
    int b[100], c[100]; //temporary arrays
    int i,j,k;
    
    //b stores the left sub-array
    for(i=l; i<=m; i++){
        b[i] = arr[i];
    }
    //c stores the right sub-array
    for(j=m+1; j<=h; j++){
        c[j] = arr[j];
    }
    
    i = l, j = m+1, k = l;
    
    //merge
    while(i<=m && j<=h){
        if(b[i] < c[j]){
            arr[k++] = b[i++];
        }
        else{
            arr[k++] = c[j++];
        }
    }
    
    //remaining elements
    for(; i<=m; i++){
        arr[k++] = b[i];
    }
    for(; j<=h; j++){
        arr[k++] = c[j];
    }
}

//split arrays
void merge_sort(int l, int h){
    int mid;
    if(l < h){
        mid = (l+h)/2;
        merge_sort(l, mid);
        merge_sort(mid+1, h);
        merge(l, mid, h);
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
    
    merge_sort(0, n-1);
    
    printf("Sorted Array : ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}