#include <stdio.h>

int main(){
    int a,b,c,d,e,x;
    scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
    int tmpa = -1,tmpb = -1,tmpc = -1;
    int tmpxa = -1,tmpxb = -1,tmpxc = -1;
    int found = 0;
    while(scanf("%d",&x)!=EOF && found == 0){
        int Cs = x;
        int cnt = 0;
        while(Cs < d || Cs > e){
            cnt++;
            Cs = (a*Cs + b) % c;
        }
        if(tmpa == -1){
            tmpa = cnt;
            tmpxa = x;
        }else if(tmpb == -1){
            tmpb = cnt;
            tmpxb = x;
        }else if(tmpc == -1){
            tmpc = cnt;
            tmpxc = x;
            int ta,tb,tc;
            ta = tmpa;
            tb = tmpb;
            tc = tmpc;
            if(ta < tb){
                if(ta < tc){
                    if(tb < tc){
                        if(ta + 1 == tb && tb + 1 == tc){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }else{
                        if(ta+1 == tc && tc+1 == tb){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }
                }else{
                    if(tc+1 == ta && ta+1 == tb){
                        printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                        found = 1;
                    }
                }
            }else{
                if(ta < tc){
                    if(tb+1 == ta && ta+1 == tc){
                        printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                        found = 1;
                    }
                }else{
                    if(tb > tc){
                        if(tc+1 == tb && tb+1 == ta){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }else{
                        if(tb+1 == tc && tc+1 == ta){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }
                }
            }
        }else{
            tmpa = tmpb;
            tmpb = tmpc;
            tmpc = cnt;
            tmpxa = tmpxb;
            tmpxb = tmpxc;
            tmpxc = x;
            int ta,tb,tc;
            ta = tmpa;
            tb = tmpb;
            tc = tmpc;
            if(ta < tb){
                if(ta < tc){
                    if(tb < tc){
                        if(ta + 1 == tb && tb + 1 == tc){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }else{
                        if(ta+1 == tc && tc+1 == tb){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }
                }else{
                    if(tc+1 == ta && ta+1 == tb){
                        printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                        found = 1;
                    }
                }
            }else{
                if(ta < tc){
                    if(tb+1 == ta && ta+1 == tc){
                        printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                        found = 1;
                    }
                }else{
                    if(tb > tc){
                        if(tc+1 == tb && tb+1 == ta){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }else{
                        if(tb+1 == tc && tc+1 == ta){
                            printf("%d %d %d\n",tmpxa,tmpxb,tmpxc);
                            found = 1;
                        }
                    }
                }
            }
        }
    }
    if(found == 0){
        printf("Not found\n");
    }
}