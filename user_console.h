#ifndef user_Console
#define user_Console
#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>

COORD GetConsoleCursorPosition(HANDLE hConsoleOutput)
{
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(hConsoleOutput, &cbsi))
    {
        return cbsi.dwCursorPosition;
    }
    else
    {
        // The function failed. Call GetLastError() for details.
        COORD invalid = {0, 0};
        return invalid;
    }
}
void shift(int shiftx = 0, int shifty = 0)
{
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = GetConsoleCursorPosition(screen);
    coord.X = coord.X + shiftx;
    coord.Y = coord.Y + shifty;
    SetConsoleCursorPosition(screen, coord);
}