#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;
}

void selectionSort( int vetorDesordenado[], int tamanhoVetor )
{
   int i, j, posicaoValorMinimo;

   for (i= 0; i < ( tamanhoVetor - 1 ); i++)
   {
      posicaoValorMinimo = i;
      for (j = ( i + 1 ); j < tamanhoVetor; j++)
      {
         if( vetorDesordenado[j] < vetorDesordenado[posicaoValorMinimo] )
         {
           posicaoValorMinimo = j;
         }
       }

       if ( i != posicaoValorMinimo )
       {
          trocarPosicaoValores( &vetorDesordenado[i], &vetorDesordenado[posicaoValorMinimo] );
       }
   }
}


int main ()
{
    int i,vet[100];

    srand(time(NULL));

    for (i=0; i<100; i++)
    {
        vet[i]= rand()%100;

    }
    selectionSort(vet, 100);
    printf("\n");
    for (i=0; i<100; i++)
    {

        printf(" %i\t", vet[i]);
    }



}
