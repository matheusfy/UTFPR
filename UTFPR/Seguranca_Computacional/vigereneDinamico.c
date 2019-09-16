#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NoTag
{
    char letra;  // caracter do arquivo
    double peso;
    int indice;
    struct NoTag *prox;
} no;
typedef struct
{
    no *inicio;
    no *fim;
    int nelem;
} Lista;

void Definir(Lista*L)
{
    L->inicio = NULL;
    L->fim = NULL;
    L->nelem = 0;
}

void Inserir(Lista*L, no *novo)   // insere nó na ultima posicao
{
    if(L->inicio == NULL)
    {
        novo->prox= NULL;
        L->inicio = novo;
        L->fim = novo;
        L->nelem++;
    }
    else
    {
        novo->prox = NULL;
        L->fim->prox = novo;
        L->fim = novo;
        L->nelem++;
    }

}

void listar(Lista *L)
{
  no *p;
  p = L->inicio;

  while(p != NULL)
  {
    printf("%c", p->letra);
    p = p->prox;
  }
}


void readTexto(Lista *texto);
void readPeso(Lista *Peso);
void tamanhoChave(Lista *texto);
void contaLetra(Lista *texto, double vletra[], int indice);
void listaFreqtext(Lista *freq, double vletra[], double total);
void calculate(Lista *peso, Lista *freq, char palavra[], int posicao);

void shift(Lista *L)
{
  no* init;
  no *final;
  init = L->inicio;

  L->inicio = init->prox;
  init->prox = NULL;

  L->fim->prox = init;
  L->fim = init;

}

void exclude(Lista *L)
{
  no* aux;
  while(L->inicio != NULL && L->fim != NULL)
  {
    if(L->inicio != L->fim)
    {
      aux = L->inicio;
      L->inicio = L->inicio->prox;
      aux->prox = NULL;
    }
    else
    {
      aux = L->inicio;
      aux->prox = NULL;
      L->inicio = NULL;
      L->fim = NULL;
    }
    free(aux);
    L->nelem--;
  }
}

int main(void)
{

      Lista texto;
      Lista peso;
      Lista freq;
      Definir(&texto);
      Definir(&peso);
      Definir(&freq);
      readTexto(&texto); // coloca em uma lista encadeada o texto
      readPeso(&peso); // coloca os pesos em um lista encadeada
      printf("numero de elementos no arquivo %d \n", texto.nelem);
      tamanhoChave(&texto); // COLOCA EM UM ARQUIVO DE SAIDA E ANALISAR O TAMANHA DA CHAVE
      double vletra[26];
      char chave[5]; // SABENDO QUE A PALAVRA EM TAMANHO 5

      for(int indice = 0; indice<5; indice++) // FOR ATE O TAMANHO DA PALAVRA
      {
        contaLetra(&texto, vletra, indice); // CONTA A LETRA NO INDICE X
        double total = 0;
        for(int z = 0; z < 26;   z++) // FOR PARA SOMAR O TOTAL DE CARACTERES
        {
          total += vletra[z];
        }
        listaFreqtext(&freq, vletra, total); // LISTA DE FREQUENCIA DE CADA LETRA cria lista de frequencia naquele indice
        calculate(&peso, &freq, chave, indice); // passa a lista de pesos e a de frequencia com que cada letra aparece no indice x e passa o vetor de chave
        exclude(&freq); // exclui a lista
      }
      printf("chave encontrada: %s\n", chave);
 /********************** ATE AQUI É O CODIGO PARA ENCONTRAR A CHAVE*********/

      int msgLen = texto.nelem, keyLen = strlen(chave), i = 0, j;
      char msg[msgLen];
      char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];
      no *aux;
      aux = texto.inicio;
      while(aux!=NULL)
      {
        encryptedMsg[i] = aux->letra;
        i++;
        aux = aux->prox;
      }
      // printf("%s\n", encryptedMsg);
      for(i=0,j=0; i < msgLen; i++, j++) // cria chave do tamanho do texto
      {
        if(j==keyLen)
        {
          j = 0;
        }
        newKey[i] = chave[j];
      }
      newKey[i] = '\0';
      // descriptografa o texto
      for(i = 0; i < msgLen; ++i)
      {
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
      }
      decryptedMsg[i] = '\0';

      printf("%s\n", decryptedMsg);
}


