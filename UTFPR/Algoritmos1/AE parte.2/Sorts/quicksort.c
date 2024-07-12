#include<stdio.h>
void Quick(int vetor[], int inicio, int fim);

int main (void)
{
    int i,vet[100];

    srand(time(NULL));

    for (i=0; i<100; i++)
    {
        vet[i]= rand()%100;
    }
    Quick(vet, 0,99);
    printf("\n");
    for (i=0; i<100; i++)
    {

        printf(" %i\t", vet[i]);
    }



}
void Quick(int vetor[], int inicio, int fim){

   int pivo, aux, i, j, meio;

   i = inicio;
   j = fim;

   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];

   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;

      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);

   if(inicio < j) Quick(vetor, inicio, j);
   if(i < fim) Quick(vetor, i, fim);

}
