#include <stdio.h>
#include<stdlib.h>

int f(int e, int d, int v[]){

    if (e==d) {
    return v[d];
    }
        else{
        int m,x,y;
    m=(e+d)/2;
    x= f(e,m,v);

    y= f(m+1, d, v);

        if(x<=y){
             return x;
        }
        else return y;
    }
}

int main (void){

        int v[10], i=0;

    while(i<10){
        scanf("%d", &v[i]);
        i++;
    }
        f(0,9,v);


}
