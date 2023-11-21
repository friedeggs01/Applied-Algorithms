#include<bits/stdc++.h>
using namespace std;

int n, k, a[10001];
int mid;

bool isFeasible() {
    int cnt = 1;
    int sum = 0;
    for(int i=0; i<n; i++){
        if(a[i]>mid) return false;
        sum += a[i];
        if(sum>mid){ // constraint sum <= mid, if not, put a[i] into new sub_seq
            cnt++;
            sum = a[i];
        }
    }
    
    if(cnt<=k) return true;
    return false;
}

int split_max() {
    int left = *max_element(a, a+n); // mid always bigger than the maximum because if split n into n subarray
    int right = 0; // mid always smaller than right when split n into 1 subarray
    int ans = 0;
    for (int i=0; i<n; ++i) {
        right += a[i];
    }
    while(left<right){
        mid = (left+right)/2;
        if(isFeasible()){
            ans = mid;
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << split_max();
}