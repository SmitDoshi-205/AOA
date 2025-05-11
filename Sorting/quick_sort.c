#include<stdio.h>

int arr[100]; //array of elements

//merge array
int partition(int l, int h){
    int pivot,i,j,temp;
    pivot = arr[l];
    i = l;
    j = h;
    while(i < j){  
        do{  //finding element larger then pivot
            i++;
        } while(arr[i] <= pivot);
        do{  //finding element smaller than pivot
            j--;
        } while(arr[j] > pivot);
        if(i < j){
            //swap(arr[i], arr[j])
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //swap(arr[l], arr[j]); 
    //place pivot in sorted position
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    
    return j;  //partition position
}

//split arrays
void quick_sort(int l, int h){
    int j;
    if(l < h){
        j = partition(l, h);
        quick_sort(l, j);
        quick_sort(j+1, h);
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
    
    quick_sort(0, n-1);
    
    printf("Sorted Array : ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}