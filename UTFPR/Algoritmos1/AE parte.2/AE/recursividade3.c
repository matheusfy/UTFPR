#include <stdio.h>
#include <stdlib.h>

float div(float n){
    if (n<=0){}

    else
            div(n/10);
            printf(" %f", n);

}

float main ()
{
    float n;
  printf("insira numeros: ");
    scanf("%f", &n);

    div(float n);
}
