#include <stdio.h>
#include <time.h>
#include <omp.h>
#include <math.h>

int is_prime(unsigned long int x) {
    unsigned long int half = sqrt(x);

    for (unsigned long int i=3; i <= half; i += 2) {
        if (x%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    double start, end;
    double runTime;
    unsigned long int i, prime_count = 2, limit = 100000000;
    int threads[7] = {0};
    start = omp_get_wtime();


    //printf("1 2 ");
    printf("Num threads (should be 1): %d\n",omp_get_num_threads());

#pragma omp parallel
{
        if (0 == omp_get_thread_num()) printf("Num threads: %d\n\n",omp_get_num_threads());
}
#pragma omp parallel
{
        #pragma omp for
        for (i=3; i<=limit; i += 2) {


            if (is_prime(i)) {
                #pragma omp critical
                {
                    prime_count++;
                    printf("thread %d : ", omp_get_thread_num());
                    printf("%lu \n", i);
                    threads[omp_get_thread_num()]++;
                }

            }
        }
}

    end = omp_get_wtime();
    runTime = end - start;
    printf("\n\nCalculated all %lu prime numbers under %lu in %g seconds\n\n",prime_count, limit, runTime);

    float total = 0.0;
    for (i=0; i<=7; i++) {
        printf("Thread %lu : %f \n", i, threads[i]*100.0/(prime_count-2));
        total = total + threads[i]*100.0/(prime_count-2);
    }
    printf("Total: %f\n\n", total);

    return 0;
}


