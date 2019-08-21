#include <stdio.h>
#include <stdlib.h>

int fat(int x)
{


        if (x==1){

        return x;

    }
        else

        return fat(x-1)*x ;







}

int main ()
{
 int x;

        printf("insira um numero que deseja saber quanto e o seu fatorial: \n");
        scanf("%i", &x);

        fat(x);
        return ;
}
