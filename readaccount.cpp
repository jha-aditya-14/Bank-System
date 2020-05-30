#include <fstream>
#include <conio.h>
#include <iostream>
#include <ctype.h>
using namespace std;
int main()
{
    char c;
    int a;
    fstream file("Account_data.dat", ios::in | ios::binary);
    while (!file.eof())
    {
        file.read((char *)&c, sizeof(c));
        cout << c;
    }
    cout << "\n\nEND";
    file.close();
}