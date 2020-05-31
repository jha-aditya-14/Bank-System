#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>

using namespace std;
class date_type
{
protected:
    int date;
    int month;
    int year;

public:
    date_type(int d = 0, int m = 0, int y = 0)
    {
        date = d;
        month = m;
        year = y;
    }
    // friend istream &operator>>(istream &in, date_type &dt)
    // {
    // 	cout << "\nEnter date(dd mm yy) : ";
    // 	in >> dt.date >> dt.month >> dt.year;
    // 	return in;
    // }
    friend ostream &operator<<(ostream &out, date_type &dt)
    {
        cout << "Date__is__(dd mm yy)___";
        out << dt.date << "/" << dt.month << "/" << dt.year;
        return out;
    }
    friend istream &operator>>(istream &in, date_type &dt)
    {
        in >> dt.date >> dt.month >> dt.year;
        return in;
    }
    void get_date()
    {
        cout << "Enter date(dd mm yy) : ";
        cin >> date >> month >> year;
    }
};
enum Branch
{
    Delhi,
    Mumbai,
    Chennai
};
enum ac_type
{
    Savings,
    Current
};
class s
{
    char fname[10];
    char lname[10];
    long long int phone;
    date_type dob;
    char res_city[10];
    char email[30];
    int acc_no;
    int passcode;
    // Branch branch;
    long int balance;
    date_type created_on;
    ac_type type;

public:
    void get()
    {
        strcpy(fname, "");
        strcpy(lname, "");
        phone = 0;
        strcpy(res_city, "");
        strcpy(email, "");
        dob = date_type(0, 0, 0);
        acc_no = 0;
        passcode = 0;
        balance = 0;
        type = Savings;
        created_on = date_type(0, 0, 0);
    }
    friend istream &operator>>(istream &in, s temp)
    {
        in >> temp.fname >> temp.lname >> temp.phone >> temp.res_city >> temp.email >> temp.acc_no >> temp.passcode >> temp.balance >> temp.dob >> temp.created_on;
        return in;
    }
    friend ostream &operator<<(ostream &out, s temp)
    {
        out << temp.fname << endl
            << temp.lname << endl
            << temp.phone << endl
            << temp.res_city << endl
            << temp.email << endl
            << temp.acc_no << endl
            << temp.passcode << endl
            << temp.balance << endl
            << temp.dob << endl
            << temp.created_on;
        return out;
    }
} obj;
int main()
{

    // cout << obj;
    fstream file;
    file.open("Account_data.dat", ios::in | ios::binary);
    file.read((char *)&obj, sizeof(obj));
    while (!file.eof())
    {
        cout << obj;
        file.read((char *)&obj, sizeof(obj));
    }
    file.close();
}