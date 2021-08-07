#include "estrutura.h"
#include <time.h>
Shared_Memory *sm;
pthread_t thread[Gaules];

 // shmget() - cria zona de memoria compartilhada
 // shmat() - liga zona de memoria compartilhada
 // shmdt() - desliga zona de memoria compartilhada
 // shmctl() - desaloca memoria compartilhada ou controla o acesso a zona de memoria compartilhada
 void *Gauleses(void* id)
 {
   long t = (long) id;
   while(1)
   {
     sleep(rand()%5);
     printf("Gaules %ld esta com fome\n", t);
     sem_wait(&sm->comida);
     // printf("eu sou gaules %ld \n", t);
     sem_wait(&sm->mutex); // esperando para retirar
     sm->cont++;
     if(sm->cont>M)
     {
       sem_post(&sm->cozinha);
       sem_wait(&sm->enchendo);
       sm->cont = 1;
       printf("Cozinheiro terminou de repor Javalis na mesa\n" );
     }
     sem_post(&sm->mutex); // retirou o prato
     printf("Gaules %ld retirou javali da mesa\n", t);
     sleep(5);
     printf("Gaules %ld terminou de comer\n", t);
   }
 }

int main (void)
{
  key_t key;
  int shmid;
  int flag = 0;

  key = ftok("path",ADDKEY);
  shmid =  shmget(key, sizeof(Shared_Memory), IPC_CREAT|SHM_R|SHM_W);
  sm    = (Shared_Memory*)shmat(shmid, NULL, flag); //attach
  // printf("%d\n",shmid);

  long t;

  for(t=0; t<Gaules; t++)
  {
    pthread_create(&thread[t],NULL, Gauleses, (void*)t );
  }
  for(t=0; t<Gaules; t++)
  {
    pthread_join(thread[t],NULL);
  }
  return 0;
}
