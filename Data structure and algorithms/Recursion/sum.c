#include<stdio.h>
//Đệ quy

// Tính tổng
// int sum(int n){
//     if(n<=1) return 1;
//     int s = sum(n-1);
//     return n + s;
// }

// Tính tổ hợp
// int C(int k, int n){
//     if(k==0 || k==n) return 1;
//     return C(k-1,n-1) + C(k, n-1);
// }

// Tháp Hà Nội
// void move(int n, char A, char B, char C){
//     if(n==1){
//         printf("Move 1 disk from %c to %c\n", A, B);
//     } else {
//         move(n-1,A, C, B);
//         move(1, A, B, C);
//         move(n-1, C, B, A);
//     }
// }

// Đệ quy có nhớ cho tính tổ hợp, gán các phần tử của m[][] = -1
// int m[101][101];
// int Cc(int k, int n) {
//     if(k==0||k==n){
//         m[k][n] = 1;
//     } else {
//         if(m[k][n]<0){
//             m[k][n] = C(k-1, n-1) + C(k, n-1);
//         }
//     }
//     return m[k][n];
// }

// Đệ quy quay lui
// Liệt kê xâu nhị phân
 int x[8];
 int n=4;
// int k=2;
void solution(){
    for(int i=1; i<=n; i++){
        printf("%d", x[i]);
    }
    printf("\n");
}
// void Try(int k){
//     for(int v=0; v<=1; v++){
//             x[k] = v;
//             if(k==n) solution();
//             else Try(k+1);
//     }
// }

// Liệt kê tổ hợp
// int TRY(int i) {
//     for(int v = x[i-1]+1; v <= n-k+i; v++){
//         x[i] = v;
//         if(i == k) 
//             solution();
//         else TRY(i+1);
//     }       
// }

// Liệt kê hoán vị
// int m[101];
// for(int v=1; v<=n; v++){
//         m[v] = 0;
//     }
// void TRY(int i) {
//     for(int v=1; v<=n; v++){
//         if(!m[v]){
//             x[i] = v;
//             m[v] = 1;
//             if(i==n)    
//                 solution();
//             else TRY(i+1);
//             m[v] = 0;
//         }
//     }
// }

//Bài toán xếp hậu
// int check(int v, int k){
//     //Kiểm tra v có gán được cho x[k] không
//     for(int i=1; i<=k-1; i++){
//         if(x[i] == v) return 0;
//         if(x[i]+i == v+k) return 0;
//         if(x[i]-i == v-k) return 0;
//     }
//     return 1;
// }
// void TRY(int k){
//     for(int v=1; v<=n; v++){
//         if(check(v, k)) {
//             x[k] = v;
//             if(k==n) solution();
//             else TRY(k+1);
//          }
//     }
// }
int main() {
    
    TRY(1);
}