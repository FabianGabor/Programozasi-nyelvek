#include <stdio.h>
#include <time.h>
#include <omp.h>

unsigned long long f(unsigned long long n) {
    if (n<2) return n;
    else return ( f(n-1) + f(n-2) );
}

int main()
{
    double start = omp_get_wtime();
    double runTime;

    //int i;
    unsigned long long i,n;
    //int sum=0;
    unsigned long long fib;

    printf("n=");
    scanf("%llu", &n);
#pragma omp parallel for num_threads(8)
    for (i=0; i<=n; i++) {
        #pragma omp critical
        fib = f(i);
        //sum += fib;
        #pragma omp critical
        printf("%d : ", i);
        #pragma omp critical
        printf((i<n-1)?"%llu, \n":"%llu\n",fib);

    }

    //printf("\nSum = %d\n", sum);

    double end = omp_get_wtime();
    runTime = end - start;
    printf("This machine calculated all fibonacci numbers up to %llu in %lf seconds\n", n, runTime);
    return 0;
}
