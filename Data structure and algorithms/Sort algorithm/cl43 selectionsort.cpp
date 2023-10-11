#include<iostream>
using namespace std;

void Selectionsort(int a[], int n){
    int indexMin;
    for(int i = 0; i < n; i++){
        indexMin = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[indexMin]){
                indexMin = j;
            }
        }
        if(i != indexMin){
            int temp = a[i];
            a[i] = a[indexMin];
            a[indexMin] = temp;
        }
    }
}

int main() {
    int n, a[10001];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Selectionsort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}