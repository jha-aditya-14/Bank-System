#pragma once
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
ostream &left1(ostream &out)
{
    out.setf(ios::left);
    out.fill('_');
    out << setw(40);
    return out;
}
ostream &message(ostream &out)
{
    out << "  ";
    out.fill(' ');
    out << setw(20);
    return out;
}
ostream &currency(ostream &out)
{
    out << setw(4) << "Rs.";
    out << setprecision(2);
    out << setiosflags(ios::fixed);
    out << setw(5);
    return out;
}