#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank, size;
    int number;
    int sum, product, maximum, minimum;
    int all_sum, all_product, all_max, all_min;

    // Initialize MPI environment
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get total number of processes

    // Each process initializes its number differently
    number = rank + 1;  // Example: process 0 -> 1, process 1 -> 2, etc.

    printf("Process %d has value %d\n", rank, number);

    // ---------------------------
    // MPI_Reduce Demonstrations
    // ---------------------------

    MPI_Reduce(&number, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&number, &product, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    MPI_Reduce(&number, &maximum, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&number, &minimum, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    if (rank == 0) {
        printf("\n--- Results using MPI_Reduce (available only in Root Process) ---\n");
        printf("Sum      = %d\n", sum);
        printf("Product  = %d\n", product);
        printf("Maximum  = %d\n", maximum);
        printf("Minimum  = %d\n", minimum);
    }

    // ---------------------------
    // MPI_Allreduce Demonstrations
    // ---------------------------

    MPI_Allreduce(&number, &all_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&number, &all_product, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    MPI_Allreduce(&number, &all_max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    MPI_Allreduce(&number, &all_min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);

    printf("\nProcess %d results using MPI_Allreduce:\n", rank);
    printf("  Sum = %d, Product = %d, Max = %d, Min = %d\n",
           all_sum, all_product, all_max, all_min);

    // Finalize MPI environment
    MPI_Finalize();
    return 0;
}
