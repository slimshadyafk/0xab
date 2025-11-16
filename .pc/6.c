#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int data;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (size != 2) {
        if (rank == 0)
            printf("Run this program with exactly 2 processes!\n");
        MPI_Finalize();
        return 0;
    }

    if (rank == 0) {
        data = 100;
        printf("Process 0: Sending data to Process 1...\n");
        MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);  // Blocking send
        printf("Process 0: Waiting to receive data from Process 1...\n");
        MPI_Recv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
        printf("Process 0: Received data = %d\n", data);
    } else if (rank == 1) {
        data = 200;
        printf("Process 1: Sending data to Process 0...\n");
        MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);  // Blocking send
        printf("Process 1: Waiting to receive data from Process 0...\n");
        MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
        printf("Process 1: Received data = %d\n", data);
    }

    MPI_Finalize();
    return 0;
}