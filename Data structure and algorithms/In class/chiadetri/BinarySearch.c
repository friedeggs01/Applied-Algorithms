#include<stdio.h>
int m;
void bSearch(int x[], int start, int finish, int y){
    if(start==finish){
        if(x[start]==y){
            printf("%d", start);
        } else {
            printf("Not found");
        }
    } else {
        m = (start + finish)/2;
        if(x[m]==y) printf("%d", m);
        if(x[m]<y) { 
            return bSearch(x, m+1, finish, y);
        } else {
            return bSearch(x, start, m-1, y);
        }
    }
}
int main() {
    int x[10] = {1,3,4,5,7,9,11,34,56};
    bSearch(x, 0, 8, 5);
}