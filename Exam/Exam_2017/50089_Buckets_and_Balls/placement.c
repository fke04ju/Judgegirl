void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]){
    if(method == 0){
        for(int i = 0;i<M;i++){
            int idx = 0;
            int found = 0;
            while(found == 0 && idx < N){
                if(bucket[idx] >= ball[i]){
                    bucket[idx] -= ball[i];
                    result[i] = idx;
                    found = 1;
                }
                idx++;
            }
            if(found == 0){
                result[i] = -1;
            }
        }
    }else if(method == 1){
        for(int i = 0;i<M;i++){
            int min = 2147483647;
            int min_idx;
            for(int j = 0;j<N;j++){
                if(bucket[j] < min && bucket[j] >= ball[i]){
                    min = bucket[j];
                    min_idx = j;
                }
            }
            if(min == 2147483647){
                result[i] = -1;
            }else{
                result[i] = min_idx;
                bucket[min_idx] -= ball[i];
            }
        }
    }else{
        for(int i = 0;i<M;i++){
            int max = -2147483648;
            int max_idx;
            for(int j = 0;j<N;j++){
                if(bucket[j] >= max && bucket[j] >= ball[i]){
                    max = bucket[j];
                    max_idx = j;
                }
            }
            if(max == -2147483648){
                result[i] = -1;
            }else{
                result[i] = max_idx;
                bucket[max_idx] -= ball[i];
            }
        }
    }
    return;
}