#include<bits/stdc++.h>
using namespace std;

int matrix[9][9];
bool markR[9][10];
bool markC[9][10];
bool markS[3][3][10];
int count_ = 0;

bool check(int row, int col, int v) {
    return markR[row][v] == false && markC[col][v] == false && markS[row/3][col/3][v] == false;
}

void TRY(int row, int col) {
    // if this position is assigned value before -> just check
    if(matrix[row][col] > 0) {
        if(row==8 && col==8){
            count_++;
        } else {
            if(col==8) TRY(row+1, 0);
            else TRY(row, col+1);
        }
        return;
    }
    for(int v = 1; v <= 9; v++) {
        if(check(row, col, v)) {
            matrix[row][col] = v;
            markR[row][v] = true;
            markC[col][v] = true;
            markS[row/3][col/3][v] = true;
            if(row == 8 && col == 8) {
                count_++;
            } else {
                if(col == 8) {
                    TRY(row+1, 0);
                } else {
                    TRY(row, col+1);
                }
            }
            matrix[row][col] = 0;
            markR[row][v] = false;
            markC[col][v] = false;
            markS[row/3][col/3][v] = false;
        }
    }
}

int main () {
    for(int i=1; i<=9; i++) {
        for(int j=0; j<9; j++) {
            markR[j][i] = false;
            markC[j][i] = false;
        }
        for(int k=0; k<3; k++) {
            for(int j=0; j<3; j++) {
                markS[k][j][i] = false;
            }
        }
    }
    // freopen("5.txt", "r", stdin);
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> matrix[i][j];
            if(matrix[i][j] > 0) {
                markR[i][matrix[i][j]] = true;
                markC[j][matrix[i][j]] = true;
                markS[i/3][j/3][matrix[i][j]] = true;
            }
        }
    }
    TRY(0, 0);
    cout << count_;
}