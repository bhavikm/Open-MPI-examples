#include <stdio.h>
#include "mpi.h"


////////////
//MPI_Comm_rank
////////////
//
// int MPI_Comm_rank( MPI_Comm comm, int *rank ) 
//
// Simple example that outputs the process ID of each process using MPI_Comm_rank
//
// example usage:
//		compile: mpicc -o mpi_comm_rank mpi_comm_rank.c
//		run: mpirun -n 4 mpi_comm_rank
//
int main(argc, argv)
int argc;
char **argv;
{
	int rank, value;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //sets rank of the current processor, root = 0, to rank variable
    
    printf("hello I am process %d\n", rank); //output rank or process ID of the this process

    MPI_Finalize();

	return 0;
}