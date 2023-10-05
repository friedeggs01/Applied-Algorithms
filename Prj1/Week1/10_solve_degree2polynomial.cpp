#include<bits/stdc++.h>
using namespace std;

int main() {
    float a, b, c, delta;
    cin >> a >> b >> c;
    delta = b*b - 4*a*c;
    if(delta <0) cout << "NO SOLUTION" << endl;
    else if (delta == 0) {
        printf("%.2f", -b/(2*a));
    } else {
        printf("%.2f ", (-b - sqrt(delta))/ (2*a));
        printf("%.2f ", (-b + sqrt(delta))/ (2*a));
    }
}