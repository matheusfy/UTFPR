/*1.	Solicite ao usuário que digite N diferentes números (ex.: N=10).
 A seguir, implemente uma função  que encontre o maior e o menor dentre os números digitados. Imprima esses valores fora do escopo da função.*/
#include <stdio.h>
#include <stdlib.h>

int compara( int num[], int *n, int i,int *p)
    {
        for (i=0; i<10; i++)
        {
            if (num[i]< *n)
            {
                *n = num[i];
            }
            if (num[i]>*p)
            {
                *p = num[i];
            }
        }

    }


int main (void){

    int n=100,i,p=0, num[10];

    for(i=0; i<10;i++){
        printf("insira 10 numeros aleatorios: ");
        scanf(" %i", &num[i]);
    }
    compara(num,&n,i,&p);
    printf("maior  : %d", p);
    printf("menor  : %d ", n);
}
