#include<bits/stdc++.h>
using namespace std;

int profit[] = { 220, 100, 120 }; 
int weight[] = { 1000, 2000, 3000 }; 
int W = 5000; 
int n = 3;
vector<int> K(W+1);
int knapSack(){
    int i, w;
    for (i = 0; i < n; i++) { 
        for (w = W; w >= 0; w--) { 
            if(weight[i] <= w){
                K[w] = max(K[w], K[w - weight[i]] + profit[i]);
            }
        } 
    } 
    return K[W];  
}

int main() {
    ios_base::sync_with_stdio();
    cin.tie(); cout.tie();
    cout << knapSack();
    return 0;
}