#include<iostream>
using namespace std;

void shellSort(int a[], int n){
    int gap, i, j, temp;
    for(gap = n/2; gap > 0; gap /= 2) {
        for(i = gap; i < n; i++){
            temp = a[i];
            for(j = i; j >= gap && a[j-gap] > temp; j-= gap){
                a[j] = a[j -gap];
            }
            a[j] = temp;
        }
    }
}

int a[10001];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    shellSort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}