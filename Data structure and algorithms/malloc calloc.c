#include<stdio.h>
#include<stdlib.h>

int main() {
    int i, n;
    printf("\nNhập số lượng phần tử của mảng:");
    scanf("%d", &n);
    int *pointer = (int*)malloc(n*sizeof(int));
    if(pointer == NULL){
        printf("\nCấp phát bộ nhớ không thành công");
        return 0;
    }
    printf("\nNhập các số:");
    for(int i=0; i<n; i++){
        scanf("%d", &pointer[i]);
        printf("%d\n", pointer[i]);
    }

}