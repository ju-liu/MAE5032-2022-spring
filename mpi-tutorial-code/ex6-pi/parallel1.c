#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
  MPI_Init(&argc, &argv);

  int size, rank;
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &size);

  long nsteps = 1000000000;
  double sum  = 0.0;

  long chunk = (nsteps + size - 1) / size;
  long start = chunk * rank;
  long end   = (chunk * (rank+1) > nsteps) ? nsteps : chunk*(rank+1);

  double t1 = MPI_Wtime();

  for(long ii=start; ii<end; ++ii)
    sum += (1.0 - 2.0 *(ii%2)) / (2.0 * ii + 1.0);

  MPI_Barrier(MPI_COMM_WORLD);
  double t2 = MPI_Wtime();
  if(rank == 0) printf("Time taken is %f. \n", t2 - t1);

  const int tag = 123;
  if(rank == 0)
  {
    double total_sum = sum;
    double other;
    for(int ii=1; ii<size; ++ii)
    {
      MPI_Recv(&other, 1, MPI_DOUBLE, ii, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      total_sum += other;
    }
    printf("pi is %.12g \n", sum * 4.0);
  }
  else
    MPI_Ssend(&sum, 1, MPI_DOUBLE, 0, tag, MPI_COMM_WORLD);

  MPI_Finalize();
  return 0;
}

// EOF
