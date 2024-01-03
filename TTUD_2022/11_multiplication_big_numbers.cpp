#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    freopen("11.txt", "r", stdin);
    long a, b;
    cin >> a >> b;
    string ar = to_string(a), br = to_string(b);

    reverse(ar.begin(), ar.end());
    reverse(br.begin(), br.end());
    int ans_size = ar.size() + br.size();
    int ans[ans_size] = {0};
    for(int i=0; i<ar.size(); i++) {
        for(int j=0; j<br.size(); j++) {
            int p = (int)(ar[i]) - '0';
            int q = (int)(br[j]) - '0';
            ans[i+j] += ar[i]*br[j];
            ans[i+j+1] = ans[i+j+1] + ans[i+j]/10;
            ans[i+j]%=10;
        }
    }
    string s="";

    for(auto i=0;i<ans_size; ++i)
        s += to_string(ans[i]); 

    reverse(s.begin(), s.end());
    cout << s;
}