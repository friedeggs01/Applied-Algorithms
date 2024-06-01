int f[100];
int numTrees(int n){
    f[0] = 1;
    f[1] = 1;
    if(n == 0 || n == 1){
         return 1;
    }
    for(int i=1; i<=n; i++){
        f[n] += numTrees(i-1)*numTrees(n-i);
    }
    return f[n];
}