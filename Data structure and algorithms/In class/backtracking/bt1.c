#include<stdio.h>
int m[1001];
int x[1001];
int k=3, n=6;
void printSolution(){
    for(int j=1; j<=k; j++){
        printf("%d", x[j]);
    }
    printf("\n");
}
int check(int v, int i){
    //Kiểm tra xem v có thể gán được cho x[i] không
    if(v==x[i-1]-1||v==x[i-1] + 1||m[v]==1 || v<x[i-1]) return 0;
    return 1;
}
void TRY(int i){
    for(int v=i; v<=n; v++){
        if(check(v, i)){
            m[v] = 1;
            x[i] = v;
            if(i==k) printSolution();
            else TRY(i+1);
            m[v] = 0;
        }
    }
}
int main() {
    for(int j=1; j<=n; j++){
        m[j] = 0;
    }
    x[0] = -1;
    TRY(1);
}