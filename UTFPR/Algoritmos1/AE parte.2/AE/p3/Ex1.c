#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIN 3
#define COL 3

typedef struct NoT {
	int lin, col, val;
	struct NoT *nextLin, *nextCol;
}	no;

typedef struct {
	no *qlin, *qcol;
	int Nlin, Ncol, nelem;
}	matEsp;

void define(matEsp *L, int l, int c){
	int i;
	L->qlin = malloc(sizeof(no) * l);
	L->qcol = malloc(sizeof(no) * c);
	L->nelem = 0;
	L->Nlin = l;
	L->Ncol = c;
	for(i = 0; i < c; i++){
		L->qcol[i].col = i;
		L->qcol[i].lin = -1;
		L->qcol[i].val = 0;
		L->qcol[i].nextCol = NULL;
	}
	for(i = 0; i < l; i++){
		L->qlin[i].col = -1;
		L->qlin[i].lin = i;
		L->qlin[i].val = 0;
		L->qlin[i].nextLin = NULL;
	}
}

int busca(matEsp *L, int l, int c, no **p){
	*p = &(L->qcol[c]);
	while(*p != NULL){
		if((*p)->lin == l)
			return 1;
		(*p) = (*p)->nextCol;
	}
	*p = NULL;
	return 0;
}

int insere(matEsp *L, int l, int c, int v){
	no *q;
	if(l >= L->Nlin || c >= L->Ncol || c < 0 || l < 0 || busca(L, l, c, &q)) return 0;
	no *p = malloc(sizeof(no));
	p->lin = l;
	p->col = c;
	p->val = v;
	q = &(L->qlin[l]);
	while(q->nextLin != NULL && q->nextLin->lin < l)
			q = q->nextLin;
	p->nextLin = q->nextLin;
	q->nextLin = p;
	q = &(L->qcol[c]);
	while(q->nextCol != NULL && q->nextCol->col < c)
			q = q->nextCol;
	p->nextCol = q->nextCol;
	q->nextCol = p;
	L->nelem++;
	return 1;
}

int remover(matEsp *L, int l, int c){
	no *p;
	if(l >= L->Nlin || c >= L->Ncol || c < 0 || l < 0 || !busca(L, l, c, &p)) return 0;
	no  *ql = &(L->qlin[l]), *qc = &(L->qcol[c]);
	while(ql->nextLin != NULL && ql->nextLin->col < c)
			ql = ql->nextLin;
	while(qc->nextCol != NULL && qc->nextCol->lin < l)
			qc = qc->nextCol;
	printf("V:%d, %d\n", ql->nextLin->val, qc->nextCol->val);
	if(qc->nextCol == NULL || ql->nextLin != qc->nextCol) return 0;
	p = qc->nextCol;
	qc->nextCol = p->nextCol;
	ql->nextLin = p->nextLin;
	free(p);
	p = NULL;
	L->nelem++;
	return 1;
}

/*int multiplica(matEsp *L1, matEsp *L2, matEsp *L3){
	if(L1->Ncol != L2->Ncol || L1->Nlin != L2->Nlin) return 0;
	define(L3, L1->Ncol, L1->Nlin);
	no *p, *q;
	int i;
	for(i = 0; i < L1->Nlin; i++){
		for(p = L1->qlin[i].nextLin; p != NULL; p = p->nextLin){
			if(busca(L2, i, p->col, &q))
				insere(L3, i, p->col, q->val * p->val);
		}
	}
}*/

/*int soma(matEsp *L1, matEsp *L2, matEsp *L3){
	if(L1->Ncol != L2->Ncol || L1->Nlin != L2->Nlin) return 0;
	define(L3, L1->Ncol, L1->Nlin);
	no *p, *q;
	int i;
	for(i = 0; i < L1->Nlin; i++){
		for(p = L1->qlin[i].nextLin; p != NULL; p = p->nextLin){
			if(busca(L2, i, p->col, &q))
				insere(L3, i, p->col, q->val + p->val);
			else
				insere(L3, i, p->col, p->val);
		}
	}
	for(i = 0; i < L2->Nlin; i++){
		for(p = L2->qlin[i].nextLin; p != NULL; p = p->nextLin){
			if(!busca(L3, i, p->col, &q))
				insere(L3, i, p->col, p->val);
		}
	}	return 1;
}
*/
 int diagonal(matEsp *L){
     no *p;
	int i, j;
	for(i = 0; i < L->Nlin; i++){
		for(j = 0; j < L->Ncol;j++){
		    busca(L, i, j, &p) ? printf(" " ) : printf("");
            if (i !=j && p->val!=0){
                printf("nao diagonal"); return 0;
            }
        }
        printf(" \n");
        }
        printf("diagonal\n");
        return 1;
		}






void imprime(matEsp *L){
	no *p;
	int i, j;
	for(i = 0; i < L->Nlin; i++){
		for(j = 0; j < L->Ncol;j++)
			busca(L, i, j, &p) ? printf("%d ", p->val) : printf("0 ");
		puts("");
	}
}

int main(){
	matEsp L, L2, L3;
	no *p;
	define(&L, 2, 2);
	define(&L2, 3, 3);
    define(&L3, 4, 4);
	insere(&L, 0, 0, 1);
	insere(&L, 0, 1, 0);
	insere(&L, 0, 2, 0);
	insere(&L, 1, 0, 0);
	insere(&L, 1, 1, 2);
	insere(&L, 1, 2, 0);
	insere(&L, 2, 0, 0);
	insere(&L, 2, 1, 0);
    insere(&L, 2, 2, 3);

	insere(&L2, 0, 0, 1);
	insere(&L2, 0, 1, 0);
	insere(&L2, 0, 2, 0);
	insere(&L2, 1, 0, 0);
	insere(&L2, 1, 1, 2);
	insere(&L2, 1, 2, 0);
	insere(&L2, 2, 0, 0);
	insere(&L2, 2, 1, 0);
	insere(&L2, 2, 2, 9);

	insere(&L3, 0, 0, 1);
	insere(&L3, 0, 1, 0);
	insere(&L3, 0, 2, 0);
	insere(&L3, 0, 3, 0);
	insere(&L3, 1, 0, 0);
	insere(&L3, 1, 1, 2);
	insere(&L3, 1, 2, 0);
	insere(&L3, 1, 3, 0);
	insere(&L3, 2, 0, 0);
	insere(&L3, 2, 1, 0);
	insere(&L3, 2, 2, 3);
	insere(&L3, 2, 3, 0);
	insere(&L3, 3, 0, 1);
	insere(&L3, 3, 1, 2);
	insere(&L3, 3, 2, 3);
	insere(&L3, 3, 3, 4);

//	soma(&L, &L2, &L3);
//	multiplica(&L, &L2, &L3);

//	remover(&L, 1, 0);
//	busca(&L, 0, 0, &p);
//	printf("%d\n", p->val);
//	printf("%d\n", L.qlin[0].nextLin->val);
//	printf("%d\n", L.qlin[0].nextLin->nextCol->val);
//	printf("%d\n", L.qlin[0].nextLin->nextLin->nextLin->val);
	imprime(&L);
    diagonal(&L);
    imprime(&L2);
    diagonal(&L2);
    imprime(&L3);
    diagonal(&L3);

}
