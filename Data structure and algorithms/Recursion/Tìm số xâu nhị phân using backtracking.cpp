#include<iostream>
using namespace std;
int n = 3, a[1001];
void Try(int k){
    for(int i=0; i<=1; i++){
        a[k] = i;
        if(k==n){
            for(int i=1; i<=n; i++){
                cout << a[i];
            }
            cout << endl;
        } else {
            Try(k+1);
        }
    }
}

int main() {
    Try(1);
}