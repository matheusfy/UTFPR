#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct NoTag{
    int chave;
    struct NoTag *link;
    struct NoTag *ant;
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
     p = (no*) malloc(sizeof(no));
     p->chave = ch;
     p->link = L->inicio;
     p->ant = NULL;
     L->inicio = p;

     L->quant++;

 }

int busca(LD*L ,int ch, no *p){
    if(L->quant==0) return 0;
    else {
        p = L->inicio;
         while(p!=NULL){
             if(p->chave ==ch){
                 return 1;
             }
             else{
                 p=p->link;
             }
         }
         return 0;
}
}

   void remover(LD*L, no*p){
            no *q = p->link;
            p-> link = q-> link;
            free(q);
            L->quant--;
    }

    Inserir(LD*L, int ch, int pos){
    int i;
      no *velho;
      no *novo;
     novo = (no*) malloc(sizeof(no));
     velho= L->inicio;
    for(i=0; i==pos; i++){
        velho=velho->link;
    }

        novo->chave = ch;
        velho->link= novo;

     L->quant++;

    }
    void Imprime(LD*L){
        no*p;

        for( p=L->inicio; p!=NULL; p= p->link){
            printf("%i", p->chave );
        }

        }


int main (void){
    LD qualquer;
    Definir(&qualquer);
int i;
    scanf("%d", &i);
    InserirPrim(&qualquer, i);

    int n,x;
        printf("inserir na posicao: ");
        scanf("%i", &n);
        printf("de valor: ");
        scanf("%i", &x);
    Inserir(&qualquer, x, n);
    Imprime(&qualquer);





}
