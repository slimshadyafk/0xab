#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int number;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        // Process 0 initializes the data
        number = 1234;
        printf("Process 0: Broadcasting number = %d to all processes...\n", number);
    }

    // Broadcast the variable 'number' from process 0 to all others
    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // All processes print the received number
    printf("Process %d: Received number = %d\n", rank, number);

    // Finalize the MPI environment
    MPI_Finalize();
    return 0;
}