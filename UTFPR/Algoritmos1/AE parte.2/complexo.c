#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complexo.h"

struct complexo {
    float a;
    float b;
};


complexo cria(float a, float b){
    complexo c = malloc(sizeof(struct complexo));
    if (c == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    c->a = a;
    c->b = b;
    return c;
}

void libera (complexo c){
    free(c);
}

void acessa (complexo c, float* a, float* b){
    *a = c->a;
    *b = c->b;
}

void atribui (complexo c, float a, float b){
    c->a = a;
    c->b = b;
}

float modulo(complexo c){
    float a2 = c->a * c->a;
    float b2 = c->b * c->b;
    return sqrt(a2 + b2);
}

complexo soma(complexo c1, complexo c2){
    complexo tempsoma = malloc(sizeof(complexo));
    if (tempsoma == NULL) {
        printf("Memoria insuficiente!\n");
        exit(1);
    }
    tempsoma->a = c1->a + c2->a;
    tempsoma->b = c1->b + c2->b;
    return tempsoma;
}


int main(void){
    complexo num1 = cria(2.0, 3.1);

    float a,b;
    acessa(num1, &a, &b);
    printf("Soma = %.2f + %.2f i\n", a, b);

    libera(num1);

    return 0;
}
