//==============================================================================
//                           LIBRARIES OR HEADER
//==============================================================================
#include <iostream>
#include <conio.h>
#include <fstream>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <iomanip>

using namespace std;
//==============================================================================
//                       FUNCTION FOR THE AXIS (GOTOXY)
//==============================================================================
void gotoxy(int x, int y)
{
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//==============================================================================
//                      FUNCTIONZ TO CLEAR CONSOLE WINDOWZ
//==============================================================================
void clearWindow()
{
      int i, j;
      for (i = 15; i < 65; i++)
      {
            for (j = 0; j < 25; j++)
            {
                  gotoxy(i, j);
                  printf(" ");
            }
      }
      return;
}
void clearWindowz()
{
      int i, j;
      for (i = 1; i < 80; i++)
      {
            for (j = 0; j < 25; j++)
            {
                  gotoxy(i, j);
                  printf(" ");
            }
      }
      return;
}
//==============================================================================
//                               MAIN CLASS
//==============================================================================
class Bank
{

private:
      int i;

public:
      void progressBarGraphicz()
      {
            gotoxy(27, 5);
            std::cout << "BANK  Of AJGKG";
            gotoxy(8, 3);
            printf("\xC9"); // Upper left corner
            for (i = 1; i <= 61; i++)
                  printf("\xCD"); // Upper left right horizontal
            gotoxy(70, 3);
            printf("\xBB"); // Upper right corner
            gotoxy(8, 22);
            printf("\xC8"); // Lower left corner
            for (i = 1; i <= 61; i++)
                  printf("\xCD"); // Lower left right horizontal
            gotoxy(70, 22);
            printf("\xBC"); // Lower right corner
            for (i = 1; i < 19; i++)
            {
                  gotoxy(8, i + 3);
                  printf("\xBA");
            } // Left vertical
            for (i = 1; i < 19; i++)
            {
                  gotoxy(70, i + 3);
                  printf("\xBA");
            } // Right vertical

            //=================================================================
            gotoxy(8, 7);
            printf("\xCC"); // Left inside upper corner
            for (i = 1; i <= 61; i++)
                  printf("\xCD"); // Inside upper left right horizontal
            gotoxy(8, 17);
            printf("\xCC"); // Left inside lower corner
            for (i = 1; i <= 61; i++)
                  printf("\xCD"); // Inside lower left right horizontal
            gotoxy(70, 7);
            printf("\xB9"); // Right inside upper corner
            gotoxy(70, 17);
            printf("\xB9"); // Right inside lower corner
            gotoxy(35, 17);
            std::cout << " LOADING ";
      }
};
//==============================================================================
//             CLASS OBJECTS DECLARATION
//==============================================================================
Bank banky;

void progressBar()
{
      int i, j, k;
      system("cls");
      system("color 09");
      banky.progressBarGraphicz();
      for (j = 1; j <= 3; j++)
      {
            if (j == 1)
            {
                  gotoxy(32, 21);
                  printf("Checking folders...");
            }
            if (j == 2)
            {
                  gotoxy(32, 21);
                  printf("Checking files...");
            }
            if (j == 3)
            {
                  gotoxy(32, 21);
                  printf("Loading System...");
            }
            for (k = 10; k < 69; k++)
            {
                  gotoxy(k, 20);
                  printf("º");
            }
            for (k = 10; k < 69; k++)
            {
                  gotoxy(k, 20);
                  putch(10000);
                  Sleep(120);
            }
      }
      system("cls");
      mainMenu();
      getch();
}
//==============================================================================
//                       FUNCTION MAIN FUNCTION
//==============================================================================
int main()
{
      SetConsoleTitle("BANK OF AJGKG.");
      progressBar();
}
