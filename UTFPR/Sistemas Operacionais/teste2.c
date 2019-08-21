#include <mpi.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
  int rank,size,tag,i, comida=0;
  MPI_Status status;
  char msg[200];
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  while(1)
  {
    if(rank==0)
    {
      // strcpy(msg, "Hello World!");
        MPI_Send(&msg,sizeof(msg),MPI_CHAR,1,tag,MPI_COMM_WORLD);
        comida++;
        sleep(1);
      MPI_Recv(msg,sizeof(msg),MPI_CHAR,1,tag,MPI_COMM_WORLD, &status);
      //
      printf("cozinhando\n");
    }else
    {
      MPI_Recv(msg,sizeof(msg),MPI_CHAR,0,tag,MPI_COMM_WORLD, &status);
      printf("Gaules: %d recebeu comida\n", rank);

        MPI_Send(&msg,sizeof(msg),MPI_CHAR,0,tag,MPI_COMM_WORLD);

    }

  }
  MPI_Finalize();
  return 0;
}
