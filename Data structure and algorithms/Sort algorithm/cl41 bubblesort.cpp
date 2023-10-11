#include<iostream>
using namespace std;

void Bubblesort(int a[], int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, a[10001];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Bubblesort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}