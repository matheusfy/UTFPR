#include "estrutura.h"

Shared_Memory *sm;
pthread_t thread[Gaules];

void* Cozinheiro(void *t)
{
  long id = (long)t;

    sem_wait(&(sm->cozinha));
    printf("Gaules %ld pediu para repor javali\n", id);
    sleep(4); // repondo javali
    for(int i=0;i<M; i++)
    {
      sem_post(&(sm->comida));
    }
    sem_post(&(sm->enchendo));
}

int main (void)
{
 key_t key;
 int shmid;
 int flag = 0;

 key = ftok("path",ADDKEY);

 shmid =  shmget(key, sizeof(Shared_Memory), IPC_CREAT|SHM_R|SHM_W);
 sm    =  (Shared_Memory*)shmat(shmid, NULL, flag); //attach
 // printf("%d\n",shmid);

 long t;
 for(t=0; t<Gaules; t++)
 {
   pthread_create(&thread[t],NULL, Cozinheiro, (void*)t );
 }

 for(t=0; t<Gaules; t++)
 {
   pthread_join(thread[t],NULL);
 }
 return 0;
}
