#include <stdio.h>


int valor(int vet[], int a, int i,int j)
{
    if (i==10)
    {
        printf("%i",a);
        return 0;
    }
    else if(vet[i]==j)
    {
         a++;
}
              i++;
    valor(vet,a,i,j);
    }




int main(void)
{

    int vet[10]={1,2,3,4,5,6,7,11,50,11}, a=0,i=0,j=11;

    valor(vet,a,i,j);
}
