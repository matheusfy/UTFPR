#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef struct NoTag
{
    int chave;
    struct NoTag *prox;
}no;

typedef struct
{
    no*inicio;
    no*fim;
    int quant;
}Lista;

void Definir (Lista*L)
{
    L->fim = NULL;
    L->inicio= NULL;
    L->quant=0;
}

void Enqueue (Lista*L, int ch)
{
    no *p;
    p = (no*)malloc(sizeof(no));
    p->chave = ch;

    if (L->inicio ==NULL)
    {
        L->inicio = p;
        L->fim = p;
         p->prox = NULL;
    }
    else
    {
        p->prox= L->fim->prox;
        L->fim->prox=p;
        L->fim = p;
    }
    L->quant++;
}

void Dequeue (Lista*L)
{
    int n;
    no *p;
    if (L->inicio == NULL)
    {
        printf("A lista esta vazia");
    }
    else
    {
        p = L->inicio;
        L->inicio = p->prox;
        free(p);
    }
}
/*
no *DequeueRetorna (Lista*L){
    int a;
    no *p;
    if (L->inicio == NULL)
    {
        printf("A lista esta vazia");

    }
    else{
    p = L->inicio;
    L->inicio = p->prox;
    free(p);
    }
    return n;
}
*/
int retornamaior (Lista*L, int n)
{
    int a;
    no *p;
    if (L->inicio == NULL)
    {
        printf("A lista esta vazia\n");
    }
    else
    {
        p = L->inicio;
        a = p->chave;
        L->inicio = p->prox;
        if (a>n)
        {
            n=a;
        }
        free(p);


    }
         return n;
}


void imprimir(Lista*L)
{

    while (L->inicio != NULL)
    {
        printf("%i\n", L->inicio->chave);
        L->inicio = L->inicio->prox;
    }

}

int main (void)
{
    Lista fila;
    Definir(&fila);
    int i=0, j=0,sorteado=0, k=0;
    srand(time(NULL));

    for (i=0; i<10; i++)
    {
        Enqueue(&fila,j=rand()%20);
    }
    imprimir(&fila);
    printf("\n");
    i=0;

    for (sorteado = rand()%10; i<sorteado; i++)
    {
        k = retornamaior(&fila, k);
    }
        imprimir(&fila);


    return 0;
}
