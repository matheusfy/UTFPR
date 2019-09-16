#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    FILE *arq_palavras;
    arq_palavras = fopen("entrada.txt", "rt"); // abre o arquivo txt

    char ch;
    char encryptedMsg[10000];
    int i=0, flag=0;


    while((ch = fgetc(arq_palavras)) != EOF) // verificaçao enquanto não é o final do arquivo
    {

        if(ch != 10 && ch != 32) //  passa caracter por caracter ate encontrar um espaço ou quebra de linha
        {
          encryptedMsg[i] = ch;
          i++;
        }
        else if( ch == 10 || ch == 32  ) // verifica se espaço ou quebra de linha
        {
            encryptedMsg[i] = '\0';                  // atribuir fim da palavra
            i = 0;
        }
    }
    fclose(arq_palavras);
    //
    // char key[] = "COMPUTER";
    int msgLen = strlen(encryptedMsg);
    char encrypCopy[msgLen],newKey[msgLen], decryptedMsg[msgLen];
    *encrypCopy = *encryptedMsg;
    int j;
    // for(i = 0, j= 0; i < msgLen; ++i, ++j)
    // {
    //   if(j == keyLen)
    //       j = 0;
    //
    //   newKey[i] = key[j];
    // }
    //   newKey[i] = '\0';
    //
    // for(i = 0; i < msgLen; ++i)
    //     decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    //
    // decryptedMsg[i] = '\0';
    // printf("mensagem descriptografada: %s\n", decryptedMsg);

    FILE *fptr;
    fptr = fopen("saida.txt", "w");
    for(j = 1; j<msgLen; j++)
    {
      int cont = 0;
      for(int i=j; i<msgLen; i++)
      {
        if(encryptedMsg[i-j] == encrypCopy[i]) cont++;
      }
      if(cont > 5)
      {
        fprintf(fptr, "x: %d\n", cont);
      }
    }
    fclose(fptr); // fecha arquivo tabela

}
