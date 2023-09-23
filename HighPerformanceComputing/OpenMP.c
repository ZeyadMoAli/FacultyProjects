#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int size, i;
    int n;
    double *data;

    printf("Array size: ");
    scanf("%d", &n);
    data = (double *)malloc(n * sizeof(double));
    for ( i = 0; i < n; i++) {
        // static array initialization
         data[i] = i + 1;
    }

    double start_time = omp_get_wtime(); 

    double total_sum = 0.0;
    #pragma omp parallel for reduction(+:total_sum)
    for (i = 0; i < n; i++) {
        total_sum += data[i];
    }

    double mean = total_sum / n;
    printf("Mean = %f ,", mean);

    double total_squared_diff_sum = 0.0;
    #pragma omp parallel for reduction(+:total_squared_diff_sum)
    for (i = 0; i < n; i++) {
        total_squared_diff_sum += pow(data[i] - mean, 2);
    }

    double variance = total_squared_diff_sum / n;
    printf("Variance = %f ,", variance);
    double std_dev = sqrt(variance);
    printf("Standard deviation = %f\n", std_dev);

    free(data);

    double end_time = omp_get_wtime(); 
    printf("Execution time = %f seconds\n", end_time - start_time);

    return 0;
}
