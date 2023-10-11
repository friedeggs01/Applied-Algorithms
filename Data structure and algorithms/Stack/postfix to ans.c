#include<stdio.h>
int n, lll=0;
char stack[10001];
void push(int val){
        stack[lll] = val;
        lll++;
}
void pull(){
        return stack[lll--];
}
int main() {
    scanf("%d", &n);
    char val;
    int x;
    for(int i=0; i<n; i++){
        scanf("%d", &val);
        if(val>='0' && val<='9'){
        push(val);
        } else {
            int a= pull();
            int b= pull();
            if(val == '+'){
                a+=b;
            } else if(val == '-'){
                a-=b;
            } else if(val == '*'){
                a*=b;
            } else {
                a/=b;
            }
            push(a);
            x=a;
        }
    
    }
    printf("%d", x);
}