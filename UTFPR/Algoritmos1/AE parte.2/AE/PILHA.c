/* Pilha e Filas , (Definir , Inserir, Remover)
 - Terminar Implementaçao das Estruturas de dados até Sexta-Feira. 08/05 */

                /*PILHA*/
#include <stdio.h>

 typedef struct NoTag{
     int chave;
     struct NoTag *prox;
 } no;

 typedef struct {
     no* inicio;
     no*fim;
    int quant;

}Lista;

void Definir(Lista*L){
    L->inicio= NULL;
    L->fim = NULL;
    L->quant = 0;
}

void push(Lista*L,int ch){
    no* p;
    no* aux;
    p = (no*) malloc(sizeof(no));
    if (p==NULL){
        printf("sem memoria !");
        exit(1);
}
    else{
        p->chave= ch;
    if(L->fim==NULL){
        p->prox =NULL;
    }
    else{
        p->prox=L->fim;
    }
    L->fim=p;
}
}

void pop(Lista*L){
    no *aux;
    if (L->fim==NULL){
        printf("A lista esta vazia");
    }
    else{
        aux = L->fim->prox;
        free(L->fim);
        L->fim =aux;
    }
}

void imprimir(Lista*L){
	no* aux;
	if(L->fim ==NULL){
	printf("A lista esta vazia");
	}
	else{
	    aux=L->fim;
	    while(aux!=NULL){
	     printf("%i", aux->chave);
	     aux=aux->prox;
	    }
}
}

int main (void){
    Lista pilha;
    Definir(&pilha);
    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);
    imprimir(&pilha);
    pop(&pilha);
    printf("\n");
    imprimir(&pilha);
    pop(&pilha);
    printf("\n");
    imprimir(&pilha);
    pop(&pilha);
    printf("\n");
    imprimir(&pilha);
    pop(&pilha);
    printf("\n");
    imprimir(&pilha);
    pop(&pilha);
    printf("\n");
    imprimir(&pilha);
    return 0;
}
