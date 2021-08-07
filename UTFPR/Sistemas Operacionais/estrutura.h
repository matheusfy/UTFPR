#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

typedef struct{
  int cont;
  sem_t mutex;
  sem_t comida;
  sem_t cozinha;
  sem_t enchendo;
}Shared_Memory;

#define ADDKEY 1234
#define M 16
#define Gaules 7
#define path "/home/matheus/SO/Exemplos"
