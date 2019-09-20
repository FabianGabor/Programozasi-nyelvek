#include <stdio.h>
#include <stdlib.h>

int main() {
    int n,i,p,ossz;
    printf("Adja meg a felso hatart: ");
    scanf_s("%d",&n);

    for(p = 1; p <= n; p++) {
        printf("\n p = %i",p);
        for(ossz=1,i=2;i<p;i++) {
            printf("\n i = %i",i);
            if (p % i == 0) {
                ossz+=i;

            }
        }
        if (ossz == p)
            printf("\n ossz = p, p= %i ",p); //!!!///
        //printf("\n");
    }

    printf("\n");
    return 0;
}
