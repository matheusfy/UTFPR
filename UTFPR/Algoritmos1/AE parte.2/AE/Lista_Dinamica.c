#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct NoTag{
    int chave;
    char info[20];
    struct NoTag *prox;
}no;


typedef struct {
     no* inicio;
    int quant;
}LD;

void Definir(LD*L){
    L->inicio = NULL;
    L->quant = 0;
}

 void InserirPrim(LD *L, int ch){
     no *p;
     p = (no*)malloc(sizeof(no));
     p->chave = ch;
     p->prox = L->inicio;
     L->inicio = p;
     L->quant++;
 }

 void insere(LD*L, int ch, int pos){
     no*p;
     no*novo;
     int i ;
     p=L->inicio;
     novo= (no*)malloc(sizeof(no));
     for (i=1;i<=(pos-1);i++ ){
      p=p->prox;
     }
     	novo->chave=ch;
     	novo->prox=p->prox;
     	p->prox=novo;
     	L->quant++;


 }


int busca(LD*L ,int ch, no **p){
    if(L->quant==0) return 0;
    else {
        *p = L->inicio;
         while(*p!=NULL){
             if((*p)->chave ==ch){
                 return 1;
             }
             else{
                 *p=(*p)->prox;
             }
         }
         return 0;
}
}
/*
   void remover(LD*L, no**q){
           no*p;
            p = (*q)->prox;
            (*q)->prox = p->prox;
            free(p);
            L->quant--;
    }
*/
    void removerposicao(LD*L, int pos){
         no*p;
     no*velho;
     int i ;
     p=L->inicio;

     for (i=1;i<=(pos);i++ ){
      p=p->prox;
     }
     	velho=p->prox;
     	p->prox=velho->prox;
     	L->quant--;

    }

    int Imprime(LD*L){
        no*p;

        for( p=L->inicio; p!=NULL; p= p->prox){
            printf("%i", p->chave );
        }
        printf("\n");
       return 0;
        }


int main (void){
    LD qualquer;
    Definir(&qualquer);
    InserirPrim(&qualquer,1);
    InserirPrim(&qualquer,2);
    InserirPrim(&qualquer,3);
    InserirPrim(&qualquer,4);
   Imprime(&qualquer);
   insere(&qualquer, 5,2);
   Imprime(&qualquer);
   removerposicao(&qualquer,2);
   Imprime(&qualquer);

}
