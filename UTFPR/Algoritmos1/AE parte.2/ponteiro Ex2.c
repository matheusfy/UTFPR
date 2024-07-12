#include <stdio.h>

void comparacao( int vet[] , int *maior , int *menor){
    int i;

    for (i=0; i<10; i++){

        if(vet[i]> *maior){
        *maior = vet[i];
        }

        if(vet[i]< *menor){
        *menor = vet[i];
        }


    }


}


int main (void){

    int vet[10]={4,2,3,4,5,6,7,8,9,40}, maior=0, menor=10;



    comparacao(vet, &maior, &menor);

    printf("maior = %i\n", maior);
    printf("menor = %i", menor);

    return 0;

}
