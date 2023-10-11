//Cho mảng A chứa các phần tử bắt đầu với chỉ số 0: 6, 1, 3, 9, 5, 7
// Hãy in ra các phần tử trong mảng A sau khi vun đống min
#include<stdio.h>

void swap(int* a, int* b){
    int* temp = a;
    a = b;
    b = temp;
}

void min_heap(int arr[], int n, int i){
    int min = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n && arr[left] > arr[min]){
        min = left;
    } else if(right<n && arr[right] > arr[min]){
        min = right;
    }
    if(min!= i){
        swap(&arr[i], &arr[min]);
        min_heap(arr, n, min);
    }
}

void sort_heap(int arr[], int n){
    for(int i = )
    for(int i=)
}

void print(int arr[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr
}