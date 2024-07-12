#include <stdio.h>

int main (void)
{

    int i,j;
    char vetor[10];
    printf("insira um numeros entre 0 e 1\n");
        for(i=0;i<10; i++){
            printf("vetor[%i]", i);
        do{
            scanf(" %c", &vetor[i]);
        }while( vetor[i]==1 || vetor[i]==0);

        }


}
