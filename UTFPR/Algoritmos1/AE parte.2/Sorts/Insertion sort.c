#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void insertionsort(int numeros[], int tam)
{

    int i, j, escolhido;
    for (i= 0;i < tam; i++)
    {

        escolhido = numeros[i];
        j = i - 1;
        while ((j>=0) && (escolhido < numeros[j]))
        {
            numeros[j+1] = numeros[j];
            j--;
        }
        numeros[j+1] = escolhido;

    }
}

int main (void)
{
    int i,vet[100];

    srand(time(NULL));

    for (i=0; i<100; i++)
    {
        vet[i]= rand()%100;
    }
    insertionsort(vet, 100);
    printf("\n");
    for (i=0; i<100; i++)
    {

        printf(" %i\t", vet[i]);
    }



}
