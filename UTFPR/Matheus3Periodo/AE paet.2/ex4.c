#include <stdio.h>

void numeros(int v[10]);

int main (void){
    int v[10]={1,2,3,4,5,6,7,8,9,10};

    numeros(v);

return 0;
}

void numeros(int v[10]){
    int i,par=0,impar=0;

    for(i=0; i<10; i++){
        if(v[i]%2==0){
         par=par+1;
        }
        else {
         impar=impar+1;
        }
    }
    printf(" %i numeros pares", par);
     printf(" %i numeros impares", impar);



}
