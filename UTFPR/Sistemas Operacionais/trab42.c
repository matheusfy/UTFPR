#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

sem_t S1;
sem_t S2;
sem_t S3;

void* thread(void* arg)
{
  long t;
    int i=0;
    int x=0;
     t = (long)arg;
    x = 1 + (rand()%5);

    if(t == 65)
    {

      printf("\nThread A criada");
      printf("\nEntrou em .. A");
      printf("\ntempo : %ds", x);
      sleep(x);
      printf("\nSaiu de  .. A");
      sem_post(&S1);
    }else if(t == 66)
    {
      printf("\nThread B criada");
      printf("\nEntrou em ..B");
      printf("\ntempo : %ds", x);
      sleep(x);
      printf("\nSaiu de  ..B");
      sem_post(&S2);
    }else if(t == 67)
    {

      printf("\nThread C criada");
      sem_wait(&S2);
      printf("\nEntrou em .. C");
      printf("\ntempo : %ds", x);
      sleep(x);
      printf("\nSaiu de  .. C");
      sem_post(&S3);
      sem_post(&S3)
    }else if(t == 68)
    {

      printf("\nThread D criada");
      sem_wait(&S3);
      printf("\nEntrou em .. D");
      printf("\ntempo : %ds", x);
      sleep(x);
      printf("\nSaiu de  .. D");
    }else if(t == 69)
    {

      printf("\nThread E criada");
      sem_wait(&S3);
      printf("\nEntrou em .. E");
      printf("\ntempo : %ds", x);
      sleep(x);
      printf("\nSaiu de  .. E\n" );

    }
    pthread_exit(NULL);
}


int main()
{

    sem_init(&S1,0,0);
    sem_init(&S2,0,0);
    sem_init(&S3,0,0);

    pthread_t threads[5];
    long   t;
    for(t = 65; t<70; t++)
    {
      pthread_create(&threads[t], NULL, thread,(void*)t);
    }
      for(t=65; t<70; t++)
      {
        pthread_join(threads[t], NULL);
      }

    sem_destroy(&S1);
    sem_destroy(&S2);
    sem_destroy(&S3);

    return 0;
}
