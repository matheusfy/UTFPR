#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main (void){
    int vetor[10],n;
    vetor[0]=2;
    vetor[1]=3;
    vetor[2]=3;
    vetor[3]=3;
    vetor[4]=4;
    vetor[5]=4;
    vetor[6]=7;
    vetor[7]=10;
    vetor[8]=15;
    vetor[9]=15;
    sequencial_simples(3,10,vetor);
    printf(" %d", n);
    /*busca_binaria(3,10,vetor);
    printf(" %d", vetor[);
    */
}
int sequencial_simples(int x,int n, int v[]){
    int m=0;
    while(m < n && v[m]<x)
        m++;
        if (m < n && v[m]==x)
        return m;



}
void sequencial_dupla(){

}

void busca_binaria(int x, int n, int v[], int *primeiro,int *ultimo){

int e=0,d=9, m;

        while(e<=d){


        }



}
