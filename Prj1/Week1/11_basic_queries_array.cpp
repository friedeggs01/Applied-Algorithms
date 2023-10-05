#include<bits/stdc++.h>
using namespace std;
int find_max_segment(int str, int des, int a[]) {
    int max = a[str];
    for(int i = str; i <= des; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("11.txt", "r", stdin);
    int n, sum = 0, min = 1001, max = -1;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
        if(a[i] < min) {
            min = a[i];
        }
        if(a[i] > max) {
            max = a[i];    
        }
    }
    while(true){
        string temp;
        cin >> temp;
        if(temp == "*") {
            continue;
        }
        if(temp == "***") {
            break;
        }
        if(temp == "find-max") {
            cout << max << endl;
        } else if (temp == "find-min") {
            cout << min << endl;
        } else if (temp == "sum") {
            cout << sum << endl;
        } else if (temp == "find-max-segment") {
            int s, e;
            cin >> s >> e;
            cout << find_max_segment(s-1, e-1, a) << endl;
        }
    }


}