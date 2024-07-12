#include <stdio.h>



int valor(int vet[], int a, int i)
{
    if (i==10){
        printf("%i\n",a);
        return 0;
    }
    else if (a<=vet[i]){
            a=vet[i];
        }
        i++;
        valor(vet,a,i);

}



int main(void){

    int vet[10]={1,2,3,4,5,6,7,11,50,10}, j=0,a=0;

    valor(vet, a, j);




}
