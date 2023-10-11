#include<iostream>
#include<math.h>
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
void printArray(int a[], int n){
    if(n == 0){
        cout << "NULL";
    } else {
        cout << a[0] << " ";
        for(int i = 1; i < n; i++){
            if(a[i] != a[i-1]){
                cout << a[i] << " ";
            }
        }
    }
}
bool check(int n){
    int k = (int) sqrt(n);
    return k*k==n;
}
int a[10001], b[10001];
int main() {
    int n, j = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        if(check(a[i])){
            b[j] = a[i];
            j++;
        }
    }
    quickSort(b, 0, j-1);
    printArray(b, j);
}