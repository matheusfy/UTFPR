#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main (
){
    int y=0, n=10;
    float media,x,i=0;
    char resp;

    for (y=0; y<n ;y++ ){
        scanf("%d", &x);
        i=i+x;

}

    media = i/y;
    printf(" %.0f", media);
}
