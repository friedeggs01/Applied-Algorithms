#include<stdio.h>
void printSolution() {
    for(int i=1; i<=k; i++){
        printf("%d ",x[i]);
    }
    printf("\n");
}
void TRY(int i){
    for(int j=x[i-1]; j<=((n-t[i-1])/2); j++){
        x[i]=j;
        t[i] = t[i-1] + j;
        TRY(i+1);
    }
    
}
int main() {
    TRY(1);
}