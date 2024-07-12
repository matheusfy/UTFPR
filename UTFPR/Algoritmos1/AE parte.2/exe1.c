//1) Implemente uma função que imprima o número de 0s e 1s dado um vetor de inteiros. Assuma que este vetor possui apenas 0s e 1s.

#include <stdio.h>
#include <time.h>

void imprima(int vet[10]);


int main (void){

int i,vet[10];

srand(time(NULL));
for(i=0; i<10; i++){
        vet[i]= rand()%2;
}

    imprima(vet);
    return 0;
}

void imprima(int vet[10]){
    int i;
    for(i=0; i<10; i++){

        printf("vetor[%d]=%d\n",i,vet[i]);

    }

}

