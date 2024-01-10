    for(int k = 1; k <= K; k++){
        int s = y[k];
        printf("route[%d]: 0 ",k);
        for(int v = s; v != 0; v = x[v]){
            printf("%d ",v);
        }
        printf("0\n");
    }
    printf("---------------------------\n");