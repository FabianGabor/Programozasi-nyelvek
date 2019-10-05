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

    /*
    #pragma omp parallel num_threads(8)
    {
        for (i=0; i<=n; i++) {

            fib = f(i);
            //sum += fib;
            #pragma omp critical
            printf("%llu : ", i);
            #pragma omp critical
            printf((i<n-1)?"%llu, \n":"%llu\n",fib);


        }
    }
*/




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


/*
int main()
{
    clock_t start, end;
    double runTime;
    start = clock();

    int n, sum=0;
    unsigned long long fib;
    printf("n=");
    scanf("%d", &n);

    for (int i=0; i<n; i++) {
        fib = f(i);
        //sum += fib;
        printf("%d : ", i);
        printf((i<n-1)?"%llu, \n":"%llu\n",fib);

    }
    //printf("\nSum = %d\n", sum);

    end = clock();
    runTime = (end - start) / (double) CLOCKS_PER_SEC;
    printf("This machine calculated all fibonacci numbers up to %d in %g seconds\n", n, runTime);
    return 0;
}*/
/*
int main()
{
    int i,j,n,fibnum[100];
    printf("Enter the Limit of the series: ");
    scanf("%d",&n);
    #pragma omp parallel num_threads(2)
    {
    #pragma omp critical
        {
            if(omp_get_thread_num()==0)
            {
                printf("\nThere are total %d threads\n",omp_get_num_threads());
                printf("\nThread no %d is the generating thread\n",omp_get_thread_num());
                for(i=0;i<n;i++)
                    fibnum[i]=f(i);
            }
            else
            {
                printf("Thread no %d is the printing thread\n",omp_get_thread_num());
                for(j=0;j<n;j++)
                    printf("%d\t",f[j]);
                printf("\n");
            }
        }
    }
}
*/
