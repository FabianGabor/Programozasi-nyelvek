#include <stdio.h>
#include <math.h>


int main ()
{
    int kartya_e;    

    // 1. Kérd be egy magyar kártya értékét számmal és írd ki, hogy melyik kártyalap ér ennyit!
    // 2 = alsó, 3 = felső, 4 = király, 11 = ász, 7=hetes, 8=nyolcas, 9=kilcenes, 10=tízes
/*
    printf("Kartya erteke: ");
    scanf("%d", &kartya_e);

    switch (kartya_e) {
        case 2: printf("also \n"); break;
        case 3: printf("felso \n"); break;
        case 4: printf("kiraly \n"); break;
        case 11: printf("asz \n"); break;
        default: printf("%d \n", kartya_e);
    }

*/
    // 2. Ha bekérjük egy egyenes két pontjának a koordinátáját (x,y), mennyi lesz az egyenes meredeksége? Ügyelj a függőleges egyenesre!
    //(ajánlott oldal: https://phet.colorado.edu/hu/simulation/graphing-lines)

    int x1, x2, y1, y2;
    double m, szog;
    /*
    printf("x1: ");
    scanf("%d", &x1);
    printf("y1: ");
    scanf("%d", &y1);

    printf("x2: ");
    scanf("%d", &x2);
    printf("y2: ");
    scanf("%d", &y2);
    */
    x1=2;
    y1=1;
    x2=5;
    y2=6;

    m = 1.0 * (y2-y1) / (x2-x1);

    double atfogo = sqrt( pow((y2-y1), 2) + pow((x2-x1),2) );
    //printf("%f \n",sin( (y2-y1) / atfogo));

    printf("Meredekseg m = %f \n", m);
    szog = atan( (y2-y1) * 1.0 / (x2-x1) ) * 180.0 / M_PI;
    //szog = asin( (y2-y1) / atfogo ) * 180.0 / M_PI;
    printf("Szog = %f \n", szog);

    // 3. Milyen messze van ez a két pont egymástól?
    printf("Atfogo, azaz 2 pont tavolsaga= %f \n", atfogo);

    //4. Hol metszi az x és az y tengelyt az egyenes?
    double x_cross=x1-y1/m;
    double y_cross = m*(0-x1)+y1;
    printf("X tengely metszespontja: %f\n", x_cross);
    printf("Y tengely metszespontja: %f\n", y_cross);

    // 5. Kérd be egy hónapnak és napnak a sorszámát (pl. 9. hónap, 20. nap), írd ki, hogy ez az év hányadik napja lesz
    // (ha nem szökőévről van szó)! A megoldást switch szerkezet biztosítsa (tömbök nélkül)!
/*
    int honap, nap, evnap = 0;
    printf("Honap, nap: \n");
    scanf("%d %d", &honap, &nap);

    switch (honap) {
        case 12: evnap += 30;
        case 11: evnap += 31;
        case 10: evnap += 30;
        case 9: evnap += 31;
        case 8: evnap += 31;
        case 7: evnap += 30;
        case 6: evnap += 31;
        case 5: evnap += 30;
        case 4: evnap += 31;
        case 3: evnap += 28;
        case 2: evnap += 31;
        case 1: evnap += 0;

    }
    evnap += nap;
    printf("%d", evnap);
*/


    return 0;
}
