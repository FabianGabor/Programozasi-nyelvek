#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

void gotoxy(short col, short row)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    SetConsoleCursorPosition(h,position);
}

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

void clrscr()
{
    system("@cls||clear");
}

void digits(int h, int min, int sec)
{

    int digi_time [6][5][3];

    for (int i=0; i<5; i++)
        for (int j=0; j<3; j++)
        {
            digi_time[0][i][j] = digit[h / 10][i][j];
            digi_time[1][i][j] = digit[h % 10][i][j];
            digi_time[2][i][j] = digit[min / 10][i][j];
            digi_time[3][i][j] = digit[min % 10][i][j];
            digi_time[4][i][j] = digit[sec / 10][i][j];
            digi_time[5][i][j] = digit[sec % 10][i][j];
        }


    for (int x = 0; x < 5; x++)
    {
        gotoxy(45,10+x);
        for (int i=0;i<=5;i++)
        {
            if ((i>0) && (i%2==0))
            {
                if (x%2==1)
                   printf(" o  ");
                else
                    printf("    ");
            }
             for (int y = 0; y < 3; y++)
                if (digi_time[i][x][y]!=0)
                    printf("%c", 219);
                else
                    printf(" ");
             printf(" ");
        }
    }
    return;
}

void current_time()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    digits(tm.tm_hour, tm.tm_min, tm.tm_sec);

}

int main()
{
    time_t t = time(NULL);

    while (!kbhit()) {
        //clrscr();
        current_time();        
        Sleep(2);
    }
    return 0;
}