void calculate(Lista *peso, Lista *freq, char palavra[], int posicao)
{
  double result = 0;
  double resultant = 0;
  int indice = 0;
  no *auxPeso;
  no *auxfreq;
  for(int i = 0; i<26; i++)
  {
    auxPeso = peso->inicio;
    auxfreq = freq->inicio;
    while(auxPeso != NULL && auxfreq != NULL) // MULTIPLICACAO DOS INDICES
    {
      result += auxPeso->peso*auxfreq->peso;
      auxPeso = auxPeso->prox;
      auxfreq = auxfreq->prox;
    }
    if(result > resultant) // IF PARA ENCONTRAR O INDICE(LETRA) QUE APARECE COM MAIS FREQUENCIA
    {
      resultant = result;
      indice = i;
    }
    // printf("result: %d , %f\n", i, result);
    result = 0;
    shift(freq); // JOGA A PRIMEIRA LETRA PARA O FINAL
  }
    printf("resultado final %f, indice: %c\n", resultant, indice+97);
    palavra[posicao] = indice+97;
}

void listaFreqtext(Lista *freq, double vletra[], double total)
{
  for(int i=0; i<26; i++)
  {
    no *aux;
    aux = malloc(sizeof(no));
    aux->peso = vletra[i]/total;
    aux->indice = i;
    aux->letra = i+97;
    Inserir(freq,aux);
  }
}

void contaLetra(Lista *texto, double vletra[], int indice) // conta letra no indice x
{
  int i=0, cont;
  int j;
  char letra;
  no *aux;
  aux = texto->inicio;

  for(int z = 0; z < 26; z++) //zera vetor
  {
    vletra[z] = 0;
    // printf("vetor %f, indice: %d\n", vletra[z], z);
  }

  {
    for(j=0; j<indice; j++) // for para deslocar o ponteirp o ponteiro
    aux = aux->prox;
  }

  printf("comeco: %c\n", aux->letra);
  while(aux != NULL) // conta quantas vezes uma letra aparece no comeco da palavra
  {
    if(i==0)
    {
        cont = 0;
        letra = aux->letra;
        i++;
    }
    else if(i >=4) // tamanho da palavra
    {
      i = 0;
    }
    else
    {
      if(letra == aux->letra)
      {
        vletra[letra-97]++;
        cont++;
      }
      i++;
    }
    aux = aux->prox;
  }
}

void tamanhoChave(Lista *texto)     // arquivo da saida com resposta
{
  FILE *fptr;
  fptr = fopen("saida.txt", "w");
  no *aux1, *aux2;
  no *estatico;
  estatico = texto->inicio;
  int cont = 0;
  // encontra tamanha da key
  while(estatico != NULL)
  {
    aux1 = texto->inicio;
    aux2 = estatico->prox;
    while(aux2 != NULL)
    {
      if(aux1->letra == aux2->letra)
      {
        cont++;
      }
      aux1 = aux1->prox;
      aux2 = aux2->prox;
    }
    estatico = estatico->prox;
    fprintf(fptr, "linha x palavras repetidas: %d\n", cont);
    cont = 0;
  }
  fclose(fptr);
}

void readTexto(Lista *texto) // funcao para ler arquivo e colocar em uma lista encadeada
{
  no *aux;
  FILE *arq_texto;
  char ch;
  int i =0;
  arq_texto = fopen("entrada.txt", "rt"); // abre o arquivo txt
  while((ch = fgetc(arq_texto)) != EOF) // verificaçao enquanto não é o final do arquivo
  {

      if(ch != 10 && ch != 32) //  passa caracter por caracter ate encontrar um espaço ou quebra de linha
      {
        aux = malloc(sizeof(no));
        aux->letra = ch;
        aux->indice = i;
        Inserir(texto,aux);
        i++;
      }
      else if( ch == 10 || ch == 32  ) // verifica se espaço ou quebra de linha
      {
          // printf("end of file\n");// atribuir fim da palavra
          i = 0;
      }
  }
  fclose(arq_texto);
}

void readPeso(Lista *Peso) // funcao para importar pesos
{
  no *aux;
  FILE *arq_peso;
  int i = 0, indice = 0;
  char v[10];
  char letra,ch;
  float valor;
  arq_peso = fopen("pesosordem.txt", "rt"); // abre o arquivo txt
  int flag = 0;
  while((ch = fgetc(arq_peso)) != EOF) // verificaçao enquanto não é o final do arquivo
  {

      if(ch != 10 && ch != 32) //  passa caracter por caracter ate encontrar um espaço ou quebra de linha
      {
        v[i] = ch;
        i++;
      }
      else if( ch == 10 || ch == 32  ) // verifica se espaço ou quebra de linha
      {
          v[i] = '\0';

          if(flag == 0)
          {
            letra = v[0];
            flag = 1;
          }
          else
          {
            aux = malloc(sizeof(no));
            aux->letra = letra;
            aux->peso = atof(v);
            aux->indice = indice;
            Inserir(Peso, aux);
            indice++;
            flag = 0;
          }

          i = 0;
          // printf("end of file\n");// atribuir fim da palavra
      }
  }
  fclose(arq_peso);

}
