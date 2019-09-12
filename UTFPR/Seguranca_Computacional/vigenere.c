#include <stdio.h>

int main(void)
{
    FILE *arq_palavras;
    arq_palavras = fopen("entrada.txt", "rt"); // abre o arquivo txt

    char ch;
    char v[10000];
    int i=0, flag=0;


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
            i = 0;
        }
    }
    fclose(arq_palavras);

    printf("%s\n", v);
}
