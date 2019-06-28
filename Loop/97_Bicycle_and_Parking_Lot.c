#include<stdio.h>
int main()
{
    int np;
    scanf("%d",&np);
    int i;
    int px[10],py[10],pc[10],count[10]={0};
    for(i=0;i<np;i++)
    {
        scanf("%d%d%d",&px[i],&py[i],&pc[i]);
    }
    int nb;
    scanf("%d",&nb);
    int d=1000000,dx=-10000,dy=-10000,dis,nptr;
    while(nb--)
    {
        int bx,by;
        scanf("%d%d",&bx,&by);
        for(i=0;i<np;i++)
        {
            if(count[i]<pc[i])
            {
                dis=abs(bx-px[i])+abs(by-py[i]);
                if(dis<d)
                {
                    nptr=i;
                    dx=px[i];
                    dy=py[i];
                    d=dis;
                }else
                if(dis==d)
                {
                    if(dx>px[i])
                    {
                        nptr=i;
                        dx=px[i];
                        dy=py[i];
                    }else
                        if(dx==px[i])
                        {
                            if(dy>py[i])
                            {
                                nptr=i;
                                dx=px[i];
                                dy=py[i];
                            }
                        }
                }       
            }
        }
        count[nptr]++;
        d=1000000;
    }
    for(i=0;i<np;i++)
        printf("%d\n",count[i]);
    return 0;
}
