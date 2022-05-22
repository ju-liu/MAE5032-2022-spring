#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
  int rank, size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  int tag1 = 42, tag2 = 43;
  int sendMessage, recvMessage;
  if(rank == 0)
  {
    sendMessage = 7;
    MPI_Ssend(&sendMessage, 1, MPI_INT, 1, tag1, MPI_COMM_WORLD);
    MPI_Recv(&recvMessage, 1, MPI_INT, 1, tag2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  }
  else if(rank == 1)
  {
    sendMessage = 14;
    MPI_Recv(&recvMessage, 1, MPI_INT, 0, tag1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Ssend(&sendMessage, 1, MPI_INT, 0, tag2, MPI_COMM_WORLD);
  }

  printf("Rank %d received the following integer: %d\n", rank, recvMessage);
  
  MPI_Finalize();
  return 0;
}

// EOF
