#include <stdio.h>
#include <time.h>
#include <omp.h>

int main() {

    double start, end;
    double runTime;
    start = omp_get_wtime();



    end = omp_get_wtime();
    runTime = end - start;
    printf("\nCalculated all %d prime numbers under %d in %g seconds\n\n",prime_count,limit,runTime);
    return 0;
}


