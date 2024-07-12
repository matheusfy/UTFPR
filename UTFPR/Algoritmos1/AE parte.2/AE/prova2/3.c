#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct NoTag{
    int chave;
    struct NoTag *prox;
    struct NoTag *ant;
}no;

typedef struct {
     no* inicio;
     no* fim;
    int quant;
}LD;

void Definir(LD*L){
    L->inicio = NULL;
    L->fim=NULL;
    L->quant = 0;
}

 void InserirPrim(LD *L, int ch){
     no *p;
     p = (no*) malloc(sizeof(no));
     if(L->inicio==NULL){
         p->chave = ch;
         p->ant=NULL;
         p->prox = L->fim;
         L->inicio=p;
         L->fim=p;
     }
     else{
         p->chave = ch;
         p->prox = L->inicio;
         p->prox->ant = p;
         p->ant = NULL;
         L->inicio = p;
         L->quant++;
     }
 }

int busca(LD*L ,int ch){
    no*p;
    int i=0;
    if(L->quant==0) return 0;
    else {
        p = L->fim;
         while(p!=NULL){
            i++;
             if(p->chave ==ch){
                  printf("O valor buscado %i , esta na posicao %i de tras para frente",p->chave,i);
                 return 1;
             }
             else{
                 p=p->ant;
             }
         }
         return 0;
}
}

   void remover(LD*L, no*p){
            no *q = p->prox;
            p->prox = q-> prox;
            free(q);
            L->quant--;
    }

    void Inserir(LD*L, int ch, int pos){
    int i;
      no *velho;
      no *novo;
      if(L->quant<pos){
          printf("Nao e possivel inserir nesta posicao\n");
      }else{
         novo = (no*)malloc(sizeof(no));
         velho = L->inicio;

    for(i=1; i<pos; i++){
        velho=velho->prox;
    }
        novo->chave = ch;
        novo->prox=velho->prox;
        novo->ant=velho;
        velho->prox=novo;
        L->quant++;
      }
    }

    void Imprime(LD*L){
        no*p;

        for( p=L->inicio; p!=NULL; p= p->prox){

            printf("%i-", p->chave );
        }
            printf("\n");
        }

    void removerposicao(LD*L, int pos){
      no*aux;
      int i;
      if (L->quant==0){
       printf("lista vazia\n");
      }
      else{
      aux=L->inicio;
        for (i=1;i<pos;i++ ){
            aux=aux->prox;
        }
        if(aux->ant != NULL){
            (aux->ant)->prox = aux->prox;
            (aux->prox)->ant = aux->ant;
        }else{
            L->inicio = aux->prox;
            (aux->prox)->ant = NULL;
        }
        free(aux);
        L->quant--;
      }
        }


int main (void){
    LD qualquer;
    Definir(&qualquer);

    InserirPrim(&qualquer, 1);
    InserirPrim(&qualquer, 2);
    InserirPrim(&qualquer, 3);
    InserirPrim(&qualquer, 4);
    Imprime(&qualquer);
    busca(&qualquer,3);

    return 0;
}
