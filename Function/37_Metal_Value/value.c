#include "value.h"
int gcd(int a,int b){
    while(a%b!=0){
      int r=a%b;
        a=b;b=r;       
    }
  return b;
}
 
int value(int type, int width, int height, int length){
    int fuck,last;
    if(type==79){
        if(width>0 && height>0 && length>0){
          last=gcd(gcd(width,height),length);
            fuck=30*last*last*last*width*height*length;
        }else{
            fuck=-2;
        }
    }else if(type==47){
        if(width>0 && height>0 && length>0){
          last=gcd(gcd(width,height),length);
            fuck=10*last*last*last*width*height*length;
        }else{
            fuck=-2;
        }
    }else if(type==29){
        if(width>0 && height>0 && length>0){
          last=gcd(gcd(width,height),length);
            fuck=4*last*last*last*width*height*length;
        }else{
            fuck=-2;
        }
    }else if(type==82){
        if(width>0 && height>0 && length>0){
          last=gcd(gcd(width,height),length);
            fuck=5*last*last*last*width*height*length;
        }else{
            fuck=-2;
        }
    }else if(type==26){
        if(width>0 && height>0 && length>0){
          last=gcd(gcd(width,height),length);
            fuck=3*last*last*last*width*height*length;
        }else{
            fuck=-2;
        }
    }else if(type==22){
        if(width>0 && height>0 && length>0){
          last=gcd(gcd(width,height),length);
            fuck=9*last*last*last*width*height*length;
        }else{
            fuck=-2;
        }
    }else{
        fuck=-1;
    }
    return fuck;
}