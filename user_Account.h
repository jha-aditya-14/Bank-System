#ifndef user_Account
#define user_Account
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
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
ostream &left1(ostream &out)
{
    out.setf(ios::left);
    out.fill('_');
    out << setw(40);
    return out;
}
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
    void get_date()
    {
        cout << left1 << "Enter date(dd mm yy) : ";
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
struct login
{
    int acc_no;
    int passcode;
    long long int phone;
} login;
class Bank
{
    char bank_name[20];
    Branch branch_name;
    char branch_city[20];
    long int asset;

public:
    // Bank(char *bnk_name, char *city)
    // {
    // 	strcpy(bank_name, bnk_name);
    // 	branch_name = Delhi;
    // 	strcpy(branch_city, city);
    // 	asset = 0;
    // }
};
class basic_details
{
protected:
    char fname[10];
    char lname[10];
    long long int phone;
    date_type dob;
    char res_city[10];
    char email[30];

public:
    /* basic_details(char fn = "Null", char ln = "Null", int ph = 0, char cit = "Null")*/
    basic_details()
    {
        strcpy(fname, "");
        strcpy(lname, "");
        phone = 0;
        strcpy(res_city, "");
        strcpy(email, "");
        dob = date_type(0, 0, 0);
    }
};
class Account : basic_details
{
    int acc_no;
    int passcode;
    // Branch branch;
    long int balance;
    date_type created_on;
    ac_type type;

public:
    Account()
    // // char fn = "Null",
    // // char ln = "Null",
    // // int ph = 0,
    // // char cit = "Null",
    // int ac_no = 0,
    // int pass = 0,
    // int bal = 0,
    // ac_type typ = Savings) // : basic_details(fn = "Null", ln = "Null", ph = 0, cit = "Null")
    {
        acc_no = 0;
        passcode = 0;
        balance = 0;
        type = Savings;
        created_on = date_type(0, 0, 0);
    }
    Account(Account &copy)
    {
        strcpy(fname, copy.fname);
        strcpy(lname, copy.lname);
        phone = copy.phone;
        strcpy(res_city, copy.res_city);
        strcpy(email, copy.email);
        dob = copy.dob;
        acc_no = copy.acc_no;
        passcode = copy.passcode;
        balance = copy.balance;
        type = copy.type;
        created_on = copy.created_on;
    }
    // Account() { cout << "\nAccount Constructed"; }
    void create_account(int);
    void show_account_details();
    void update_details();
    int get_passcode() { return passcode; }
    int get_acc_no() { return acc_no; }
    long long int get_phone() { return phone; }
    long int get_balance() { return balance; }
    void add_into_balance(long &amt) { balance += amt; }
    void sub_from_balance(long &amt)
    {
        if (balance - amt > 0)
        {
            balance -= amt;
        }
    }
    // const char *get_email() { return email; }
    void get_name()
    {
        cout << left1 << "Enter First Name";
        cin >> fname;
        cout << left1 << "Enter Last Name";
        cin >> lname;
    }
    void get_email()
    {
        cout << left1 << "Enter Email Id";
        cin >> email;
    }
    void input_phone()
    {
    Enter_phone:
        cin >> phone;
        if (phone < 999999999 || phone > 9999999999)
        {
            cout << "Invalid Enter Again";
            shift(-19, -1);
            getch();
            cout << left1 << "Enter Phone Number";
            cout << "          ";
            shift(-10, 0);
            goto Enter_phone;
        }
        else
        {
            cout << "          ";
        }
        shift(-10);
    }
    void get_DOB()
    {
        cout << "DOB : \n";
        dob.get_date();
    }
    void get_city()
    {
        cout << left1 << "Enter City";
        cin >> res_city;
    }
    void generate_acc_no()
    {
        acc_no = rand() % (100) + 100;
        cout << left1 << "Account Number is " << acc_no;
        cout << endl;
    }
    void enter_passcode()
    {
        cout << left1 << "Enter the passcode";
    Enter_passcode:
        cin >> passcode;
        if (isdigit(passcode))
        {
            cout << "Invalid Enter Again";
            shift(-19, -1);
            getch();
            cout << left1 << "Enter the passcode";
            cout << "          ";
            shift(-10, 0);
        }
    }
    void show_balance()
    {
        cout << left1 << "Current Balance" << balance;
        cout << endl;
    }
    void get_type()
    {
        int num;
        cout << left1 << "Type (0 for Savings, 1 for Current)";
    Enter_type:
        cin >> num;
        if (num == 0)
            type = Savings;
        else if (num == 1)
            type = Current;
        else
        {
            cout << "Invalid Enter Again";
            shift(-19, -1);
            getch();
            cout << left1 << "Type (0 for Savings, 1 for Current)";
            cout << "\t\t\t";
            shift(-24, 0);
            goto Enter_type;
        }
    }
    void input_creation_date()
    {
        cout << "Creation Date : \n";
        created_on.get_date();
    }
};
void Account::create_account(int specific = 0)
{
    char input;
    int digits;
    int num;
    cout << endl;
    this->get_name();
    this->get_email();
    this->input_phone();
    this->get_DOB();
    this->get_city();
    cout << "====Basic Details taken====";
    cout << endl;
    this->generate_acc_no();
    this->enter_passcode();
    this->show_balance();
    this->get_type();
    this->input_creation_date();
}
void Account::update_details()
{
    int choice;
    do
    {
        cout << "1.Update Name" << endl
             << "2.Update Email ID" << endl
             << "3.Update Phone Number" << endl
             << "4.Update DOB" << endl
             << "5.Update City" << endl
             << "6.Update Passcode" << endl
             << "7.Update Type" << endl
             << "8.Exit" << endl
             << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:

            this->get_name();
            break;
        case 2:
            this->get_email();
            break;
        case 3:
            this->input_phone();
            break;
        case 4:
            this->get_DOB();
            break;
        case 5:
            this->get_city();
            break;
        case 6:
            this->enter_passcode();
            break;
        case 7:
            this->get_type();
            break;
        default:
            break;
        }
    } while (choice != 8);
}
void Account::show_account_details()
{
    system("cls");
    cout << left1 << "First Name" << fname << endl;
    cout << left1 << "Last Name" << lname << endl;
    cout << left1 << "Email ID" << email << endl;
    cout << left1 << "Phone Number " << phone << endl;
    cout << left1 << "Residing City" << res_city << endl;
    cout << "Date_of_Birth___:" << dob << endl;
    cout << left1 << "Account Number" << acc_no << endl;
    cout << "passcode" << passcode << endl;
    cout << left1 << "Balance" << balance << endl;
    cout << left1 << "Type";
    (type == Savings) ? cout << "Savings" : cout << "Current";
    cout << endl;
    cout << "Account_Opening_:" << created_on << endl;
}

#endif