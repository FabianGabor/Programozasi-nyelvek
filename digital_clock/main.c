#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


void clrscr()
{
    system("@cls||clear");
}

void current_time()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%d %d %d \n", tm.tm_hour, tm.tm_min, tm.tm_sec);
}

int main()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);


    while (!kbhit()) {

        current_time();

        //if (kbhit()) return 0;
        Sleep(1000);
        clrscr();
    }
    return 0;
}
