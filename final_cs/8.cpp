#include<bits/stdc++.h>
using namespace std;

int n, a[1001], sol[1001];
int min_value = INT_MAX;
int value[3] = {0,0,0};
bool check(int v, int k) {
    return true;
}
void TRY(int k) {
    // cout << "k: "<< k << endl;
    for(int v = 0; v<3; v++) {
        // cout << "v: " << v << endl;
        if (check(v, k)){
            sol[k] = v;
            value[v] += a[k];
            if (k==n-1){
                int values = *max_element(value, value+3);
                if (values < min_value) {
                    min_value = values;
                    // cout << min_value << endl;
                }
            } else {
                TRY(k+1);
            }
            value[v] -= a[k];
        }
    }
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("8.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    TRY(0);
    cout << min_value;
}