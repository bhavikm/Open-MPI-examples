# Open-MPI-examples
Examples of some common functions used with Open Message Passing Interface (MPI)

Requires Open MPI to compile and run (http://www.open-mpi.org/)

Example functions:
  * MPI_Abort
  * MPI_Bcast
  * MPI_Comm_Rank
  * MPI_Isent and MPI_Irecv
  * MPI_Send and MPI_Recv

To compile:  
`mpicc -o <program_name> <source_name.c>`  
  
To run:  
`mpirun -n <number of processes> <program_name>`
