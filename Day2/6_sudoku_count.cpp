#include<bits/stdc++.h>
using namespace std;
int table[9][9];
bool markR[9][10];
bool markC[9][10];
bool markS[3][3][10];
int counttt=0;
bool check(int v, int row, int col) {
    return markR[row][v] == false && markC[col][v]== false && markS[row/3][col/3][v]==false;
}

void sudoku(int row, int col) {
    if(table[row][col] > 0) {
        if(row==8 && col==8){
            counttt++;
        } else {
            if(col==8) sudoku(row+1, 0);
            else sudoku(row, col+1);
        }
        return;
    }
    for(int v = 1; v < 10; v++) {
        if(check(v, row, col)) {
            // cout << row << col << v << endl;
            table[row][col] = v;
            markR[row][v] = true;
            markC[col][v] = true;
            markS[row/3][col/3][v] = true;
            if(row==8 & col==8) {
                // for(int i=0; i<9; i++) {
                //     for(int j=0; j<9; j++) {
                //         cout << table[i][j] << " ";
                //     }
                //     cout<<endl;
                // }
                counttt++;
            } else {
                if (col<8) {
                    sudoku(row, col+1);
                } else {
                    sudoku(row+1, 0);
                }      
            }
            markR[row][v] = false;
            markC[col][v] = false;
            markS[row/3][col/3][v] = false;
            table[row][col] = 0;
        }
    }
}

int main() {
    for(int i=1; i<=9; i++) {
        for(int r=0; r < 9; r++) {
            markR[r][i] = false;
            markC[r][i] = false;
        }
        for(int k=0;k<3;k++)  {
            for(int j=0;j<3;j++){
                markS[k][j][i] = false;
            }
        }
    }
    // freopen("6.txt","r", stdin);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> table[i][j];
            if (table[i][j] > 0 ) {
                markR[i][table[i][j]] = true;
                markC[j][table[i][j]] = true;
                markS[i/3][j/3][table[i][j]] = true;
            }
        }
    }
    sudoku(0, 0);
    cout << counttt;
}