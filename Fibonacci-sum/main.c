#include <stdio.h>

int main()
{
    int i, n, fib, fib_prev=1, fib_prev2=0, sum=0;
    printf("n=");
    scanf("%d", &n);
    printf("0, 1, ");
    for (i=0; i<n-2; i++) {
        fib = fib_prev + fib_prev2;
        fib_prev2=fib_prev;
        fib_prev=fib;
        sum = sum + fib;

        printf((i<n-3)?"%d, ":"%d", fib);
    }
    printf("\nSum = %d, ", sum);
    return 0;
}
