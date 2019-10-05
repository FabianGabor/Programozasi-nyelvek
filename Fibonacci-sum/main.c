#include <stdio.h>
#include <time.h>
#include <omp.h>

int main()
{
    double start = omp_get_wtime();
    double runTime;
    int i,n = 99999;
    unsigned long long fib, fib_prev=1, fib_prev2=0, sum=0;

    //printf("n=");
    //scanf("%d", &n);

    printf("1 : 0\n2 : 1\n");
    // 7.1s vs
//#pragma omp parallel for num_threads(8)
    for (i=3; i<=n; i++) {
        fib = fib_prev + fib_prev2;
        fib_prev2 = fib_prev;
        fib_prev = fib;
        sum = sum + fib;

  //      #pragma omp critical
        printf("%d : %llu\n", i, fib);
    }

    printf("\nSum = %llu\n", sum);

    double end = omp_get_wtime();
    runTime = end - start;
    printf("Calculated all fibonacci numbers up to %d in %lf seconds\n", n, runTime);

    return 0;
}
