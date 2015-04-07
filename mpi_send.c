#include <stdio.h>
#include "mpi.h"


////////////
//MPI_Send
////////////
//
// uses:
// int MPI_Send(const void *buf, int count, MPI_Datatype datatype, int dest, int tag, MPI_Comm comm)
//
// This example sets up a ring of processes, the user gives a value and the root process sends the value
// to the next process. Each process then sends the value to the next process (by process ID) up to the end of the ring.
//
// example usage:
//		compile: mpicc -o mpi_send mpi_send.c
//		run: mpirun -n 4 mpi_send
//
int main(argc, argv)
int argc;
char **argv;
{
	int rank, value, size;
    MPI_Status status;

    MPI_Init(&argc, &argv);
 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //get the rank or ID of the current process
    MPI_Comm_size(MPI_COMM_WORLD, &size); //number of processes that are running

    do { 
        if (rank == 0) {
            printf("Enter a number to send (input negative to stop):\n");
            scanf("%d",&value);
            MPI_Send(&value,1,MPI_INT,rank+1,0,MPI_COMM_WORLD); // the root process sends the read-in value to next process (by ID)
        } else {
            MPI_Recv(&value,1,MPI_INT,rank-1,0,MPI_COMM_WORLD,&status); // every process except to the root receives the sent value from the previous process ID
            
            if (rank < size-1)
                MPI_Send(&value,1,MPI_INT,rank+1,0,MPI_COMM_WORLD); // each process sends the value to the next process by ID
        
            printf("Process %d got %d\n",rank, value);  //the received value
        }
    } while (value >= 0); //keep going until user inputs negative number

    MPI_Finalize();

	return 0;
}