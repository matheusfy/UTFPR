#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "estrutura.h"
#include "Grafo.h"
int main (int argc, char *argv[])
{

               //define fila

  FILE *arq_palavras;
  char ch;
  char v[60];
  int i=0, flag=0, vertexnumber = 0, fvalue = -1, svalue = -1;
  bool firstline = false, vertex = false, endofline = false, firstvalue = false, secondvalue = false;

  Grafo G;
  Define(&G);

  arq_palavras = fopen("numero.txt", "rt"); // abre o arquivo txt
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
            else if(v[0] != 'p' && firstline == true && vertex == false)
            {

              if(strcmp(v,"edge")) // verifica se passou pela palavra para inserir quantidade de vertices vertices
              {
                vertex = true;
              }
              int numVertex = atoi(v);
              for(int j=1; j <= numVertex; j++)
              {
                inserirVertice(&G,j);
              }

            }
            else if(vertex == true && firstline == true)
            {
              firstline = false;
              // printf("primeiro\n" );
            }

            // A partir da segunda linha
            if(v[0] == 'e' && firstline == false)
            {
              //  inserindo arestas
              firstvalue = true;
            }
            else if(firstvalue == true && secondvalue == false)
            {
              fvalue = atoi(v);
              secondvalue = true;
            }
            else if(firstvalue == true && secondvalue == true)
            {
              svalue = atoi(v);
              printf("frstvalue = %d, scondvalue = %d\n", fvalue ,svalue );
              inserirAresta(&G, fvalue, svalue);
              firstvalue = false;
              secondvalue = false;
            }
            i = 0;
        }
      }
fclose(arq_palavras);
visualizarGrafo(&G);
return 0;
}
