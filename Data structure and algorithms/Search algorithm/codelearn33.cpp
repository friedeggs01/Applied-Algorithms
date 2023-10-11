#include<iostream>
using namespace std;

int main() {
    int n,a[10001],min,max, cmax, cmin;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        min = a[0];
        max = a[0];
        if(a[i] >= max){
            max = a[i];
            cmax = i;
        }
    }
    for(int i = n-1; i >=0; i--){
        if(a[i] <= min){
            min = a[i];
            cmin = i;
        }
    }
    int temp = a[cmin];
    a[cmin] = a[cmax];
    a[cmax] = temp;
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    } 
}