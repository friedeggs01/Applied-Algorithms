#include<bits/stdc++.h>
using namespace std;
int table[9][9];
int count_1 = 0;
bool check(int v, int r, int c){
    // test column
    for(int i=0; i<r; i++){
        if(table[i][c]==v) return false;
    }
    // test row
    for(int i=0; i<c; i++){
        if(table[r][i]==v) return false;
    }
    // index in small matrix 3x3
    int I=r/3;
    int J=c/3;
    int i=r-3*I;
    int j=c-3*J;
    for(int i1=0; i1<i; i1++){
        for(int j1=0; j1<=2; j1++){
            if(table[3*I+i1][3*J+j1]==v) return false;
        }
    }
    for(int j1=0; j1<j; j1++){
        if(table[3*I+i][3*J+j1]==v) return false;
    }
    return true;
}
void sudoku(int row, int col) {
    for(int v = 1; v < 10; v++) {
        if(check(v, row, col)) {
            table[row][col] = v;
            if(row==8 && col==8) {
                for(int i=0; i<9; i++) {
                    for(int j=0; j<9; j++) {
                        cout << table[i][j] << " ";
                    }
                    cout<<endl;
                }
                count_1++;
            } else {
                if (col<8) {
                    sudoku(row, col+1);
                } else {
                    sudoku(row+1, col);
                }      
            }
        }
    }
}

int main() {
    freopen("6.txt","r", stdin);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> table[i][j];
        }
    }
    sudoku(0, 0);
    printf("%d", count_1);
}