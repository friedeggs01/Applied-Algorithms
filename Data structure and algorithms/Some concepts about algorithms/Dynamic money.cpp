#include<iostream>

using namespace std;

int a[100001];
int l[100001];
int moneyChange(int a[], int n, int x)
{
    for (int i = 0; i <= x; i++)
        l[i] = 9999999;
    for (int i = 0; i < n; i++)
        l[a[i]] = 1;
	for (int i = 1; i <= x; i++)
	    for (int j = 0; j < n; j++){
                if (i >= a[j] && (l[i] > l[i-a[j]] + 1)){ 
                    l[i] = l[i-a[j]] + 1;
                }
	        }
	return l[x];
}
int main(){
	int n, x;
    cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cin >> x;
	cout << moneyChange(a, n, x);
}