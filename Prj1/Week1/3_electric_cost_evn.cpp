#include<bits/stdc++.h>
using namespace std;

double new_cost(int n){
    if(n<50) {
        return n*1.728;
    } else if(n<100){
        return 50*1.728 + (n-50)*1.786; 
    } else if(n<200){
        return 50*1.728 + 50*1.786 + (n-100)*2.074;
    } else if(n<300) {
        return 50*1.728 + 50*1.786 + 100*2.074 + (n-200)*2.612;
    } else if(n<400) {
        return 50*1.728 + 50*1.786 + 100*2.074 + 100*2.612 + (n-300)*2.919;
    } else {
        return 50*1.728 + 50*1.786 + 100*2.074 + 100*2.612 + 100*2.919 + (n-400)*3.015;
    }
}

double old_cost(int n){
    if(n<100) {
        return n*1.728;
    } else if(n<200){
        return 100*1.728 + (n-100)*2.074; 
    } else if(n<400){
        return 100*1.728 + 100*2.074 + (n-200)*2.612;
    } else if(n<700) {
        return 100*1.728 + 100*2.074 + 200*2.612 + (n-400)*3.111;
    } else {
        return 100*1.728 + 100*2.074 + 200*2.612 + 300*3.111 + (n-700)*3.457;
    }
}

int main() {
    int n, cost = 0;
    cin >> n;
    printf("%.2f",  (old_cost(n) - new_cost(n)) * 1100);
}