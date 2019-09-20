/*
1. Írasd ki a neved a képernyőre!
2. Kérd be a születési évet és írasd ki az életkort!
3. Kérd be a víz hőfokát, állapítsd meg belőle a halmazállapotát!
4. Kérd be három gerelyhajító legjobb eredményét és hirdess győztest!
5. Kérje be egy hasáb három élének hosszúságát, majd írja ki a hasáb felszínét és térfogatát!
6. Kérje be egy gömb sugarát, majd írja ki a gömb felszínét és térfogatát! (valós adatok)
*/

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define _USE_MATH_DEFINES
#include <math.h>
#define pi 3.1415

int main()
{
    int szuletesi_ev, viz_hofoka, gerely1, gerely2, gerely3, gomb_r;
    char helyezesek[3];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    struct hasab { int a,b,m; } hasab;

    // 1. Írasd ki a neved a képernyőre!
    printf("Fabian Gabor!\n");

    // 2. Kérd be a születési évet és írasd ki az életkort!
    printf("Szuletesi eved: ");
    scanf("%d", &szuletesi_ev);
    printf("%s \n", "");
    printf("Eletkorod: %d \n", tm.tm_year + 1900 - szuletesi_ev);

    // 3. Kérd be a víz hőfokát, állapítsd meg belőle a halmazállapotát!
    printf("\nViz hofoka: ");
    scanf("%d", &viz_hofoka);

    if (viz_hofoka <= 0)
        printf("Halmazallapota jeg\n");
    else
        if (viz_hofoka < 100)
            printf("Halmazallapota folyekony\n");
        else printf("Halmazallapota gaz\n");


    // 4. Kérd be három gerelyhajító legjobb eredményét és hirdess győztest!
    printf("\nHelyezesek:\n");
    scanf("%d %d %d", &gerely1, &gerely2, &gerely3);

    helyezesek[gerely1]='A';
    helyezesek[gerely2]='B';
    helyezesek[gerely3]='C';

    printf("\nSorrend: \n");
    for (int i=1;i<=3;i++)
    {
        printf("%c \n", helyezesek[i]);
    }


    // 5. Kérje be egy hasáb három élének hosszúságát, majd írja ki a hasáb felszínét és térfogatát!
    printf("\nHasab oldalai:\n");
    printf("a: ");
    scanf("%d", &hasab.a);
    printf("b: ");
    scanf("%d", &hasab.b);
    printf("c: ");
    scanf("%d", &hasab.m);

    printf("Hasab felszine: %d \n", hasab.a * hasab.b * 2 + hasab.a * hasab.m * 2 + hasab.b * hasab.m * 2);
    printf("Hasab terfogata: %d \n", hasab.a * hasab.b * hasab.m);


    // 6. Kérje be egy gömb sugarát, majd írja ki a gömb felszínét és térfogatát! (valós adatok)
    printf("\nGomb sugara: ");
    scanf("%d", &gomb_r);
    printf("Gomb felszine: %lf \n", 4 * pow(gomb_r, 2) * pi);
    printf("Gomb terfogata: %lf \n", 4 * pow(gomb_r, 3) * pi / 3);

    printf("\n");
    return 0;
}
