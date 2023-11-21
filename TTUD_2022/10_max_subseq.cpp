#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000001];

int max_subseq(){
    int ans = a[0];
    int max_sum_have_ai = a[0];
    for(int i=1;i<n;i++){
        int temp = max_sum_have_ai + a[i];
        if(temp < a[i]){
            max_sum_have_ai = a[i];
        } else {
            max_sum_have_ai = temp;
        }
        if(ans < max_sum_have_ai){
            ans = max_sum_have_ai;
        }
        // cout << i << " " << ans << endl;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << max_subseq();
}