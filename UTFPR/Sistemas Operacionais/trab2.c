#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
  int contagem = 0; // variavel globa de contagem

  // AUMENTA A CONTAGEM TODA VEZ QUE APERTA CTRL_C
void trata_CTRL_C() {
      contagem = contagem +1;
      printf("\n" );
    }

    // RECEBE O SINAL ENVIADO QUANDO APERTA CTRL Z E MOSTRA A QUANTIDADE DE CTRL_C APERTADO.
void trata_CTRL_Z() {
    printf("contagem = %d\n", contagem);
}

int main(void)
{
  char opcao;

      while(1)   //entra e fica no looṕ
      {

        signal (SIGINT, trata_CTRL_C); // quando apertar crtl-c entra no tratamento.
        signal (SIGTSTP, trata_CTRL_Z); // entra no tratamento do crtl-z.
        alarm(0); // cancela a chamada previa da contagem para a saida do programa.
        if(contagem == 10)
        {
          printf("---- crtl-c apertado 10 vezes, deseja sair?(y/n): ");
          printf("\n----- comecando contagem ----------\n" );
          alarm(5); // comeca a contagem para sair do programa.
          scanf(" %s",&opcao);
          if(opcao == 'y')
          {
                exit(0); // SAI DO PROCESSO
          }
          else if(opcao == 'n')
          {
            printf("------ contagem resetada  -----------\n" );
            contagem = 0;
          }
        }

      }
    return 0;
}
