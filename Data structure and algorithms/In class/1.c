//Tìm dãy con lớn nhất
#include<stdio.h>
#include<limits.h>
//Duyệt toàn bộ
int maxSum1(int A[], int n){
    int maxSum = -INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<j; k++){
                sum+=A[k];
            }
            if(sum>maxSum){
                maxSum = sum;
            }
        }
    }
    return maxSum;
}
//Duyệt toàn bộ có cải tiến
int maxSum2(int A[], int n){
    int maxSum= -INT_MAX;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum+=A[j];
        if(sum>maxSum){
            maxSum = sum;
        }
        }
    }
    return maxSum;
}
//Dynamic programming
int maxSum3(int A[], int n){
    int smax = A[1];
    int ei = A[1];
    int imax = 1;
    int u, v;
    for(int i=2; i<n; i++){
        u = ei + A[i];
        v = A[i];
        if(u>v){
            ei = u;
        } else {
            ei = v;
        }
        if(ei>smax){
            smax = ei;
            imax = i;
        }
    }
    return smax;
}
int main() {
    int A[] = {-2, 11, -4, 13, -5, 2};
    printf("%d", maxSum3(A, 6));
}