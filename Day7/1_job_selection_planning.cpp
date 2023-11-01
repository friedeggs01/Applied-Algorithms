#include<bits/stdc++.h>
using namespace std;

int n;
pair<int, int> p[100001];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    // freopen("1.txt", "r", stdin);
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p, p + n, compare);
    int ans = 0;
    bool used[100001] = {false};

    for(int i=0; i<n; i++) {
        for(int j = p[i].first - 1; j >= 0; j--){
            if(used[j] == false) {
                ans += p[i].second;
                // cout << ans << " " << j << " ";
                used[j] = true;
                break;
            }  
        }
    }
    cout << endl << ans;
}