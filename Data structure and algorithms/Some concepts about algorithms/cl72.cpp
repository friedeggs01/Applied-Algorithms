#include<iostream>
using namespace std;

void quickSort(int a[], int l, int r){
    int p = a[(l+r)/2];
    int i = l, j = r;
    while(i < j){
        while(a[i] < p){
            i++;
        } 
        while(a[j] > p){
            j--;
        }
        if(i <= j){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if(i < r){
        quickSort(a, i, r);
    }
    if(l < j){
        quickSort(a, l, j);
    }
}
int solve(int a[], int n){
    int chong = 1;
    quickSort(a, 0, n-1);
    int stiffness = a[n-1];
    for(int i = n-2; i >= 0; i--){
        chong++;
        stiffness--;
        if(stiffness > a[i]){
            stiffness = a[i];
        }
        if(stiffness == 0){
            return chong;
        }
    }
    return n;
}
int main() {
    int n, a[10001];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << solve(a, n);
}