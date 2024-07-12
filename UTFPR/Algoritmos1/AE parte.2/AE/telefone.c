#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct {



}letra;
typedef struct {
        int chave;
        char inf[10];
}elem;


typedef struct{
		int nelem;
		elem A[MAX+1];
} Lista;

int Fim(Lista *L){
	/* Retorna a posi��o ap�s o �ltimo elemento da lista */
	return (L->nelem + 1);
}


int Lista_cheia(Lista *L){
	/* Retorna true se lista cheia, false caso contr�rio */
	return (L->nelem == MAX);
}

void Definir(Lista *L){
	/* Define uma lista vazia */
	L->nelem= 0;
	L->A[0].chave = 0;       /* C�lula n�o utilizada */
	L->A[0].info[0] = '\0';  /* C�lula n�o utilizada */
}

int func(){

}

int main (void){
 int v[4],a,;

 for(a=0; a<4; a++){
    scanf("%d", &v[a]);

 }
}
