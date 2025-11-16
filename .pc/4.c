#include <omp.h>
#include <stdio.h>
int main() {
    int prime[1000], i, j, n;
    // Prompt user for input
    printf("\n In order to find prime numbers from 1 to n, enter the value of n:");
    scanf("%d", &n);
    // Initialize all numbers as prime (set all to 1)
    for (i = 1; i <= n; i++) {
        prime[i] = 1;
    }
    // 1 is not a prime number
    prime[1] = 0;
    // Sieve of Eratosthenes with parallelization
    for (i = 2; i * i <= n; i++) {
#pragma omp parallel for
        for (j = i * i; j <= n; j = j + i) {
            if (prime[j] == 1) {
                prime[j] = 0;
            }
        }
    }
    // Print prime numbers
    printf("\n Prime numbers from 1 to %d are\n", n);
    for (i = 2; i <= n; i++) {
        if (prime[i] == 1) {
            printf("%d\t", i);
        }
    }
    double start, end;
    // Sequential
    start = omp_get_wtime();
    prime[i];
    end = omp_get_wtime();
    printf("\nSequential Time: %f seconds\n", end - start);
    // Parallel
    start = omp_get_wtime();
    prime[i];
    end = omp_get_wtime();
    printf("Parallel Time: %f seconds\n", end - start);
    printf("\n");
}