/*5. Implemente uma função recursiva que recebe uma string e susbtitui as letras minúsculas por maiúsculas e vice-versa.*/

#include<stdio.h>

int troca(char vet[], int i)
{

    if (i>15)
    {
        return 0;
    }

    if (vet[i]>=65 && vet[i]<=90)
    {
        vet[i]= vet[i]+32;
        printf("%c",vet[i]);
        i++;
        troca(vet,i);
    }
    else{
     vet[i]=vet[i]-32;
     printf("%c",vet[i]);
     i++;
     troca(vet,i);
    }



}


int main (void)
{

    char vet[16]={"HUE HUE  br br  "};
    int i=0;

    troca(vet,i);


}
