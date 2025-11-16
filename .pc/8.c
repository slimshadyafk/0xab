#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int send_data[8];      // Data to be scattered (only meaningful in root)
    int recv_data;         // Each process will receive one integer
    int gathered_data[8];  // Data gathered back at root

    MPI_Init(&argc, &argv);                // Initialize MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get total number of processes

    if (size != 4) {
        if (rank == 0)
            printf("Please run this program with 4 processes.\n");
        MPI_Finalize();
        return 0;
    }

    // Process 0 initializes the data to scatter
    if (rank == 0) {
        printf("Process 0 initializing data: ");
        for (int i = 0; i < 8; i++) {
            send_data[i] = i + 1;
            printf("%d ", send_data[i]);
        }
        printf("\n");
    }

    // Scatter data: root process sends equal parts to all processes
    MPI_Scatter(send_data, 2, MPI_INT, &recv_data, 2, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received data: ", rank);
    for (int i = 0; i < 2; i++)
        printf("%d ", (&recv_data)[i]);
    printf("\n");

    // Each process modifies its data
    int local_data[2];
    local_data[0] = (&recv_data)[0] * 10;
    local_data[1] = (&recv_data)[1] * 10;

    // Gather modified data back to root
    MPI_Gather(local_data, 2, MPI_INT, gathered_data, 2, MPI_INT, 0, MPI_COMM_WORLD);

    // Root process prints the gathered result
    if (rank == 0) {
        printf("\nProcess 0 gathered modified data: ");
        for (int i = 0; i < 8; i++)
            printf("%d ", gathered_data[i]);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}