int stationDistance(int R_distance[],int G_distance[],int B_distance[],int G_origin,
    int G_destination,int startStation[],int endStation[]){
    int r_dis = 0;
    int g_dis = 0;
    int b_dis = 0;
    while(R_distance[r_dis] != 0){
        r_dis++;
    }
    while(G_distance[g_dis] != 0){
        g_dis++;
    }
    while(B_distance[b_dis] != 0){
        b_dis++;
    }
    int sum = 0;
    if(startStation[0] == 0){
        if(endStation[0] == 2){
            if(endStation[1] > G_destination){
                for(int i = G_destination;i<endStation[1];i++){
                    sum += B_distance[i-1];
                }
            }else{
                for(int i = endStation[1];i<G_destination;i++){
                    sum += B_distance[i-1];
                }
            }
            for(int i = 1;i<=g_dis;i++){
                sum += G_distance[i-1];
            }
            if(startStation[1] > G_origin){
                for(int i = G_origin;i<startStation[1];i++){
                    sum += R_distance[i-1];
                }
            }else{
                for(int i = startStation[1];i<G_origin;i++){
                    sum += R_distance[i-1];
                }
            }
        }else if(endStation[0] == 1){
            for(int i = 1;i<endStation[1];i++){
                sum += G_distance[i-1];
            }
            if(startStation[1] > G_origin){
                for(int i = G_origin;i<startStation[1];i++){
                    sum += R_distance[i-1];
                }
            }else{
                for(int i = startStation[1];i<G_origin;i++){
                    sum += R_distance[i-1];
                }
            }
        }else{
            if(startStation[1] > endStation[1]){
                for(int i = endStation[1];i<startStation[1];i++){
                    sum += R_distance[i-1];
                }
            }else{
                for(int i = startStation[1];i<endStation[1];i++){
                    sum += R_distance[i-1];
                }
            }
        }
    }else if(startStation[0] == 1){
        if(endStation[0] == 1){
            if(startStation[1] > endStation[1]){
                for(int i = endStation[1];i<startStation[1];i++){
                    sum += G_distance[i-1];
                }
            }else{
                for(int i = startStation[1];i<endStation[1];i++){
                    sum += G_distance[i-1];
                }
            }
        }else if(endStation[0] == 2){
            for(int i = startStation[1];i<=g_dis;i++){
                sum += G_distance[i-1];
            }
            if(endStation[1] > G_destination){
                for(int i = G_destination;i<endStation[1];i++){
                    sum += B_distance[i-1];
                }
            }else{
                for(int i = endStation[1];i<G_destination;i++){
                    sum += B_distance[i-1];
                }
            }
        }else{
            if(endStation[1] > G_origin){
                for(int i = G_origin;i<endStation[1];i++){
                    sum += R_distance[i-1];
                }
            }else{
                for(int i = endStation[1];i<G_origin;i++){
                    sum += R_distance[i-1];
                }
            }
            for(int i = 1;i<startStation[1];i++){
                sum += G_distance[i-1];
            }
        }
    }else{
        if(endStation[0] == 0){
            if(endStation[1] > G_origin){
                for(int i = G_origin;i<endStation[1];i++){
                    sum += R_distance[i-1];
                }
            }else{
                for(int i = endStation[1];i<G_origin;i++){
                    sum += R_distance[i-1];
                }
            }
            for(int i = 1;i<=g_dis;i++){
                sum += G_distance[i-1];
            }
            if(startStation[1] > G_destination){
                for(int i = G_destination;i<startStation[1];i++){
                    sum += B_distance[i-1];
                }
            }else{
                for(int i = startStation[1];i<G_destination;i++){
                    sum += B_distance[i-1];
                }
            }
        }else if(endStation[0] == 1){
            for(int i = endStation[1];i<=g_dis;i++){
                sum += G_distance[i-1];
            }
            if(startStation[1] > G_destination){
                for(int i = G_destination;i<startStation[1];i++){
                    sum += B_distance[i-1];
                }
            }else{
                for(int i = startStation[1];i<G_destination;i++){
                    sum += B_distance[i-1];
                }
            }
        }else{
            if(startStation[1] > endStation[1]){
                for(int i = endStation[1];i<startStation[1];i++){
                    sum += B_distance[i-1];
                }
            }else{
                for(int i = startStation[1];i<endStation[1];i++){
                    sum += B_distance[i-1];
                }
            }
        }
    }
    return sum;
}