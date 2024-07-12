#include <stdio.h>


int cont(int v[], int i)
{
    if (i==10)
    {
        return 0;
    }
    v[i]= rand()%2;
    i++;
    cont(v,i);


}



int main(void)
{

    int v[10],i=0;

    cont(v,i);

    for (i=0; i<10; i++)
    {
        printf(" vet[%d]=%d\n",i,v[i]);
    }



}
