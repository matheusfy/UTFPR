#include <stdio.h>
#include <stdlib.h>

typedef struct NoTag{
    int chave;
    struct NoTag *prox;
}no;

typedef struct {
    no*inicio;
    int quant;
}Lista;

void Definir (Lista*L){
    L->fim=NULL;
    L->inicio= NULL;
    L->quant=0;
}

void Enqueue (Lista*L, int ch){
    no*novo;
    no *p;
    p = (no*)malloc(sizeof(no));
    p->chave = ch;
    p->prox = NULL;

    if (L->inicio ==NULL) {
        p->prox = NULL;
        L->inicio = p;

    }
    else{
        novo = L->inicio;
        while(novo->prox != NULL){
            novo = novo->prox;
        }
        novo->prox= p;
    }
    L->quant++;
}

void Dequeue (Lista*L){
    int n;
    no *p;
    no*aux;
    if (L->inicio == NULL)
    {
        printf("A lista esta vazia");
    }
    else{
    p=L->inicio;
    L->inicio=p->prox;
    free(p);
    }
    L->quant--;
}
    void inverte(Lista*L){
    no*aux1;
    no*aux2;
    no*p;

    for( p=L->inicio; L->quant<6; p=p->prox){
        aux1=p;

    }


    }

void imprimir(Lista*L)
{
    no*p;
	printf(" ");
	p=L->inicio;
	while (p != NULL)
	{
		printf("%c-", p->chave);
		p =p->prox;
	}
	printf("\n");
}
            /* WHY SO SERIOUS*/
int main (void){
    Lista fila;
    Definir(&fila);
    Enqueue(&fila,79);
    Enqueue(&fila,83);
    Enqueue(&fila,89);
    Enqueue(&fila,72);
    Enqueue(&fila,87);
    Enqueue(&fila,83);
    Enqueue(&fila,85);
    Enqueue(&fila,79);
    Enqueue(&fila,73);
    Enqueue(&fila,82);
    Enqueue(&fila,69);
    Enqueue(&fila,83);
    imprimir(&fila);
    printf("\n");


    return 0;
}
