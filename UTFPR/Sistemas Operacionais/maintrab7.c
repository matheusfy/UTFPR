#include "informacao.h"

//Processo filho envia dados para o processo pai

int main()
{
   int n, fd1[2];
   // int fd2[2];
   pid_t pid;
   pipe(fd1);
   // pipe(fd2);

   int id=0;
   if (pipe(fd1)<0)
   {
      fprintf(stderr,"Erro no tubo\n");
      _exit(1);
   }
   //
   // if (pipe(fd2)<0)
   // {
   //    fprintf(stderr,"Erro no tubo\n");
   //    _exit(1);
   // }

   if ((pid=fork())<0)
   {
      fprintf(stderr,"Erro no fork\n");
      _exit(1);
   }
   // Gaules
   for(int i=1; i<=Gaules; i++)
   {
     if((pid = fork()) == 0)
     {
       char channel[2], id[Gaules];
       close(fd1[WRITE]);
       sprintf(id,"%d",i);
       sprintf(channel,"%d",fd1[READ]);
       execl("./Gaulestrab7",channel, id, NULL);
     }
   }
   //cozinha
   if((pid=fork()) == 0)
   {
     char channel[2];
     close(fd1[READ]);
     sprintf(channel,"%d",fd1[WRITE]);
     execl("./Cozinheirotrab7", channel, NULL);
   }

   pid_t child;
   for(;;)
   {
     child = wait(NULL);
   }
   exit(0);

}
