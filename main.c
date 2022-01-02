#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mpi.h>
#define M 32


int main(int argc, char **argv) {
  clock_t tic = clock();
  int rank, size, from, to, N, useful_size;
  FILE *fp = NULL;
  MPI_Status status;

  MPI_Init (&argc, &argv);	/* starts MPI */
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);	/* get current process id */
  MPI_Comm_size (MPI_COMM_WORLD, &size);	/* get number of processes */

  if (rank == 0){
    fp = fopen("input.txt", "r");
    fscanf(fp, "%d", &N);
  }   
  MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
  useful_size = size;
  while (N % useful_size != 0) {
    useful_size--;
  }
  int A[size * (N / useful_size)][M], B[M][N], C[size * (N / useful_size)][N];
  if (rank == 0) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        fscanf(fp, "%d", &A[i][j]);
      }
    }
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        fscanf(fp, "%d", &B[i][j]);
      }
    }
    fclose(fp);

  }
  MPI_Bcast(&useful_size, 1, MPI_INT, 0, MPI_COMM_WORLD);


  from = rank * N / useful_size;
  to =  (rank + 1) * N / useful_size;

  MPI_Bcast (B, M * N, MPI_INT, 0, MPI_COMM_WORLD);

  MPI_Scatter (A, M * N / useful_size, MPI_INT, A[from], M * N / useful_size, MPI_INT, 0, MPI_COMM_WORLD);

  if (rank < useful_size) {
    for (int i = from; i < to; i++) { 
      for (int j = 0; j < N; j++) {
        C[i][j] = 0;
        for (int k = 0; k < M; k++)
          C[i][j] += A[i][k]*B[k][j];
      }
    }
  }

  MPI_Gather (C[from], N*N/useful_size, MPI_INT, C, N*N/useful_size, MPI_INT, 0, MPI_COMM_WORLD);

  if (rank == 0) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        printf("%d ", C[i][j]);
      }
      printf("\n");
    }
  }


  MPI_Finalize();
  clock_t toc = clock();
  if (rank == 0){
    printf("running time: %f\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  }

  return 0;
}
