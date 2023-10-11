#include<bits/stdc++.h>
using namespace std;

int water_jug(int a, int b, int c) {
    int from = a;
    int to = 0;
    int step = 1;
    while(from != c && to != c) {
        // cout << from << "  " << to << endl;
        // find the maximum amount that can be poured
        int temp = min(from, b-to);

        // pour "temp" from "from" to "to"
        to += temp;
        from -= temp;
        step++;

        // ending condition
        if(from == c || to == c)
            break;
        
        // if from is "0" -> refill this
        if(from == 0) {
            from = a;
            step++;
        }

        // if to is "full" -> remove this
        if(to == b)
        {
            to = 0;
            step++;
        }
    } 
    return step;   
}
int minSteps(int m, int n, int d) {
    if (m>n) {
        swap(m, n);
    }
    return min(water_jug(n,m,d), water_jug(m,n,d));
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << minSteps(a, b, c);
}