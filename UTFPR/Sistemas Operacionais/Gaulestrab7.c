#include "informacao.h"

int main(int argc, char *args[])
{
    char buf[M];
    int cont=0;
    id = atoi(args[1]);
channel = atoi(args[0]);

    while(1)
    {
        read(channel,buf,M);
        printf("O Gaules %d retirou Javali\n", id);
      sleep(1);
      // printf("O Gaules %d acaba de comer o Javali\n", id);
    }

}
