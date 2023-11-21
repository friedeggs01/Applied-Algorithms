#include<bits/stdc++.h>
using namespace std;

int profit[31];
int weight[31];
int W; 
int n;
int K[1000001];
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
    cin >> n >> W;
    for(int i=0; i<n; i++) {
        cin >> weight[i] >> profit[i];
    }
    cout << knapSack();
    return 0;
}