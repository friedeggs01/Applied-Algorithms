// check if this number appear before
#include <iostream>
#include <map>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, num;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if(mp[num] == 1) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
            mp[num] = 1;
        }
    }
    return 0;
}
