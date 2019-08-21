#include <stdio.h>
#include <mpi.h>
#include <string.h>
#define STD_TAG 0


int main (int argc, char **argv)
{
  int i,rank,size;
  char buffer[100];
  MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    while(1)
    {
      if(rank!=0)
      {
        MPI_Recv( buffer,16,MPI_CHAR,MPI_ANY_SOURCE, MPI_ANY_TAG,MPI_COMM_WORLD,&status);
        MPI_Send( buffer, strlen(buffer)+1, MPI_CHAR,0, STD_TAG,MPI_COMM_WORLD);

        // MPI_recv();
        // MPI_Recv( buffer,16,MPI_CHAR,MPI_ANY_SOURCE, MPI_ANY_TAG,MPI_COMM_WORLD,&status);
         printf("processo %d , comendo\n", status.MPI_SOURCE, buffer );

      }
      else
      {

        MPI_Recv( buffer,16,MPI_CHAR,MPI_ANY_SOURCE, MPI_ANY_TAG,MPI_COMM_WORLD,&status);
        // for(int i=0; i<size; i++)
        // {
        //   MPI_Send( buffer, strlen(buffer)+1, MPI_CHAR,0, STD_TAG,MPI_COMM_WORLD);
        // }

        sleep(2);

        printf("\n" );
      }

    }

    MPI_Finalize();
}
