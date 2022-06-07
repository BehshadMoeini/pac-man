

int table[100][100];
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define VK_NUMPAD0        0x60
#define VK_NUMPAD1        0x61
#define VK_NUMPAD2        0x62
#define VK_NUMPAD3        0x63
#define VK_NUMPAD4        0x64
#define VK_NUMPAD5        0x65
#define VK_NUMPAD6        0x66
#define VK_NUMPAD7        0x67
#define VK_NUMPAD8        0x68
#define VK_NUMPAD9        0x69

#define VK_CLEAR          0x0C
#define VK_RETURN         0x0D

#define VK_SHIFT          0x10
#define VK_CONTROL        0x11
#define VK_MENU           0x12
#define VK_PAUSE          0x13
#define VK_CAPITAL        0x14

#define VK_KANA           0x15
#define VK_HANGEUL        0x15  /* old name - should be here for compatibility */
#define VK_HANGUL         0x15
#define VK_JUNJA          0x17
#define VK_FINAL          0x18
#define VK_HANJA          0x19
#define VK_KANJI          0x19

#define VK_ESCAPE         0x1B

#define VK_CONVERT        0x1C
#define VK_NONCONVERT     0x1D
#define VK_ACCEPT         0x1E
#define VK_MODECHANGE     0x1F

#define VK_SPACE          0x20
#define VK_PRIOR          0x21
#define VK_NEXT           0x22
#define VK_END            0x23
#define VK_HOME           0x24
#define VK_LEFT           0x25
#define VK_UP             0x26
#define VK_RIGHT          0x27
#define VK_DOWN           0x28
#define VK_SELECT         0x29
#define VK_PRINT          0x2A
#define VK_EXECUTE        0x2B
#define VK_SNAPSHOT       0x2C
#define VK_INSERT         0x2D
#define VK_DELETE         0x2E
#define VK_HELP           0x2F
using namespace std;
#include <windows.h>
#include <ctime>
#include <time.h>

#include <iostream>


#include <stdio.h>
#include <stdlib.h>
#include <thread>
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}


class PacMan
{
    public :
        int x=15,y=15;
        bool alive=1;

        int direction = -1;

        void move(void)
        {
            if (direction == 1 )
            {
                x--;
                if (table[x][y]==1)
                {
                    direction=-1;
                    x++;
                }
            }
            else if (direction == 2)
            {
                y++;
                if (table[x][y]==1)
                {
                    direction=-1;
                    y--;
                }
            }
            else if (direction == 3)
            {
                y--;
                if (table[x][y]==1)
                {
                    direction=-1;
                    y++;
                }
            }
            else if (direction == 4)
            {
                x++;
                if (table[x][y]==1)
                {
                    direction=-1;
                    x--;
                }
            }

            if (table[x][y]==2)
                table[x][y]=0;

        }

        void SetDir (void)
        {
        if (GetKeyState(VK_LEFT)!=0 && GetKeyState(VK_LEFT)!=1)
            this->direction=1;
        if (GetKeyState(VK_DOWN)!=0 && GetKeyState(VK_DOWN)!=1)
            this->direction=2;
        if (GetKeyState(VK_UP)!=0 && GetKeyState(VK_UP)!=1)
            this->direction=3;
        if (GetKeyState(VK_RIGHT)!=0 && GetKeyState(VK_RIGHT)!=1)
            this->direction=4;
        }


};





PacMan pacman;

void show ( int Table[100][100] )
{

    system("cls");
    for (int i=0;i<30;i++)
    {
        for (int j=0;j<28;j++)
        {
            if (j==pacman.x && i==pacman.y)
                cout <<"*"<<" ";
            else
                cout<<Table[j][i]<<" ";
            pacman.SetDir();
        }
        cout << endl;
    }
}

int main()
{

    FILE *f=fopen("Map.txt","r");

    int i=0;
    while (!feof(f))
    {
        for (int j=0;j<28;j++)
            fscanf(f,"%d",&table[j][i]);
        i++;
    }
    fclose(f);

    show(table);


    while (pacman.alive)
    {

        for (int i=0;i<100;i++)
            pacman.SetDir();
        pacman.move();
        show(table);
    }
    system("cls");
    cout<<"u died";
}






