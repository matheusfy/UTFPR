#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int calculo(int a, int b, int *soma, int *sub){

    *soma = a+b;
    *sub = a-b;
}
int main (void){

    int x,y,soma, sub;

    scanf("%d", &x);
    scanf("%d", &y);

    calculo(x,y,&soma,&sub);

    printf("soma: %d ", soma);
    printf("subtracao: %d ", sub);
}
