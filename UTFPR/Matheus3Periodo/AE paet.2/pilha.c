#include <stdio.h>

typedef struct NoTag
{

    int chave;
    char info ;
    struct NoTag *prox;
} no;

typedef struct
{
    no *fim;
    no *inicio;
    int nelem;
} PILHA;

void define(PILHA *L)
{
    L->fim=NULL;
    L->inicio=NULL;
    L->nelem=0;
}
void push(PILHA *L, no*novo)
{
    if(L->inicio==NULL)
    {
        novo->prox=L->inicio;
        L->inicio=novo;
        L->fim=novo;
        L->nelem++;
    }
    else
    {
        novo->prox=L->fim->prox;
        L->fim->prox = novo;
        L->fim=novo;
        L->nelem++;
    }
}
void imprimir(PILHA*L)
{
    no *p;
    if (L->inicio==NULL)
    {
        printf("Lista vazia");
    }
    p=L->inicio;
    while(p!=NULL)
    {
        printf("%d", p->chave);
        printf(" %c\n", p->info);
        p=p->prox;

    }

}
void pop(PILHA *L)
{
    no *p;
    no *q;
    p = L->inicio;
    if(L->inicio==NULL)
    {
        printf("lista vazia");
    }
    else
    {
        while(p->prox!=L->fim)
        {
            p=p->prox;
        }
        q = p->prox;
        p->prox=L->fim->prox;
        L->fim=p;
        free(q);
        L->nelem--;
    }
}
int main(void)
{
    PILHA L;
    define(&L);
    int i ;
    no *aux;
    for (i=0; i<5; i++)
    {
        aux = (no*)malloc(sizeof(no));
        aux->chave = rand()%20;
        aux->info = rand()%20+67;
        push(&L, aux);
    }
    imprimir(&L);
    pop(&L);
    printf(" \n");
    imprimir(&L);
    pop(&L);
    printf(" \n");
    imprimir(&L);
}
