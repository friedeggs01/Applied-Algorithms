#include<stdio.h>

int stack_arr[];
int count = 0;

void push(int x){
    stack_arr[count] = x;
    count++;
}
int pop() {
    int res = stack_arr[count];
    count--;
    return res;
}
int main() {
    push(2);
    push(3);
    push(5);
    push(10);
    push(11);
    push(12);
    count--;
    while(count>=0){
        printf("%d ", pop());
    }
    return 0;
}