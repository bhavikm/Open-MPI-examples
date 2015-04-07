#include <stdio.h>
#include "mpi.h"


////////////
//MPI_Abort
////////////
//
// Simple example that sets up certain number of MPI processes but only continues if 4 processes are used, otherwise
// use MPI_Abort to properly stop
//
// example usage:
//		compile: mpicc -o mpi_abort mpi_abort.c
//		run: mpirun -n 4 mpi_abort
//
int main(argc, argv)
int argc;
char **argv;
{
	int rank, size;
    MPI_Init(&argc, &argv);
    
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //rank of the processor, root = 0
    MPI_Comm_size(MPI_COMM_WORLD, &size); //number of processors
    
    if (size != 4) {
        MPI_Abort(MPI_COMM_WORLD, 1); //abort properly with error code '1' if not using 4 processes
    }

    printf("hello I am process: %d, size should only be 4: %d\n", rank, size);

    MPI_Finalize();

	return 0;
}