#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>

#define M 16 // 16376 73
#define N 7 // > matheus

sem_t cozinha;
sem_t comida;
sem_t mutex;
sem_t enchendo;

int Javali = M;
int cont = 0;
void Cozinheiro(void* t);
void *Gaules(void* id);
void RetiraJavali(long i);
void Colocajavali(long i);

int main (void)
{
    sem_init(&comida,0,M+1);
    sem_init(&mutex,0,1);
    sem_init(&cozinha,0,0);
    sem_init(&enchendo,0,0);

    pthread_t Gauleses[N];
    long t;
    for(t=0; t<N; t++)
    {
      pthread_create(&Gauleses[t],NULL,Gaules,(void*)t);
    }

    for(t=0; t<N; t++)
    {
      pthread_join(Gauleses[t],NULL);
    }

    sem_destroy(&cozinha);
    sem_destroy(&comida);
    sem_destroy(&mutex);
    sem_destroy(&enchendo);
}

void *Gaules(void* id)
{
  long t = (long) id;
  while(1)
  {
    sem_wait(&comida);
    printf("Gaules %ld esta com fome\n", t);
    sem_wait(&mutex);
    sleep(1);
    cont++;
    if(cont>M)
    {
      sem_post(&cozinha);
      Cozinheiro(id);
      sem_wait(&enchendo);
      cont = 1;
    }
    sem_post(&mutex);
    RetiraJavali(t);
    printf("Gaules %ld terminou de comer\n", t);
  }
}

void Cozinheiro(void* t)
{
  long id = (long)t;

    sem_wait(&cozinha);
    Colocajavali(id);
    for(int i=0;i<M; i++)
    {
      sem_post(&comida);
    }
    sem_post(&enchendo);
}

void RetiraJavali(long i)
{
  if(i==0)
  {
    printf("Gaules m(%ld) retirou um javali e esta comendo \n", i);
  }else if(i==1)
  {
    printf("Gaules a(%ld) retirou um javali e esta comendo \n", i);
  }else if(i==2)
  {
    printf("Gaules t(%ld) retirou um javali e esta comendo \n", i);
  }else if(i==3)
  {
    printf("Gaules h(%ld) retirou um javali e esta comendo \n", i);
  }else if(i==4)
  {
    printf("Gaules e(%ld) retirou um javali e esta comendo \n", i);
  }else if(i==5)
  {
    printf("Gaules u(%ld) retirou um javali e esta comendo \n", i);
  }else if(i==6)
  {
    printf("Gaules s(%ld) retirou um javali e esta comendo \n", i);
  }
  sleep(rand()%3);
}

void Colocajavali(long i)
{
  if(i==0)
  {
    printf("Gaules m(%ld) acordou o cozinheiro\n", i);
  }else if(i==1)
  {
    printf("Gaules a(%ld) acordou o cozinheiro\n", i);
  }else if(i==2)
  {
    printf("Gaules t(%ld) acordou o cozinheiro\n", i);
  }else if(i==3)
  {
    printf("Gaules h(%ld) acordou o cozinheiro\n", i);
  }else if(i==4)
  {
    printf("Gaules e(%ld) acordou o cozinheiro\n", i);
  }else if(i==5)
  {
    printf("Gaules u(%ld) acordou o cozinheiro\n", i);
  }else if(i==6)
  {
    printf("Gaules s(%ld) acordou o cozinheiro\n", i);
  }
  sleep(4);
  Javali = M;
  printf("O cozinheiro Terminou de repor os Javalis\n");

  }
