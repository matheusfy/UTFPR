

                    /*FILA*/
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
        L->inicio = p;
    }
    else{
        novo = L->inicio;
        while(novo->prox != NULL){
            novo = novo->prox;
        }
        novo->prox = p;
    }
     printf("%i", p->chave);
}

void Dequeue (Lista*L){
    int n;
    no *p;
    if (L->inicio == NULL)
    {
        printf("A lista esta vazia");
    }
    else{
    p = L->inicio;
    n = p->chave;
    L->inicio = p->prox;
    free(p);
    }
}

void imprimir(Lista*L)
{
	printf(" {");
	while (L->inicio != NULL)
	{
		printf("%i", L->inicio->chave);
		L->inicio = L->inicio->prox;
	}
	printf("}\n");
}

int main (void){
    Lista fila;
    Definir(&fila);
    Enqueue(&fila,1);
    Enqueue(&fila,2);
    Enqueue(&fila,3);
    Enqueue(&fila,4);
    Enqueue(&fila,5);
    Enqueue(&fila,6);
    Enqueue(&fila,7);
    Dequeue(&fila);
    imprimir(&fila);

    return 0;
}
