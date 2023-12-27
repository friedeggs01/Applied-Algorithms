#include<bits/stdc++.h>
using namespace std;

int n, arr[100001], m, after_max[100001], bef_max[100001];

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("5.txt", "r", stdin);
    cin >> n;
    cin >> arr[0];
    bef_max[0] = arr[0];
    after_max[0] = arr[0];
    for(int i=1; i<n; i++) {
        cin >> arr[i];
        bef_max[i] = max(bef_max[i-1], arr[i]);
    }
    while(m--){
        string t;
        int a, b;
        cin >> t;
        if(t == "get-max"){
            cin >> a >> b;
            int ans = 0;
            for(int i=a; i<=b; i++){
                ans = max(ans, arr[i]);
            }
            cout << ans;
        } else {
            cin >> a >> b;
            int i = a, v = b;
            arr[i] = v;
        }
    }
}