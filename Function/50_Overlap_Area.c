#include <stdio.h>
#include <stdlib.h>
 
int two_has_min_in_right(int ar,int br){
    if(br>ar){
        return ar;
    }else{
        return br;
    }
}
 
int two_has_max_in_left(int al,int bl){
    if(bl>al){
        return bl;
    }else{
        return al;
    }
}
 
int two_has_intersect(int al,int ar,int bl,int br){
    if(two_has_max_in_left(al,bl)<two_has_min_in_right(ar,br)){
        return two_has_min_in_right(ar,br)-two_has_max_in_left(al,bl);
    }else{
        return 0;
    }
}
 
int three_has_max_in_left(int al,int bl,int cl){
    int max = al;
    if(max<bl){
        max = bl;
    }
    if(max<cl){
        max = cl;
    }
    return max;
}
 
int three_has_min_in_right(int ar,int br,int cr){
    int min = ar;
    if(min>br){
        min = br;
    }
    if(min>cr){
        min = cr;
    }
    return min;
}
 
int three_has_intersect(int al,int ar,int bl,int br,int cl,int cr){
    if(three_has_max_in_left(al,bl,cl)<three_has_min_in_right(ar,br,cr)){
        return three_has_min_in_right(ar,br,cr)-three_has_max_in_left(al,bl,cl);
    }else{
        return 0;
    }
}
 
int main(){
    int alx,aly,arx,ary,blx,bly,brx,bry,clx,cly,crx,cry;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&alx,&aly,&arx,&ary,&blx,&bly,&brx,&bry,&clx,&cly,&crx,&cry);
    int total = 0;
    int a = (arx-alx)*(ary-aly);
    int b = (brx-blx)*(bry-bly);
    int c = (crx-clx)*(cry-cly);
    //printf("%d %d %d\n",a,b,c);
    total += (a+b+c);
    int a_b = (two_has_intersect(alx,arx,blx,brx))*(two_has_intersect(aly,ary,bly,bry));
    int a_c = (two_has_intersect(alx,arx,clx,crx))*(two_has_intersect(aly,ary,cly,cry));
    int b_c = (two_has_intersect(blx,brx,clx,crx))*(two_has_intersect(bly,bry,cly,cry));
    total -= (a_b+a_c+b_c);
    //printf("%d %d %d\n",a_b,a_c,b_c);
    int a_b_c = (three_has_intersect(alx,arx,blx,brx,clx,crx))*(three_has_intersect(aly,ary,bly,bry,cly,cry));
    total += a_b_c;
    printf("%d\n",total);
}