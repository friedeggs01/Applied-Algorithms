#include<iostream>
using namespace std;
int main()  {
    int n, a[10001], l[10001];
    int indexMax = 0;
    l[0] = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i < n; i++){
        if(a[i] >= a[i-1]){
            l[i] = l[i-1] + 1;
        } else {
            l[i] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        if(l[indexMax] < l[i]){
            indexMax = i;
        }
    }
    for(int i = indexMax - l[indexMax] + 1; i < indexMax; i++){
        cout << a[i] << " ";
    }
}