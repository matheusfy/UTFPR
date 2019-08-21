#include "informacao.h"
int main (int argc, char *args[])
{
      char buf[M];
      channel = atoi(args[0]);
      int valor = 0;
      sleep(5);
      while(1)
      {
        // valor= atoi(buf);
        // printf("buffer C: %d\n",valor );

          for(int i=0; i<M;i++)
          {
            write(channel,buf,M);
          }
          printf("Cozinheiro terminou de cozinhar!\n");
          // printf("cozinheiro dormiu\n");
          sleep(20);
      }
}
