#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
/*
 #include <iostream>
 #include <sstream>
 #include <locale>
 #include <iomanip>
 
 int main()
 {
    std::tm t = {};
    std::istringstream ss("2011-Februar-18 23:12:34");
    ss.imbue(std::locale("de_DE.utf-8"));
    ss >> std::get_time(&t, "%Y-%b-%d %H:%M:%S");
    if (ss.fail()) {
        std::cout << "Parse failed\n";
    } else {
        std::cout << std::put_time(&t, "%c") << '\n';
    }



		resetiosflags(std::ios_base::basefield);
	cout << std::resetiosflags(std::ios_base::dec)
		 << std::setiosflags(std::ios_base::hex | std::ios_base::uppercase | std::ios_base::showbase ) << 42;


    std::cout << "default fill: " << std::setw(10) << 42 << '\n'
              << "setfill('*'): " << std::setfill('*')
                                  << std::setw(10) << 42 << '\n';

 }
*/
// HEADERS

void Color(int color, int j = 0)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | j);
}
void all_colors()
{
	for (int i = 0; i < 500; i++)
	{
		Color(i);
		cout << " i= : " << i << endl;
	}
}

int main()
{
    all_colors();
    system("pause");
}
// void all_colors()
// {
// 	for (int i = 0; i < 300; i++)
// 	{
// 		Color(i);
// 		cout << " i= : ";
// 	}
// }
HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD max_size = GetLargestConsoleWindowSize(screen);
COORD pos;
SetConsoleColors(BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
Account a;
pos.X = (max_size.X - 20) / 2;
pos.Y = (0);
SetConsoleCursorPosition(screen, pos);