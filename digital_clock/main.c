#define _CRT_SECURE_NO_WARNINGS 1 // STFU Qt
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#define fullscreenMSG "Press Alt + Enter to enter/exit full screen mode"

void gotoxy(short col, short row)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position={col,row};
    CONSOLE_CURSOR_INFO ccinfo;

    ccinfo.dwSize = 100;
    ccinfo.bVisible = FALSE;
    SetConsoleCursorInfo(h, &ccinfo);

    SetConsoleCursorPosition(h,position);
}

struct consoleSize {
    short cols, rows;
};

typedef struct consoleSize Struct;

Struct getConsoleSize() {
    Struct size;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    size.cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    size.rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return size;
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
    Struct cs;
    Struct currentcs;
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

    currentcs=getConsoleSize();

    if ((cs.cols!=currentcs.cols) || (cs.rows!=currentcs.rows))
    {
        clrscr();
        cs.cols=currentcs.cols;
        cs.rows=currentcs.rows;
    }

    gotoxy((cs.cols-sizeof(fullscreenMSG))/2, cs.rows-2);
    printf(fullscreenMSG);

    for (int x = 0; x < 5; x++)
    {
        gotoxy((cs.cols-30)/2,(cs.rows-5)/2+x);
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
    while (!kbhit()) {
        //clrscr();
        current_time();        
        Sleep(125);
    }
    return 0;
}
