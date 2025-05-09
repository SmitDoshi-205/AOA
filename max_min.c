#include<stdio.h>
int arr[100];

void max_min(int i,int j, int *max, int *min){
    int mid, max_left, min_left, max_right, min_right;
    //single element in array
    if(i == j){
        *max = *min = arr[i];
    }
    
    //2 elements in array
    else if(i == j-1){
        if(arr[i] > arr[j]){
            *max = arr[i];
            *min = arr[j];
        }
        else{
            *max = arr[j];
            *min = arr[i];
        }
    }
    
    //'n' elements in array
    else{
        mid = (i+j) / 2;
        
        //left half of array
        max_min(i, mid, &max_left, &min_left);
        
        //right half of array
        max_min(mid+1, j, &max_right, &min_right);
        
        //maximum
        if(max_left < max_right){
            *max = max_right;
        }
        else{
            *max = max_left;
        }
        
        //minimum
        if(min_left > min_right){
            *min = min_right;
        }
        else{
            *min = min_left;
        }
    }
}

void main(){
    int n; //no of elements in array
    int i, max, min;
    printf("Enter the no of elements in array-");
    scanf("%d", &n);
    printf("Enter the array elements-");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    //function call
    max_min(0, n-1, &max, &min);
    
    printf("Maximum = %d", max);
    printf("\nMinimum = %d", min);
}