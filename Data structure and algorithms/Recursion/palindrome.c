#include<stdio.h>
#include<string.h>

int palindrome(char s[], int start, int end){
    if(strlen(s)<=1){
        return 1;
    }
    if((s[start]==s[end]) && palindrome(s, start+1, end-1)){
        return 1;
    }else return 0;
}
int main() {
    char s[1001];
    gets(s);
    if(palindrome(s, 0, strlen(s)-1)){
        printf("Palindrome");
    } else {
        printf("Not palindrome");
    }
}