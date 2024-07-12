#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

typedef struct noHash {
	char nome[TAM];
	int ddd, id, null;
	long int tel;
	struct noHash *next;
}	no;

typedef struct listaHash {
	no *lista;
	int Nelem;
}	listaHash;

void definir(listaHash *L){
	L->lista = malloc(sizeof(no) * 26);
	L->Nelem = 0;
	int i;
	for(i = 0; i < 26; i++){
		L->lista[i].null = 1;
		L->lista[i].next = NULL;
	}
}

int hash(char chave[]){
	return chave[0] - 97;
}

no *rehash(no *p){
	no *q = malloc(sizeof(no));
	q->next = p->next;
	p->next = q;
	return q;
}

void inserir(listaHash *L, char nome[], int ddd, long int tel){
	int pos = hash(nome);
	if(L->lista[pos].null == 0){
		no *q = rehash(&(L->lista[pos]));
		strcpy(q->nome, nome);
		q->ddd = ddd;
		q->tel = tel;
		q->id = L->Nelem++;
		q->null = 0;
	}	else {
		strcpy(L->lista[pos].nome, nome);
		L->lista[pos].ddd = ddd;
		L->lista[pos].tel = tel;
		L->lista[pos].id = L->Nelem++;
		L->lista[pos].null = 0;
	}
}

int remover(listaHash *L, char nome[]){
	int pos = hash(nome);
	no *p = &(L->lista[pos]);
	if(p == NULL) return 0;
	while(p->next != NULL){
		if(!strcmp(nome, p->next->nome)){
			no *q = p->next;
			p->next = q->next;
			free(q);
			q = NULL;
			L->Nelem--;
			return 1;
		}	p = p->next;
	}	return 0;
}

int buscaNome(listaHash *L, char nome[], no **p){
	int pos = nome[0] - 97;
	if(L->lista[pos].null){
		p = NULL;
		return 0;
	}
	for(*p = &(L->lista[pos]); *p != NULL; *p = (*p)->next){
		if(!strcmp(nome, (*p)->nome))
			return 1;
	}
	*p = NULL;
	return 0;
}

int buscaId(listaHash *L, int id, no **p){
	int i;
	for(i = 0; i < 26; i++){
		for(*p = &(L->lista[i]); *p != NULL; *p = (*p)->next){
			if(id == (*p)->id)
				return 1;
		}
	}
	*p = NULL;
	return 0;
}

void printa(listaHash *L){
	int i;
	no *p;
	for(i = 0; i < 26; i++){
		for(p = &(L->lista[i]); !L->lista[i].null && p != NULL; p = p->next)
			printf("%d: %s\t%d\t%ld\n", p->id, p->nome, p->ddd, p->tel);
	}
}

int main(){
	listaHash L;
	definir(&L);
	no *p;
	inserir(&L, "tyr", 666, 66666666);
	inserir(&L, "zok", 456, 53465653);
	inserir(&L, "rag", 123, 65754656);
	inserir(&L, "mer", 437, 67567567);
	inserir(&L, "tor", 435, 65743576);
	inserir(&L, "ekl", 312, 87456768);
	inserir(&L, "fgg", 551, 67876867);
	inserir(&L, "fss", 519, 78678667);
	inserir(&L, "fsd", 357, 56858787);

	printa(&L);
	puts("\n");
	buscaNome(&L, "tyr", &p);
	printf("%d: %s\t%d\t%ld\n\n", p->id, p->nome, p->ddd, p->tel);
	buscaId(&L, 3, &p);
	printf("%d: %s\t%d\t%ld\n\n", p->id, p->nome, p->ddd, p->tel);

	remover(&L, "fsd");
	printa(&L);
	return 0;
}
