#define MAX 100 		/* Max. Tamanho da Lista */
#define TRUE 1
#define FALSE 0
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
		int chave;
		char info[100];
} elem;				        /* Tipo do Elemento */

typedef struct{
		int nelem;
		elem A[MAX+1];
} Lista; 			/* Tipo da Lista */


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

int Remover(int p, Lista *L){
/* Remove o elemento da posi��o p da Lista.
Se L = a1,a2,...,an ent�o tem-se a1,a2,...,ap-1,ap+1,...,an.
Devolve true se sucesso, false c.c. (L n�o tem posi��o p, inclusive se p = Fim(L))  */
	int atual;
	if(p >= Fim(L) || p < 1 || Lista_vazia(L))
        return FALSE;
	else {
		for (atual = p+1; atual <= L->nelem; atual++)
			L->A[atual-1] = L->A[atual];
		L->nelem--;
	}
    return TRUE;
}

elem* Obter(Lista *L, int p){
/* Retorna elem. da posi��o p, ou elem. inv�lido se p � inv�lida */
	if (p >= Fim(L) || p < 1 || Lista_vazia(L))
		return NULL;    /* retorna elemento inv�lido */
	else
        return &(L->A[p]);
}
                       /*Busca sequencial utilizando while*/
   /* int busca_while(Lista*L ,int i)
    {
        int p=1;
        if (Lista_cheia(L))
		return FALSE;
        while( p<=L->nelem){
            elem*atual = Obter(L,p);
            if (atual->chave == i){
            return p;
            }
            else
            p++;
        }
        return -1;
        }
*/
        /*busca sequencial utilizando recursividade*/
/*
int recursividade(Lista*L, int i, int p ){
        if (Lista_cheia(L))
		return FALSE;

        if( p<=L->nelem){
            elem*atual = Obter(L,p);
            if (L->A[p].chave == i){
            return p;
            }
            else{
           return recursividade(L, i, p+1);
        }
        }
        return -1;
}
*/
        /*busca sequencial binaria*/
int busca_binaria(Lista*L, int i){
    int e=0,p,d;
         if (Lista_cheia(L))
		return FALSE;
		d=L->nelem;
         while(e<=d){
            p = (e+d)/2;
            elem*atual = Obter(L,p);
            if(atual->chave==i){
            return p;
            }
            else if(atual->chave<i){
            e=p+1;
            }
            else
            d=p-1;
         }
        return -1;
    }


int main(void){
    Lista chamada;			/* Exemplo de Declara��o*/
    Definir(&chamada);
    char resp;

    int i /*,p=1*/;
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

            printf("Procurar aluno pelo  RA  ");
            scanf("%d", &i);
        printf("%s",chamada.A[busca_binaria(&chamada,i)].info);
            /*
    printf("%s",chamada.A[recursividade(&chamada, i, p)].info);
*/
    /* printf("Procurar aluno pelo  RA  ");
    scanf("%d", &i);
    printf("%s",chamada.A[busca_while(&chamada, i)].info);
*/

   /* elem *aluno = Obter(&chamada, 4);
    printf("O aluno %s tem matricula nro. %d.\n", aluno->info, aluno->chave);

    printf("\nRemovendo aluno com matricula 3.\n");
    Remover(3, &chamada);

    aluno = Obter(&chamada, 4);
    printf("\nO aluno %s tem matricula nro. %d.\n", aluno->info, aluno->chave);
*/

}


