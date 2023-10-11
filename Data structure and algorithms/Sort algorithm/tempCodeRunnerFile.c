#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
// Số nhỏ nhất xếp 1, min tiếp theo xếp vị trí số 2...
void selectionSort(int a[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(a[min] > a[j]) min = j;
        }
        swap(&a[min], &a[i]);
    }
}
// Bắt đầu từ số thứ 2, đổi chỗ nếu nó nhỏ hơn số đứng trước nó
void insertSort(int a[], int n){
    for(int i=1; i<n; i++){
        int last = a[i];
        int j = i; // giá trị j là vị trí chính xác của a[i]
        while(j > 0 && a[j-1] > last){
            a[j] = a[j-1];
            j--;
        }
        a[j] = last;
    }
}
// Duyệt lần lượt từ trái qua phải, đổi chỗ hai phần tử liền kề nhau nếu phần từ đứng trước lại lớn hơn, lặp lại cho khi vẫn có phần từ trước lớn hơn phần từ sau
void bubbleSort(int a[], int n){
    int swapped;
    do {
        swapped = 0;
        for(int i=0; i<n-1; i++){
            if(a[i] > a[i+1]){
                swap(&a[i], &a[i+1]);
                swapped = 1;
            }
        }
    } while (swapped == 1);
    
}
//Trộn hai dãy con đã sắp xếp
void merge(int a[], int L, int M, int R){
    int ta[1001];
    int i = L, j = M+1;
    for(int k=L; k<=R; k++){
        //khi đã duyệt hết phần tử của mảng bắt đầu bằng L, hoặc bắt đầu bằng M+1 thì chỉ cần nhét hết phần tử của mảng còn lại vào trung gian
        if(i>M){
            ta[k] = a[j];
            j++;
        } else if(j>R){
            ta[k] = a[i];
            i++;
        } else {
            if(a[i] < a[j]){
                ta[k] = a[i];
                i++;
            } else {
                ta[k] = a[j];
                j++;
            }
        }
    }
    for(int k=L; k<=R; k++){
        a[k] = ta[k];
    }
}
//Chia để trị
void mergeSort(int a[], int L, int R){
    if(L < R){
        int M = (L+R)/2;
        mergeSort(a, L, M);
        mergeSort(a, M+1, R);
        merge(a, L, M, R);
    }
}

int partition(int a[],int L,int R,int M){
    int pivot = a[M];
    swap(&a[M], &a[R]);
    int storeIndex = L;
    for(int i=L; i<R; i++){
        if(a[i] < pivot){
            swap(&a[storeIndex], &a[i]);
            storeIndex++;
        }
    }
    swap(&a[storeIndex], &a[R]);
    return storeIndex;
    
}
void quickSort(int a[], int L, int R){
    if(L<R){
        int M = (L+R)/2;
        M = partition(a, L, R, M);
        if(L < M){
            quickSort(a, L, M-1);
        } 
        if(M < R){
            quickSort(a, M+1, R);
        }
    }
}
// vun lại đống
void heapify(int a[], int i, int n){
    int L = 2*i + 1;
    int R = 2*i + 2;
    int max = i;
    if(L < n && a[L] > a[i])
        max = L;
    if(R < n && a[R] > a[max])
        max = R;
    if(max != i){ 
        swap(&a[i], &a[max]);
        heapify(a,max,n);
    }
}
void heapSort(int a[], int n){
    for(int i=n/2; i>=0; i--){
        heapify(a, i, n);
    }
    for(int i = n-1; i>=0; i--){
        swap(&a[0], &a[i]);
        heapify(a, 0, i);
    }
}
int main() {
    int a[15] = {3,44,38,5,47,15,36,26,27,2,46,4,19,50,48};
    int n = 15;
    heapSort(a, n);
    printArray(a, n);
}