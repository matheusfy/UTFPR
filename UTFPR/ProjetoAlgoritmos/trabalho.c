#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "estrutura.h"
#include "Grafo.h"
#include "busca.h"
void readArchive(Grafo *G, char nome[]);

/******************** IMPLEMENTACAO DO METODO GULOSO PARA COBERTURA MINIMA DE VERTICES **************************/

int main (int argc, char *argv[])
{
  Grafo G;
  Define(&G);
  char nome[20];
  printf("coloque aqui o nome do arquivo\n");
  scanf(" %s", &nome);
  readArchive(&G,nome);
  visualizarGrafo(&G);
  int vetor[G.numV];
  for(int i = 0; i < (int)sizeof(vetor)/sizeof(vetor[0]); i++)
  {
    vetor[i] = 0;
  }
  guloso(&G,vetor);
  for(int i = 0; i < (int)sizeof(vetor)/sizeof(vetor[0]); i++)
  {
    printf("%d ", vetor[i]);
  }

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
              // printf("frstvalue = %d, scondvalue = %d\n", fvalue ,svalue ); // printi para ver se estava armazenando na variavel os valores corretamente
              inserirAresta(G, fvalue, svalue);
              firstvalue = false; // reseta flags e volta para a primeira condicao onde comecam as linhas
              secondvalue = false;
            }
            i = 0;
        }
      }
fclose(arq_palavras);
}
