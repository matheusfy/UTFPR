
#include<stdio.h>
#include<stdlib.h>

int recu(int v[], int n){
        int x;
    if (n<0){

    }
   else{

    return x = v[n]*recu( v, n-1);

   }
    return 1;
}

int main (void){

    int v[100],n,i=0;


    scanf("%d", &n); /*tamanho do vetor de inteiros*/

    while(i<n){
    scanf("%d", &v[i]);
    i++;
    }


    recu(v, n-1);
}
