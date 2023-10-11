#include<stdio.h>
int maxSeq(int a[], int l, int r){
    if(l==r) return a[l];
    int max;
    int mid = (l+r)/2;
    int mL = maxSeq(a, l, mid);
    int mR = maxSeq(a, mid+1, r);
    int mLR = maxLeft(a, l, mid) + maxRight(a, mid+1, r);
    max = mL;
    if(max < mR) max = mR;
    if(max < mLR) max = mLR;
    return max;
}
int maxLeft(int a[], int l, int r){
    int max = -1e9;
    int s=0;
    for(int i=r; i>=l; i--){
        s+=a[i];
        if(s>max) max=s;
    }
    return max;
}
int maxRight(int a[], int l, int r){
    int max = -1e9;
    int s=0;
    for(int i=l; i<=r; i++){
        s += a[i];
        if(s>max) max = s;
    }
    return max;
}
int main() {
    int n=10;
    int a[10] = {3, 4 ,7, 1, -1, 5, 9, 7, -5, 4};
    int rs = maxSeq(a, 0, n-1);
    printf("result = %d", rs);
}