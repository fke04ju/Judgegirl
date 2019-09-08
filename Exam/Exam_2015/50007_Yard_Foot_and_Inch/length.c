void init(int length[3]) {
    for(int i = 0;i<3;i++){
        length[i] = 0;
    }
    return;
}
void add(int length[3], int i) {
    length[2] += i;
    int flow = 0;
    if(length[2] >= 12){
        flow = length[2]/12;
        length[2] %= 12;
        length[1] += flow;
    }
    if(length[1] >= 3){
        flow = length[1]/3;
        length[1] %= 3;
        length[0]+=flow;
    }
    return;
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    for(int i = 0;i<3;i++){
        lengthc[i] = lengtha[i]+lengthb[i];
    }
    int flow = 0;
    if(lengthc[2] >= 12){
        flow = lengthc[2]/12;
        lengthc[2] %= 12;
        lengthc[1] += flow;
    }
    if(lengthc[1] >= 3){
        flow = lengthc[1]/3;
        lengthc[1] %= 3;
        lengthc[0]+=flow;
    }
    return;
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    if(lengthb[1] > lengtha[1]){
        lengtha[0]--;
        lengtha[1]+=3;
    }
    if(lengthb[2] > lengtha[2]){
        lengtha[1] --;
        lengtha[2]+=12;
    }
    for(int i = 0;i<3;i++){
        lengthc[i] = lengtha[i]-lengthb[i];
    }
    return;
}