#include <stdio.h>

 typedef struct NoTag{
     int chave;
     struct NoTag *prox;
 } no;
 typedef struct {
     no*fim;
    int quant;

}Lista;
void Definir(Lista*L){
    L->fim = NULL;
    L->quant = 0;
}
void push(Lista*L,int ch){
    no* p;
    no* aux;
    p = (no*) malloc(sizeof(no));
    if (p==NULL){
        printf(" !");

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
L->quant++;
}
void pop(Lista*L){
    no *aux;
    if (L->fim==NULL){

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

	}
	else{
	    aux=L->fim;
	    printf("figurinhas");
	    while(aux!=NULL){
	     printf("%i-", aux->chave);
	     aux=aux->prox;
	    }
}
}
void joao(Lista*L){
    int jo,i=0;
    no*p;
    p=L->fim;

    for(jo=0; jo<4||p->prox==NULL; jo++){
     pop(L);
        i++;
    }if(i<2){
        printf("\nJog.-%i- 4fig. para joao ");
    }
       printf("\nJog.-%i- 2fig. para joao ");
}
void juq(Lista*L){
    int ju;
    no*p;
    p=L->fim;
    for(ju=0; ju<2; ju++){
     pop(L);

    }
    printf("\nJog.-%i- 2fig. para juca ");
}

int main (void){
    Lista pilha;
    Definir(&pilha);
    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);
    push(&pilha, 6);
    push(&pilha, 7);
    push(&pilha, 8);
    push(&pilha, 9);
    push(&pilha, 10);
    push(&pilha, 11);
    push(&pilha, 12);
    push(&pilha, 13);
    push(&pilha, 14);
    push(&pilha, 15);
    push(&pilha, 16);
    push(&pilha, 17);
    push(&pilha, 18);
    push(&pilha, 19);
    push(&pilha, 20);
    printf("numero de figura");imprimir(&pilha);
    joao(&pilha);
    imprimir(&pilha);
    juq(&pilha);
    imprimir(&pilha);
     joao(&pilha);
    imprimir(&pilha);
    juq(&pilha);
    imprimir(&pilha);
     joao(&pilha);
    imprimir(&pilha);
    juq(&pilha);
    imprimir(&pilha);
     joao(&pilha);
    imprimir(&pilha);
    printf("\ncontabilizado no total 7 jogadas com a maximo dos dois ");
    printf("\n 14 figuras para joaozinho ");
    printf("\n 6 figuras para juquinha");

    return 0;
}
