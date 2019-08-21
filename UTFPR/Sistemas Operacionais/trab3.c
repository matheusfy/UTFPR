#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <math.h>

#define NUM_THREADS 1
double tamanho = 1000000000/NUM_THREADS;
double result[NUM_THREADS],valorPI=0;


void* calculopi(void* threadid) // calcula o valor parcial de pi
{

    long thread; // declaraçao de variavel tipo long
    thread = (long)threadid;// thread 0,1,2 ...
    int i = 0;
    for(i = (tamanho*thread); i<(thread+1)*tamanho; i++) // se 2 threads a primeira faz metade e a outra faz a outra metade
    {
      if( i%2 == 0)
      {
        result[thread]=result[thread] + 4/(2*i+1);
      }
      else
      {
        result[thread] = result[thread] - 4/(2*i+1);
      }
    // result[thread]=result[thread] + 4*(pow(-1,i)/(2*i+1)); // multiplicado por quado pq a somatoria final é pi/4 e queremos o valor do pi
    }
  pthread_exit(NULL);
}

void CalculaSoma()  //soma todas parciais que ta em cada thread
{
    for (int i = 0; i < NUM_THREADS; i++)
   {
      valorPI = valorPI + result[i];
    }
}

int main (void)
{
  printf("numero de threads %d : \n", NUM_THREADS );
  pthread_t threads[NUM_THREADS];
  long   t;
  time_t tini , tfim;
  float tempo;
  tini = time(NULL);

  for(t=0; t<NUM_THREADS; t++)
  {
    pthread_create(&threads[t], NULL, calculopi,(void*)t); // t = argumento passado, NULL nenhum atributo para o objeto
  }

  for (t= 0;  t < NUM_THREADS; t++)
  {
    pthread_join(threads[t], NULL);  // threads[t] a thread que ta esperando, outro parametro null pq nao tem valor retornado pela thread acordada
  }

  CalculaSoma();

  tfim = time(NULL);
  tempo = difftime(tfim,tini);
  printf("valor de pi : %.8f \n", valorPI );
  printf("Tempo de execuçao = %f \n",tempo );

    pthread_exit(NULL);

}
