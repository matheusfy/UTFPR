/*
    UNIVERSIDADE TECNOLÓGICA FEDERAL DO PARANÁ
    ACADÊMICO : MATHEUS FELIPIN YOKOYAMA
    DISCIPLINA : PROJETO DE ALGORITMOS
    -----------TRABALHO 1--------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Grafo.h"
#include "busca.h"
void readArchive(Grafo *G, char nome[]);

/******************** IMPLEMENTACAO DO METODO GULOSO PARA COBERTURA MINIMA DE VERTICES **************************/

int main (int argc, char *argv[])
{
  Grafo G; // cria grafo
  Define(&G); // define grafo

  char nome[20];
  int solucao =1;
  FILE *fptr;
  fptr = fopen("tabela.txt", "w"); // abre o arquivo tabela em modo escrita para escrever resultados

  printf("digite: nomeArquivo.tipo\n"); // arquivos que contem as instancias de entrada
  scanf(" %s", &nome);
  readArchive(&G,nome); // ler arquivo de entrada

  int vetor[G.numV]; // cria vetor para armazenar a resposta
  for(int i = 0; i < (int)sizeof(vetor)/sizeof(vetor[0]); i++)
  {
    vetor[i] = 0;
  }
  double tempo;
  fprintf(fptr, "entrada: %s\n", nome); // escreve o nome da entrada no txt

  // for(int i = 0; i<12; i++)
  // {
    guloso(&G, vetor, &tempo); // metodo guloso para entrada
    int vconjunto = 0;
    for(int i = 0; i < (int)sizeof(vetor)/sizeof(vetor[0]); i++)
    {
      if(vetor[i] == 1)
      {
        fprintf(fptr, "%d ", i+1); // escreve no arquivo os vertices que foram pintados
        vconjunto++;
      }
    // }

    fprintf(fptr, "\n----------- solucao %d, MVC: %d, tempo = %lf -----------\n", solucao++,vconjunto, tempo);
  }

  fclose(fptr); // fecha arquivo tabela
  return 0;
}

void readArchive(Grafo *G, char nome[])
{
  FILE *arq_palavras;
  arq_palavras = fopen(nome, "rt"); // abre o arquivo txt

  char ch;
  char v[60];
  int i=0, flag=0, vertexnumber = 0, fvalue = -1, svalue = -1, x= 0;
  bool firstline = false, vertex = false, endofline = false, firstvalue = false, secondvalue = false;


    while((ch = fgetc(arq_palavras)) != EOF) // verificaçao enquanto não é o final do arquivo
    {

        if(ch != 10 && ch != 32) //  passa caracter por caracter ate encontrar um espaço ou quebra de linha
        {
          v[i] = ch;
          i++;
        }
        else if( ch == 10 || ch == 32  ) // verifica se espaço ou quebra de linha
        {
            v[i] = '\0';                  // atribuir fim da palavra

            if(v[0] == 'p') // primeira linha
            {
              firstline = true;
            }
            else if(strcmp(v,"edge") && firstline == true && vertex == false)
            {

              vertex = true;
              int numVertex = atoi(v);
              // printf("numeros de vertices : %d\n", numVertex);
              for(int j=1; j <= numVertex; j++)
              {
                inserirVertice(G,j);
              }
            }
            else if(vertex == true && firstline == true) // garante que saiu da primeira linha
            {

              firstline = false;
            }

            // A partir da segunda linha
            if(v[0] == 'e' && firstline == false)
            {
              //  inserindo arestas
              firstvalue = true;
            }
            else if(firstvalue == true && secondvalue == false) // condicao para garantir o primeiro valor depois do 'e'
            {
              fvalue = atoi(v);
              secondvalue = true;
            }
            else if(firstvalue == true && secondvalue == true) // condicao para garantir o segundo valor
            {
              svalue = atoi(v);
              inserirAresta(G, fvalue, svalue);
              firstvalue = false; // reseta flags e volta para a primeira condicao onde comecam as linhas
              secondvalue = false;
            }
            i = 0;
        }
      }
fclose(arq_palavras);
}
