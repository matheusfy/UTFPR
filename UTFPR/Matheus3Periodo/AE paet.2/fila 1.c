/*1) Resolva o exercício do Batman (exercícios com listas circulares) utilizando uma fila.
 Utilize um caractere qualquer da mensagem do Coringa como início, insira todos os demais em sentido anti-horário e imprima uma possível mensagem.
 A seguir, remova o primeiro nó da fila e novamente insera-o ao final (ou um nó idêntico).
  Repita este processo até que todas possíveis mensagens sejam impressas.*/
                /*FILA*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NoTag{
    int chave;
    struct NoTag *prox;
}no;

typedef struct {
    no*inicio;
    no*fim;
    int quant;
}Lista;

void Definir (Lista*L){
    L->fim = NULL;
    L->inicio= NULL;
    L->quant=0;
}

void Enqueue (Lista*L, int ch){
    no *p;
    p = (no*)malloc(sizeof(no));
    p->chave = ch;
    p->prox = NULL;

    if (L->inicio ==NULL) {
        L->inicio = p;
        L->fim = p;
    }
    else{
       p->prox= L->fim->prox;
       L->fim->prox=p;
       L->fim = p;
    }
    L->quant++;
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
    L->inicio = p->prox;
    free(p);
    }
}
int DequeueRetorna (Lista*L){
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
    return n;
    }
}

void imprimir(Lista*L)
{

	while (L->inicio != NULL)
	{
		printf("%c\n", L->inicio->chave);
		L->inicio = L->inicio->prox;
	}
	;
}

int main (void){
    Lista fila;
    Definir(&fila);
    int i=0;
    Enqueue(&fila,79);
    Enqueue(&fila,83);
    Enqueue(&fila,69);
    Enqueue(&fila,82);
    Enqueue(&fila,73);
    Enqueue(&fila,79);
    Enqueue(&fila,85);
    Enqueue(&fila,83);
    Enqueue(&fila,87);
    Enqueue(&fila,72);
    Enqueue(&fila,89);
    Enqueue(&fila,83);

    i = DequeueRetorna(&fila);
    Enqueue(&fila,i);
    imprimir(&fila);

    return 0;
}
