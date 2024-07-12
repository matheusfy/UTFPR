#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define VAR 5

typedef struct noHash {
	char nome[20];
	int ddd, id, null;
	long int tel;
}	no;

typedef struct listaHash {
	no *lista;
	int Nelem;
}	listaHash;

void definir(listaHash *L){
	L->lista = malloc(sizeof(no)* TAM * 26);
	int i;
	L->Nelem = 0;
	for(i = 0; i < TAM * 26; i++){
		L->lista[i].ddd = 0;
		L->lista[i].tel = 0;
		L->lista[i].id = -1;
		L->lista[i].null = 1;
	}
}

int hash(char chave[]){
	return chave[0] - 97;
}

int rehash(int chave){
	if(chave < (TAM * 26) - 26) return chave + 26;
	else return -1;
}

int inserir(listaHash *L, char nome[], int ddd, long int tel){
	int pos = hash(nome);
	while(!L->lista[pos].null)
		pos = rehash(pos);
	if(pos == -1) return 0;
	strcpy(L->lista[pos].nome, nome);
	L->lista[pos].ddd = ddd;
	L->lista[pos].tel = tel;
	L->lista[pos].id = L->Nelem++;
	L->lista[pos].null = 0;
	return 1;
}

int remover(listaHash *L, char nome[]){
	int pos = hash(nome);
	while(!L->lista[pos].null){
		if(!strcmp(nome, L->lista[pos].nome)){
			L->lista[pos].ddd = 0;
			L->lista[pos].tel = 0;
			L->lista[pos].id = -1;
			L->lista[pos].null = 1;
			L->Nelem--;
			return 1;
		}	pos = rehash(pos);
	}	return 0;
}

int buscaNome(listaHash *L, char nome[]){
	int pos = nome[0] - 97;
	while(!L->lista[pos].null){
		if(!strcmp(nome, L->lista[pos].nome))
			return pos;
		pos += 26;
	}	return -1;
}

int buscaId(listaHash *L, int id){
	int i;
	for(i = 0; i < TAM * 26; i++){
		if(!L->lista[i].null && L->lista[i].id == id)
			return i;
	}	return -1;
}

void printa(listaHash *L){
	int i, j;
	for(i = 0; i < 26; i++){
		for(j = i; !L->lista[j].null; j += 26)
			printf("%d: %s\t%d\t%ld\n",  L->lista[j].id, L->lista[j].nome,  L->lista[j].ddd,  L->lista[j].tel);
	}
}

int main(){
	listaHash L;
	definir(&L);
	int pos;
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

	pos = buscaNome(&L, "tyr");
	if(pos != -1)
		printf("%d: %s\t%d\t%ld\n\n", L.lista[pos].id, L.lista[pos].nome, L.lista[pos].ddd, L.lista[pos].tel);
	pos = buscaId(&L, 3);
	if(pos != -1)
		printf("%d: %s\t%d\t%ld\n\n", L.lista[pos].id, L.lista[pos].nome, L.lista[pos].ddd, L.lista[pos].tel);

	remover(&L, "fsd");
	printa(&L);
}
