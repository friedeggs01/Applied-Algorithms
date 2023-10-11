// Bài toán Sodoku
#include<stdio.h>
#include<stdbool.h>
int x[9][9];
void printSolution(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }
}
bool check(int v, int r, int c){
    // test column
    for(int i=0; i<r; i++){
        if(x[i][c]==v) return false;
    }
    // test row
    for(int i=0; i<c; i++){
        if(x[r][i]==v) return false;
    }
    // index in small matrix 3x3
    int I=r/3;
    int J=c/3;
    int i=r-3*I;
    int j=c-3*J;
    for(int i1=0; i1<i; i1++){
        for(int j1=0; j1<=2; j1++){
            if(x[3*I+i1][3*J+j1]==v) return false;
        }
    }
    for(int j1=0; j1<j; j1++){
        if(x[3*I+i][3*J+j1]==v) return false;
    }
    return true;
}
void Try(int r, int c){
    for(int v=1; v<=9; v++){
        if(check(v,r,c)){
            x[r][c]=v;
            if(r==8&&c==8){
            printSolution();
            printf("\n------------------\n");
            break;
            } else { 
            if(c==8) Try(r+1,0);
            else Try(r,c+1);
            }
        }
    }  
}
int main() {
    Try(0,0);
}