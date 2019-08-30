int max(int *iptr[], int n){
    int m=*iptr[0];
    for(int i=0;i<n;i++){
        if(*iptr[i]>=m){
            m=*iptr[i];
        }
    }
    return m;
}