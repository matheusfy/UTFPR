#include "estrutura.h"

Shared_Memory *sm;

int main (void)
{
  int shmid;
  int flag = 0;
  key_t key = ftok("path", ADDKEY);
  // busca zona da memoria compartilhada
    shmid = shmget(key, sizeof(Shared_Memory), IPC_CREAT|SHM_R|SHM_W);

  if(shmid == -1)  // Deu erro
  {
    perror("Erro no shmget");
    exit(1);
  }
  // liga a zona da memoria compartilhada
  sm = (Shared_Memory*)shmat(shmid, NULL, flag);

  // inicializar semafaro
  sem_init(&(sm->comida), 1, M+1);
  sem_init(&(sm->mutex),1,1);
  sem_init(&(sm->enchendo),1,0);
  sem_init(&(sm->cozinha),1,0);
  sm->cont = 0;
  // printf("%d\n",shmid);

  pid_t pid;

  if((pid = fork()) == 0)
  {
    execl("Cozinheiro", NULL);
  }else
  {

    if((pid=fork())==0)
    {
      execl("Gaules", NULL);
    }
  }
  pid_t child;

        child = wait(NULL);
    if((child == -1)&& (errno != EINTR))
    {
      break;
    }


  shmctl(shmid, IPC_RMID, NULL); //Destruindo ou desalocando o segmento de memoria
}
