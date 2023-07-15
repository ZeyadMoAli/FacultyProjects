#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mpi.h"

int main(int argc, char *argv[])
{
    int rank, size, i;
    double start_time, end_time; 

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n;
    double *data;
    if (rank == 0)
    {
        printf("Array size: ");
        scanf("%d", &n);
        data = (double *)malloc(n * sizeof(double));
        // static array initialization
        for (i = 0; i < n; i++)
        {
            data[i] = i + 1;
        }
    }

    start_time = MPI_Wtime();

    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int local_n = n / size;
    int remainder = n % size;
    double *local_data = (double *)malloc(local_n * sizeof(double));
    MPI_Scatter(data, local_n, MPI_DOUBLE, local_data, local_n,
                MPI_DOUBLE, 0, MPI_COMM_WORLD);

    double local_sum = 0;
    for (i = 0; i < local_n; i++)
    {
        local_sum += local_data[i];
    }

    if (rank == 0)
    {
        for (i = n - remainder; i < n; i++)
        {
            local_sum += data[i];
        }
    }

    double total_sum;
    MPI_Reduce(&local_sum, &total_sum, 1, MPI_DOUBLE, MPI_SUM, 0,
               MPI_COMM_WORLD);

    double mean;
    if (rank == 0)
    {
        mean = total_sum / n;
        printf("Mean = %f ,", mean);
    }

    MPI_Bcast(&mean, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    double local_squared_diff_sum = 0;
    for (i = 0; i < local_n; i++)
    {
        local_squared_diff_sum += pow(local_data[i] - mean, 2);
    }

    if (rank == 0)
    {
        for (i = n - remainder; i < n; i++)
        {
            local_squared_diff_sum += pow(data[i] - mean, 2);
        }
    }

    double total_squared_diff_sum;
    MPI_Reduce(&local_squared_diff_sum, &total_squared_diff_sum, 1,
               MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        double variance = total_squared_diff_sum / n;
        printf("Variance = %f ,", variance);
        double std_dev = sqrt(variance);
        printf("Standard deviation = %f\n", std_dev);
        end_time = MPI_Wtime();
        printf("Execution time = %f seconds\n", end_time - start_time);
    }

    free(local_data);
    if (rank == 0)
    {
        free(data);
    }

    MPI_Finalize();
}
