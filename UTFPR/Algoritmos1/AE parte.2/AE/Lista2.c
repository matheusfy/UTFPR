#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct {
    int chave;
    int prox;
}elem;                  /* Tipo do Elemento */

typedef struct {
    int nelem;
    elem A[MAX+1];
}Lista;                 /* Tipo da Lista */

void Definir(Lista *L){
	/* Define uma lista vazia */
	L->nelem= 0;
	L->A[0].chave = 0;       /* C�lula n�o utilizada */
	L->A[0].info[0] = '\0';  /* C�lula n�o utilizada */
}

int Fim(Lista *L){
	/* Retorna a posi��o ap�s o �ltimo elemento da lista */
	return (L->nelem + 1);
}

int Lista_vazia(Lista *L){
	/* Retorna true se lista vazia, false caso contr�rio */
	return (L->nelem == 0);
}

int Lista_cheia(Lista *L){
	/* Retorna true se lista cheia, false caso contr�rio */
	return (L->nelem == MAX);
}

int Inserir(elem* x, int p, Lista *L){
/* Insere elemento x na posi��o p da Lista L.
Se a lista � tal que L=a1,a2,...,ap,...,an ent�o L=a1,a2,...,ap-1,x,ap+1,...,an.
Se p=Fim(L) ent�o L=a1,a2,...,an,x.
Devolve true se sucesso, false se L cheia ou n�o tem posi��o p. L n�o ordenada! */
	int atual;
	if (Lista_cheia(L))
		return FALSE;  /* lista cheia */
	else if (p > Fim(L) || p < 1)
		return FALSE; /* posi��o n�o existe */
	else {
		for(atual = L->nelem; atual >= p; atual--)
			L->A[atual+1] = L->A[atual];
		L->A[p]=  *x;
		L->nelem++;
		return TRUE; /* inser��o com sucesso */
	}
}

elem* Obter(Lista *L, int p){
/* Retorna elem. da posi��o p, ou elem. inv�lido se p � inv�lida */
	if (p >= Fim(L) || p < 1 || Lista_vazia(L))
		return NULL;    /* retorna elemento inv�lido */
	else
        return &(L->A[p]);
}

int main(void){
    Lista chamada;			/* Exemplo de Declara��o*/
    Definir(&chamada);
    char resp;

    int i;
    int aux;
    //adicionar 5 novos alunos a chamada
    for (i=1; i<=5; i++) {
        elem novo;
        novo.chave = i;

        printf("Digite o nome de um aluno: ");
        scanf("%s", &novo.info);
        getchar();

        aux = Inserir(&novo, i, &chamada);
        if (aux<0)
            printf("Erro insercao");
    }
    printf("\n\n");

}
