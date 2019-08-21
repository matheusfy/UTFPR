#include <omp.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <semaphore.h>
#include <mpi.h>
#include <string.h>
#include <stdio.h>

#define Gaules 7
#define M 16

int main(int argc, char **argv)
{
  int rank,size,tag,i=1, comida=0;
  MPI_Status status;
  char msg[200];
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  int myid;
    if(rank==0)
    {
        while(1)
        {
          for(int j=0; j<M;j++)
            MPI_Send(&msg,sizeof(msg),MPI_CHAR,1,0,MPI_COMM_WORLD);
          sleep(1);
          MPI_Recv(msg,sizeof(msg),MPI_CHAR,1,0,MPI_COMM_WORLD, &status);
          printf("cozinhando\n");
        }// strcpy(msg, "Hello World!");
    }
    else
    {
        omp_set_num_threads(Gaules);
        #pragma omp parallel
        {
          while(1)
          {
            myid = omp_get_num_threads();
            if(myid<=Gaules)
            {
              #pragma omp critical
              {
                MPI_Recv(msg,sizeof(msg),MPI_CHAR,0,0,MPI_COMM_WORLD, &status);
                printf("Gaules %d retirou comida : %d\n", omp_get_num_threads(), i );
              }
                // printf("i\n", );
              // cont++;
              if(i==M)
              {
                printf("Gaules %d acordou o cozinheiro\n", omp_get_num_threads() );
                MPI_Send(&msg,sizeof(msg),MPI_CHAR,0,0,MPI_COMM_WORLD);
                i =0;
              }
              // printf("%d\n",i );
              i++;

            }

              // printf("Gaules: %d recebeu comida\n", rank);
          }
        }
      }

  MPI_Finalize();
  return 0;
}
