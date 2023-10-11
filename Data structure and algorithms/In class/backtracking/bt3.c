#include<stdio.h>
int x[1001];
int n = 3;
void printSolution() {
    for(int j=1; j<=n; j++){
        printf("%d", x[j]);
    }
    printf("\n");
}
int check(int v, int i){
    if(v==1 && v==x[i-1] && v==x[i-2]) return 0;
    return 1;
}
void TRY(int i){
    for(int v=0; v<=1; v++){
        if(check(v, i)){
            x[i] = v;
            if(i==n) printSolution();
            else TRY(i+1);
        }
    }
}
int main() {
    TRY(1);
}