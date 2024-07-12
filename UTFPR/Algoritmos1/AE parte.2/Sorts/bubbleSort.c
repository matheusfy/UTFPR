#include<stdio.h>
#include<time.h>
void bubbleSort( int vetorDesordenado[], int tamanhoVetor );
void trocarPosicaoValores( int *posicaoA, int *posicaoB );

int main (void)
{
    int i,vet[100];

    srand(time(NULL));

    for (i=0; i<100; i++)
    {
        vet[i]= rand()%100;
    }
    bubbleSort(vet, 100);
    printf("\n");
    for (i=0; i<100; i++)
    {

        printf(" %i\t", vet[i]);
    }



}

void bubbleSort( int vetorDesordenado[], int tamanhoVetor )
{
   int i, j;
   for( i = 0; i < ( tamanhoVetor -1 );  i++ )
   {
      for( j=0; j <( tamanhoVetor -( i +1 ) ); j++ )
      {
         if( vetorDesordenado[j] > vetorDesordenado[j+1] )
         {
            trocarPosicaoValores( &vetorDesordenado[j], &vetorDesordenado[j+1] );
         }
      }
   }
}
void trocarPosicaoValores( int *posicaoA, int *posicaoB )
{
   int temporario;
   temporario = *posicaoA;
   *posicaoA = *posicaoB;
   *posicaoB = temporario;
}
