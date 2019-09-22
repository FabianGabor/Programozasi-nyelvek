#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


void clrscr()
{
    system("@cls||clear");
}

void digits()
{
    int digit[10][5][3] =
    {
        {
            {1,1,1},
            {1,0,1},
            {1,0,1},
            {1,0,1},
            {1,1,1}
        },
        {
            {0,1,0},
            {0,1,0},
            {0,1,0},
            {0,1,0},
            {0,1,0}
        },
        {
            {1,1,1},
            {0,0,1},
            {1,1,1},
            {1,0,0},
            {1,1,1}
        },
        {
            {1,1,1},
            {0,0,1},
            {1,1,1},
            {0,0,1},
            {1,1,1}
        },
        {
            {1,0,1},
            {1,0,1},
            {1,1,1},
            {0,0,1},
            {0,0,1}
        },
        {
            {1,1,1},
            {1,0,0},
            {1,1,1},
            {0,0,1},
            {1,1,1}
        },
        {
            {1,1,1},
            {1,0,0},
            {1,1,1},
            {1,0,1},
            {1,1,1}
        },
        {
            {1,1,1},
            {0,0,1},
            {0,0,1},
            {0,0,1},
            {0,0,1}
        },
        {
            {1,1,1},
            {1,0,1},
            {1,1,1},
            {1,0,1},
            {1,1,1}
        },
        {
            {1,1,1},
            {1,0,1},
            {1,1,1},
            {0,0,1},
            {1,1,1}
        }
    };

    for (int i = 0; i < 10 ; i++)
        for (int x = 0; x < 5; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (digit[i][x][y]!=0)
                    printf("%c", 178);
                else
                    printf(" ");
            }
            printf("\n");
        }
}

void current_time()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    //printf("%d %d %d \n", tm.tm_hour, tm.tm_min, tm.tm_sec);
    digits();

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
