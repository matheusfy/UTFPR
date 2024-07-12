#include <stdio.h>

void mult( float *m , float *d , float a , float b){

    *m = a*b;
    if (b!=0){
    *d = a/b;
    }
    else
    printf("nao existe divisao por zero\n");

}


int main (void){

    float n1 , n2 , multiplicacao=0, divisao=0;

    scanf("%f",&n1);
    scanf("%f",&n2);

    mult(&multiplicacao, &divisao, n1, n2);

    printf("multiplicacao = %.3f \n", multiplicacao);
    if (divisao!=0){
    printf("divisao = %.2f", divisao);

    return 0;
}
}
