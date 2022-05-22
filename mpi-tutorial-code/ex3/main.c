#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int tag = 42;
  int message;
  if(rank == 0)
  {
    for(int i=1; i<size; ++i)
    {
      message = i * i;
      MPI_Send(&message, 1, MPI_INT, i, tag, MPI_COMM_WORLD);
    }
  }
  else
  {
    MPI_Recv(&message, 1, MPI_INT, 0, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    printf("Rank %d received the following integer: %d\n", rank, message);
  }

  MPI_Finalize();
  return 0;
}

// EOF
