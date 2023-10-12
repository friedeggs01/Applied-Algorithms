#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int k;
    string temp;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> results;
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    while (cin >> temp) {
        if (temp == "#") {
            break;
        } else if (temp == "POP") {
            results.push_back(pq.top());
            pq.pop();
        } else {
            cin >> k;
            pq.push(k);
        }
    }

    for (int res: results) {
        cout << res << '\n';
    }
    return 0;
}
