#include <mpi.h>
#include <stdio.h>
#define Gaules 7
#define M 16
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the number of processes
    int size;
    int rank;
    MPI_Status status;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if((size-1) == rank) //cozinha
    {
      for(int i = 0; i<M; i++)
      {

      }
    }
    else //gaules
    {
      MPI_Recv(count, 16, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status );
    }

    MPI_Finalize();


}
