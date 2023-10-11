#include<iostream>
using namespace std;

void Insertionsort(int a[], int n){
    int temp;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int n, a[10001];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Insertionsort(a, n);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}