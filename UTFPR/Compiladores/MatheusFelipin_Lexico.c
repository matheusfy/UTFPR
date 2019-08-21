#include "estrutura.h"

int main (int argc, char *argv[])
{

  Lista palavras;                      //cria fila
  Definir(&palavras);                 //define fila
  no *aux;
  FILE *arq_palavras;
  char ch;
  char v[60];
  int i=0, flag=0;
  int linha = 1;
  arq_palavras = fopen("palavras.txt", "rt"); // abre o arquivo txt
    while((ch = fgetc(arq_palavras)) != EOF) // verificaçao enquanto não é o final do arquivo
      {
        if(ch != 10 && ch != 32) // passa caracter por caracter ate encontrar um espaço ou quebra de linha
        {
          v[i] = ch;
          i++;
        }
        else if( ch == 10 || ch == 32  ) // verifica se espaço ou quebra de linha
        {
            v[i] = '\0';                  // atribuir fim da palavra
            if(v[0] == '{' && flag == 0) // verifica se é inicio de comentario
            {
              flag = 1;
            }
            else if(v[0] == '}' && flag == 1) // verifica se é termino de um comentario
            {
              flag = 0;
            }
            if(flag == 0 )
            {
              aux = malloc(sizeof(no));  // alocamento de espaço na memória para o nó
              aux->linha = linha;
              aux->info[0] = '\0';
              *aux = compara(v,aux); // recebe nó tratado na funcao
              if(aux->info[0] != '\0') // se é palavra reservada entao insere na lista de tokens
              {
                Inserir(&palavras, aux); // insere no na lista
              }
            }


            i = 0;
            if(ch == 10) // quando encontrado um \n aumenta o numero da linha
            {
              linha = linha + 1;
            }
        }
      }
fclose(arq_palavras);
imprimir(&palavras);
  /**********PARTE SINTATICA *******/
  
return 0;
}
