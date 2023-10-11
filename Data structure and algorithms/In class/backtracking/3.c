/*Cho sẵn các dấu ngoặc tròn đóng mở, điền dấu ngoặc đóng hoặc mở thích hợp vào vị trí dấu chấm hỏi*/
#include<stdio.h>
void inra(char A[], int size){
    for(int i=0; i<size; i++){
        print("%c ", A[i]);
    }
}
void kiemtra(char A[], int size){
    int c=0;
    for(int i=0; i<size; i++){
        if(A[i]=='('){
            c++;
        } else {
            c--;
        }
        if(c<0) return 0;
    }
    if(c==0) return 0;
}
void try(int k, char A[], n){
    for(int i=0; i<size; i++){
        if()
    }
}
int main(){
    char A[];

}