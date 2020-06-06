// #ifndef user_Account
// #define user_Account
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
#include <string>
#include "user_manip.h"
#include "user_console.h"
using namespace std;
int view_fd();
int getch1()
{
    cout << endl;
    system("pause");
    return 0;
}
class date_type
{
public:
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
    friend ostream &operator<<(ostream &out, const date_type &dt)
    {
        // cout << "Date__is__(dd mm yy)___";
        out << dt.date << "/" << dt.month << "/" << dt.year;
        return out;
    }
    friend istream &operator>>(istream &in, date_type &dt)
    {
        // cout << "(dd mm yyyy):";
        in >> dt.date >> dt.month >> dt.year;
        if (dt.date > 31)
            cout << "\nInvalid date\n";
        if (dt.month > 12)
            cout << "\nInvalid month\n";
        return in;
    }
    int operator==(const date_type &check)
    {
        if (date == check.date &&
            month == check.month &&
            year == check.year)
        {
            return 1;
        }
        else
            return 0;
    }
};
/* 
enum Branch
{
    Delhi,
    Mumbai,
    Chennai
};
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
 */
enum ac_type
{
    Savings,
    Current
};
ostream &operator<<(ostream &out, const ac_type &obj)
{
    switch (obj)
    {
    case 0:
        out << "Savings";
        break;
    case 1:
        out << "Current";
        break;
    default:
        break;
    }
    return out;
}
class basic_details
{
protected:
    char fname[15];
    char lname[15];
    unsigned long long int phone;
    date_type dob;
    char res_city[15];
    char email[30];

public:
    basic_details()
    {
        strcpy(fname, "");
        strcpy(lname, "");
        phone = 0;
        dob = date_type(0, 0, 0);
        strcpy(res_city, "");
        strcpy(email, "");
    }
    void input_name()
    {
        cout << left1 << "Enter First Name";
        cin >> fname;
        cout << left1 << "Enter Last Name";
        cin >> lname;
    }
    void input_phone()
    {
        cout << left1 << "Enter Phone";
    Enter_phone:
        cin >> phone;
        if (phone < 999999999 || phone > 9999999999)
        {
            cout << "Invalid Enter Again";
            shift(-19, -1);
            // getch();
            cout << left1 << "Enter Phone Number";
            cout << "                    ";
            shift(-20, 0);
            goto Enter_phone;
        }
        else
        {
            cout << "                    ";
        }
        shift(-20);
    }
    void input_DOB()
    {
        cout << left1 << "DOB___(dd mm yyyy): ";
        cin >> dob;
    }
    void input_city()
    {
        cout << left1 << "Enter City";
        cin >> res_city;
    }
    void input_email()
    {
        cout << left1 << "Enter Email Id";
        cin >> email;
    }
    const char *get_fname() { return fname; }
    const char *get_lname() { return lname; }
    long long int get_phone() { return phone; }
    date_type get_DOB() { return dob; }
    const char *get_res_city() { return res_city; }
    const char *get_email() { return email; }
};
class Account : public basic_details
{
    unsigned long long int acc_no;
    unsigned long long int passcode;
    double balance;
    date_type created_on;
    ac_type type;

public:
    Account()
    {
        acc_no = 0;
        passcode = 0;
        balance = 0;
        created_on = date_type(0, 0, 0);
        type = Savings;
    }
    /* Account(Account &copy)
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
    } */
    void generate_acc_no()
    {
        time_t time_var;
        unsigned int seedval = (unsigned)time(&time_var);
        srand(seedval);
        acc_no = rand() % (1000) + 100;
        cout << left1 << "Account Number is " << acc_no;
        cout << endl;
    }
    void input_passcode()
    {
        char input[10];
        cout << left1 << "Enter the passcode";
    input_passcode:
        cin >> input;
        if (!isdigit(input[0]))
        {
            cout << "Invalid Enter Again";
            shift(-19, -1);
            getch1();
            cout << left1 << "Enter the passcode";
            cout << "          ";
            shift(-10, 0);
        }
        else
        {
            passcode = atoi(input);
        }
    }
    void show_balance()
    {
        cout << left1 << "Current Balance" << currency << balance;
        cout << endl;
    }
    void input_creation_date()
    {
        cout << left1 << "Opening Date(dd mm yy):";
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        created_on.year = 1900 + local_time->tm_year;
        created_on.month = 1 + local_time->tm_mon;
        created_on.date = local_time->tm_mday;
        cout << created_on;
    }
    void input_type()
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
            getch1();
            cout << left1 << "Type (0 for Savings, 1 for Current)";
            cout << "\t\t\t";
            shift(-24, 0);
            goto Enter_type;
        }
    }
    unsigned long long int get_acc_no() { return acc_no; }
    unsigned long long int get_passcode() { return passcode; }
    double get_balance() { return balance; }
    date_type get_created_on() { return created_on; }
    ac_type get_ac_type() { return type; }
    void add_into_balance(double amt, int hide = 0)
    {
        balance += fabs(amt);
        if (hide == 0)
            cout << "\nAmount Added Successfully";
    }
    int sub_from_balance(double amt)
    {
        amt = fabs(amt);
        if (balance - amt >= 0)
        {
            balance -= amt;
            cout << "\nAmount Withdrawn Successfully";
            return 1;
        }
        else
            cout << "\nWithdrawn Cancelled"
                 << "\nBalance Not Sufficient\n";
        return 0;
    }
    friend int operator==(Account check, Account check2)
    {

        if (check.acc_no == check2.acc_no &&
            (check.passcode == check2.passcode))
        {
            return 1;
        }
        else if (!strcmpi(check.fname, check2.fname) &&
                 !strcmpi(check.lname, check2.lname) &&
                 check.phone == check2.phone &&
                 check.dob == check2.dob)
        {
            return 1;
        }
        return 0;
    }
    friend ostream &operator<=(ostream &out, Account temp)
    {
        out << endl
            << left1 << "Basic Details\t" << endl
            << endl
            << message << "First Name" << temp.fname << endl
            << message << "Last Name" << temp.lname << endl
            << message << "Phone" << temp.phone << endl
            << message << "Date of Birth"
            << temp.dob.date << '/' << temp.dob.month << '/' << temp.dob.year << endl
            << message << "Residing City" << temp.res_city << endl
            << message << "Email" << temp.email << endl
            << endl
            << left1 << "Account Details\t" << endl
            << endl
            << message << "Account Number" << temp.acc_no << endl
            // << message << "" << temp.passcode << endl
            << message << "Balance" << temp.balance << endl
            << message << "Type" << temp.type << endl
            << message << "Created on"
            << temp.created_on.date << '/' << temp.created_on.month << '/' << temp.created_on.year << endl;
        return out;
    }
    void create_account();
    void show_account_details();
    void update_details();
} logged_in_user;
void Account::create_account()
{
    cout << endl;
    this->input_name();
    this->input_email();
    this->input_phone();
    this->input_DOB();
    this->input_city();
    cout << "\n\t====Basic Details taken====\t\n";
    cout << endl;
    this->generate_acc_no();
    this->input_passcode();
    this->show_balance();
    this->input_type();
    this->input_creation_date();
    {
        ofstream file("bug.txt", ios::out | ios::app);
        file << acc_no << ":"
             << passcode << ":"
             << phone << ":"
             << fname << ":"
             << lname << ":"
             << email << ":"
             << res_city << ":"
             << type << ":"
             << dob << ":"
             << created_on << "\n";
    }
}
void Account::show_account_details()
{
    // system("cls");
    cout << endl
         << endl;
    cout << left1 << "First Name" << fname << endl;
    cout << left1 << "Last Name" << lname << endl;
    cout << left1 << "Email ID" << email << endl;
    cout << left1 << "Phone Number " << phone << endl;
    cout << left1 << "Residing City" << res_city << endl;
    cout << left1 << "Date_of_Birth___:" << dob << endl;
    cout << left1 << "Account Number" << acc_no << endl;
    // cout << "passcode" << passcode << endl;
    cout << left1 << "Balance" << currency << balance << endl;
    cout << left1 << "Type" << type << endl;
    cout << left1 << "Account_Opening_:" << created_on << endl;
}
void Account::update_details()
{
    int choice = -1;
    do
    {
        system("cls");
        cout << "1.Update Name" << endl
             << "2.Update Email ID" << endl
             << "3.Update Phone Number" << endl
             << "4.Update DOB" << endl
             << "5.Update City" << endl
             << "6.Update Passcode" << endl
             << "7.Update Type" << endl
             << "0.Exit" << endl
             << "\nEnter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:

            this->input_name();
            break;
        case 2:
            this->input_email();
            break;
        case 3:
            this->input_phone();
            break;
        case 4:
            this->input_DOB();
            break;
        case 5:
            this->input_city();
            break;
        case 6:
            this->input_passcode();
            break;
        case 7:
            this->input_type();
            break;
        default:
            break;
        }
        // getch1();
    } while (choice != 0);
}
int login_user()
{
    unsigned long long acc_no, input;
    int flag = 0;
    Account temp;
    ifstream file;

    file.open("Account_data.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\nFile not Found";
        file.close();
        getch1();
        return 0;
    }
    cout << endl;
    cout << left1 << "Enter Account Number : ";
    cin >> acc_no;
    cout << left1 << "Enter Passcode :";
    cin >> input;
    while (!file.eof())
    {
        file.read((char *)&temp, sizeof(temp));
        if (temp.get_acc_no() == acc_no && temp.get_passcode() == input)
        {
            logged_in_user = temp;
            flag = 1;
        }
    }
    file.close();
    return flag;
}
int save_into_file(Account save)
{
    Account temp;
    int flag = 0;
    long pos = -1;
    fstream file;
    file.open("Account_data.dat", ios::out | ios::in | ios::binary);
    if (!file)
    {
        cout << "\nFile not Found";
        file.close();
        file.open("Account_data.dat", ios::out | ios::binary);
        file.write((char *)&save, sizeof(save));
        file.close();
        cout << "\nAdded New Record";
        return 1;
    }
    while (!file.eof())
    {
        pos = file.tellg();
        file.read((char *)&temp, sizeof(temp));
        // temp.show_account_details();
        if (temp == save)
        {
            flag = 1;
            // cout << "\n\nAccount found";
            break;
        }
    }
    if (flag == 0)
    {
        file.close();
        file.open("Account_data.dat", ios::out | ios::app | ios::binary);
        cout << "\n\nAccount NOT found, writing at last";
        file.write((char *)&save, sizeof(save));
        file.close();
    }
    if (flag == 1)
    {
        // file.open("Account_data.dat", ios::out | ios::binary);
        file.seekp(pos);
        file.write((char *)&save, sizeof(save));
        file.close();
        cout << "\nSaved Record in file";
    }

    return flag;
}
int search()
{
    int choice;
    Account temp;
    int flag = 0;
    unsigned long long int input, acno;
    date_type input_date;
    system("cls");
    cout << "1.Search Using account number - phone number " << endl
         << "2.Search Using account number - creation date " << endl
         << "\nEnter Choice : ";
    cin >> choice;
    cout << "\n";
    switch (choice)
    {
    case 1:
        cout << left1 << "Enter Acc_no";
        cin >> acno;
        cout << left1 << "Enter Phone number";
        cin >> input;
        break;
    case 2:
        cout << left1 << "Enter Acc_no";
        cin >> acno;
        cout << left1 << "Creation Date (dd mm yyyy) :";
        cin >> input_date;
        break;
    default:
        break;
    }
    ifstream file("Account_data.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\nFile not Found";

        getch1();
        return 0;
    }
    // file.read((char *)&temp, sizeof(temp));
    while (!file.eof())
    {
        if ((temp.get_acc_no() == acno &&
             (temp.get_phone() == input || temp.get_created_on() == input_date)))
        {
            cout << "\nPassword has been sent on your Email and Phone";
            cout << "\nOTP or Email generation is not possible at this moment"
                 << "\nWait Untill Next Update";
            getch1();
            cout << "\nFor Now Password to Login is " << temp.get_passcode();
            getch1();
            flag = 1;
            break;
        }
        file.read((char *)&temp, sizeof(temp));
    }
    if (flag == 0)
    {
        cout << endl
             << "Record Not Found !";
        getch1();
        file.close();
        return 0;
    }
    else if (flag == 1)
    {
        file.close();
        return 1;
    }
    return 0;
}
int delete_from_file(Account obj)
{
    char choice;
    long pos = 0;
    Account temp;
    int flag = 0;
    fstream file, file1;
    cout << "\nConfirm delete (Y/N)? :";
    cin >> choice;
    file.open("Account_data.dat", ios::in | ios::binary);
    file1.open("temp.dat", ios::out | ios::binary);
    while (!file.eof())
    {
        file.read((char *)&temp, sizeof(temp));
        if (temp.get_acc_no() == obj.get_acc_no() &&
            temp.get_passcode() == obj.get_passcode())
        {
            temp.show_account_details();
            if (choice == 'y' || choice == 'Y')
            {
                cout << "\nDeleted\n";
                flag = 1;
            }
            else
            {
                file1.write((char *)&temp, sizeof(temp));
            }
        }
    }
    if (flag == 0)
        cout << "\nRecord Not Found";

    file1.close();
    remove("Account_data.dat");
    rename("temp.dat", "Account_data.dat");
    return flag;
}
int fund_transfer(double amt, unsigned long long int acno)
{
    Account temp;
    int flag = 0;
    long pos;

    fstream file;
    file.open("Account_data.dat", ios::out | ios::in | ios::binary);
    if (!file)
    {
        cout << "\nFile not Found";
        getch1();
        return 0;
    }
    while (!file.eof())
    {
        pos = file.tellg();
        file.read((char *)&temp, sizeof(temp));
        if (temp.get_acc_no() == acno)
        {
            temp.add_into_balance(amt);
            // temp.show_account_details();
            // file.open("Account_data.dat", ios::out | ios::binary);
            file.seekp(pos);
            file.write((char *)&temp, sizeof(temp));
            file.close();
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "\nTransfered Successfully";

        return 1;
    }
    if (flag == 0)
    {
        cout << "\nTransfer Un_Successful"
             << "\n\tAccount not found";
        return 0;
    }
    return 0;
}
void transaction(int choice, string param = "")
{
    time_t time_var = time(nullptr);
    string timestamp = string(asctime(localtime(&time_var)));
    timestamp = timestamp.substr(0, timestamp.size() - 1);

    string msg, msg1, buffer1;
    char buffer[10];
    itoa(logged_in_user.get_acc_no(), buffer, 10);
    buffer1 = string(buffer);
    buffer1.append("        ");
    buffer1.resize(11);
    msg += buffer1;
    msg += "  ";
    msg += '[' + timestamp + ']';
    msg += " ";
    switch (choice)
    {
    case 1:
        msg1 = "Viewed Account Details";
        break;
    case 2:
        msg1 = "Updated Account Details";
        break;
    case 3:
        msg1 = "Deleted Account";
        break;
    case 4:
        msg1 = "Checked Balance";
        break;
    case 5:
        msg1 = "Deposited Amount";
        break;
    case 6:
        msg1 = "Withdrawn Amount";
        break;
    case 7:
        msg1 = "Mini Statement Requested";
        break;
    case 8:
        msg1 = "Transfered Fund";
        break;
    case 9:
        msg1 = "Viewed History";
        break;
    case 10:
        msg1 = "Opened Fixed Deposit";
        break;
    case 11:
        msg1 = "Viewed FD status";
        break;
    default:
        break;
    }
    msg1 += " ";
    msg1 += param;
    msg.append(msg1);
    fstream file;
    file.open("Transactions.txt", ios::out | ios::app);
    if (!file)
        cout << "Transaction file not found";
    file << msg.c_str() << '\n';
    file.close();
}
int view_history(unsigned long long acno)
{
    long long int ac;
    fstream file;
    file.open("Transactions.txt", ios::in);
    if (!file)
    {
        cout << "\nFile not Found";
        return 0;
    }
    char msg[71];
    char msg1[20];
    cout.setf(ios::left);
    cout << "\n"
         << setw(12) << "AcNo"
         << "|" << setw(4) << "" << setw(22) << "TIMESTAMP"
         << "|" << setw(4) << "" << setw(24) << "DETAILS"
         << "\n\n";
    file.getline(msg, 70, '\n');
    strncpy(msg1, msg, 11);
    strcat(msg1, "\0");
    cout.unsetf(ios::left);
    ac = atoll(msg1);
    do
    {
        if (ac == acno)
        {
            cout << msg << endl;
        }
        file.getline(msg, 70, '\n');
        if (!strcmp(msg, ""))
        {
            break;
        }
    } while (!file.eof());

    return 0;
}
void mini_statement()
{
    time_t time_var = time(nullptr);
    string timestamp = string(asctime(localtime(&time_var)));
    timestamp = timestamp.substr(0, timestamp.size() - 1);
    cout << "\nMini statement for : "
         << timestamp.substr(0, 10) + " " + timestamp.substr(20, 25) << endl;
    cout << "\n";
    // logged_in_user.show_account_details();
    cout <= logged_in_user;
    cout << "\nFixed Deposits =======\n";
    cout.fill('_');
    view_fd();
    cout << "\nHistory of Account =======\n";
    cout.fill('_');
    view_history(logged_in_user.get_acc_no());
}
int refresh()
{
    Account temp;
    ifstream file;

    file.open("Account_data.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\nFile not Found";

        getch1();
        return 0;
    }
    while (!file.eof())
    {
        file.read((char *)&temp, sizeof(temp));
        if (temp.get_acc_no() == logged_in_user.get_acc_no() && temp.get_passcode() == logged_in_user.get_passcode())
        {
            logged_in_user = temp;
        }
    }

    return 1;
}
class fd
{
    char fname[10];
    char lname[10];
    long long int fd_no = 0;
    float fd_principle = 0;
    float fd_rate = 0;
    int fd_time = 0;
    long long int acno = 0;
    date_type open_date;
    date_type maturity_date;

public:
    friend int fixed_deposit();
    friend int view_fd();
    void view()
    {
        cout.setf(ios::left);

        char buffer[5];
        char msg[12];
        char msg1[12];
        itoa(open_date.date, msg, 10);
        strcat(msg, "/");
        itoa(open_date.month, buffer, 10);
        strcat(msg, buffer);
        strcat(msg, "/");
        itoa(open_date.year, buffer, 10);
        strcat(msg, buffer);
        // strcat(msg, "/");

        itoa(maturity_date.date, msg1, 10);
        strcat(msg1, "/");
        itoa(maturity_date.month, buffer, 10);
        strcat(msg1, buffer);
        strcat(msg1, "/");
        itoa(maturity_date.year, buffer, 10);
        strcat(msg1, buffer);
        // strcat(msg1, "/");

        cout.fill(' ');
        cout << setw(06) << fd_no
             << setw(13) << acno
             << setw(11) << fname
             << setw(10) << lname
             << setw(16) << fd_principle
             << setw(07) << fd_rate
             << setw(13) << msg
             << setw(14) << msg1
             << setw(16) << calc_amt();
        cout << "\n";
        cout.fill('_');
    }
    float calc_amt()
    {
        return float((fd_principle * fd_rate * fd_time) + fd_principle);
    }
} fd_var;
int fixed_deposit()
{
    int choice = 0;
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    unsigned int seedval = (unsigned)time(&ttime);
    srand(seedval);
    fd_var.fd_no = rand() % 100 + 100;
    fd_var.acno = logged_in_user.get_acc_no();
    strcpy(fd_var.fname, logged_in_user.get_fname());
    strcpy(fd_var.lname, logged_in_user.get_lname());

    fd_var.open_date.year = 1900 + local_time->tm_year;
    fd_var.open_date.month = 1 + local_time->tm_mon;
    fd_var.open_date.date = local_time->tm_mday;

    fd_var.maturity_date.month = 1 + local_time->tm_mon;
    fd_var.maturity_date.date = local_time->tm_mday;

    do
    {
        // system("cls");
        cout << "\nSelect Plan:\n"
             << "\n1.Fd For 12 Month Intrest rate is 6.0 % "
             << "\n2.Fd For 24 Month Intrest rate is 8.0 % "
             << "\n3.Fd For 36 Month Intrest rate is 10.0 % "
             << "\n\n Enter Choice : ";
        cin >> choice;
    } while (choice != 1 && choice != 2 && choice != 3);
    cout << "\nEnter Amount : ";
    cin >> fd_var.fd_principle;
    if (logged_in_user.sub_from_balance(fd_var.fd_principle))
    {
        cout << "\nAmount added into fixed Deposit";
        save_into_file(logged_in_user);
    }
    else
    {
        logged_in_user.add_into_balance(fd_var.fd_principle, 1);
        cout << "\nDeposit unsuccessful";
        return 0;
    }

    if (choice == 1)
    {
        fd_var.fd_rate = 0.06;
        fd_var.fd_time = 1;
        fd_var.maturity_date.year = 1900 + local_time->tm_year + 1;
    }
    else if (choice == 2)
    {
        fd_var.fd_rate = 0.08;
        fd_var.fd_time = 2;
        fd_var.maturity_date.year = 1900 + local_time->tm_year + 2;
    }
    else if (choice == 3)
    {
        fd_var.fd_rate = 0.1;
        fd_var.fd_time = 3;
        fd_var.maturity_date.year = 1900 + local_time->tm_year + 3;
    }
    fstream file("FixedDeposit.dat", ios::out | ios::app | ios::binary);
    if (!file)
    {
        cout << "\nFile Not Found";
        // return 0;
    }
    file.write((char *)&fd_var, sizeof(fd_var));
    file.close();

    return 1;
}
int view_fd()
{
    fstream file("FixedDeposit.dat", ios::in | ios::binary);
    if (!file)
    {
        cout << "\nFile Not Found";
        return 0;
    }
    cout << "\nFD no"
         << "|"
         << setw(12) << "Ac_no"
         << "|"
         << "First Name"
         << "|"
         << "Last Name"
         << "|"
         << "Amount Invested"
         << "|"
         << "Rate  "
         << "|"
         << "Opening Date"
         << "|"
         << "Maturity Date"
         << "|"
         << "Expected Amount\n\n";
    file.read((char *)&fd_var, sizeof(fd_var));
    do
    {
        if (fd_var.acno == logged_in_user.get_acc_no())
        {
            fd_var.view();
        }
        file.read((char *)&fd_var, sizeof(fd_var));
    } while (!file.eof());
    return 1;
}
int menu()
{
    int choice = 0;
    double amt;
    unsigned long long int acno;
    char buffer[20];
    do
    {
        amt = 0;
        acno = 0;
        choice = 0;
        system("cls");
        cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
        cout << "\n| Bank management System |" << endl;
        cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
        cout << "\nWELCOME TO THE MAIN MENU\n\n";
        cout << "1.Show Account Details" << endl
             << "2.Update Account details" << endl
             << "3.Delete Existing Account " << endl
             << "4.Get balance of Account" << endl
             << "5.Deposit money in Account " << endl
             << "6.Withdraw from Account " << endl
             << "7.Get a Mini Statement " << endl
             << "8.Transfer Fund" << endl
             << "9.View History" << endl
             << "10.Create FD" << endl
             << "11.View FD" << endl
             << "0.Exit\n\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            logged_in_user.show_account_details();
            transaction(choice);
            break;
        case 2:
            logged_in_user.update_details();
            save_into_file(logged_in_user);
            transaction(choice);
            break;
        case 3:
            delete_from_file(logged_in_user);
            transaction(choice);
            choice = 0;
            break;
        case 4:
            logged_in_user.show_balance();
            transaction(choice);
            break;
        case 5:
            cout << endl
                 << left1 << "Enter Amount :";
            cin >> amt;
            itoa(amt, buffer, 10);
            logged_in_user.add_into_balance(amt);
            save_into_file(logged_in_user);
            transaction(choice, buffer);
            break;
        case 6:
            cout << endl
                 << left1 << "Enter Amount :";
            cin >> amt;
            itoa(amt, buffer, 10);
            if (logged_in_user.sub_from_balance(amt))
            {
                save_into_file(logged_in_user);
            }
            else
                strcat(buffer, " Bounced!");
            transaction(choice, buffer);
            break;
        case 7:
            system("cls");
            mini_statement();
            transaction(choice);
            break;
        case 8:
            cout << endl
                 << left1 << "Enter Amount : ";
            cin >> amt;
            cout << endl
                 << left1 << "Enter Receiptent Acc_no : ";
            cin >> acno;
            itoa(amt, buffer, 10);
            strcat(buffer, " to ");
            char temp[10];
            itoa(acno, temp, 10);
            strcat(buffer, temp);
            if (logged_in_user.sub_from_balance((amt)))
            {
                save_into_file(logged_in_user);
                if (fund_transfer(amt, acno))
                {
                    cout << "\nFund Transfered\n";
                }
                else
                {
                    cout << "\nTransaction Un_Successful"
                         << "\nAmount Deposited Back\n";
                    logged_in_user.add_into_balance(amt);
                    save_into_file(logged_in_user);
                }
            }
            else
                strcat(buffer, " Bounced! ");
            transaction(choice, buffer);
            break;
        case 9:
            transaction(choice);
            view_history(logged_in_user.get_acc_no());
            break;
        case 10:
            fixed_deposit();
            transaction(choice);
            break;
        case 11:
            view_fd();
            transaction(choice);
            break;
        default:
            break;
        }
        getch1();
        refresh();
    } while (choice != 0);
    return 0;
}
int main()
{
    int choice;
    Account temp;

    do
    {
        system("cls");
        logged_in_user = Account();

        cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
        cout << "\n| Bank management System |" << endl;
        cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;

        cout << endl
             << "1.Login To your Account." << endl
             << "2.Open An Account." << endl
             << "3.Forgot Passcode" << endl
             << "0.Exit";

        cout << "\n\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            login_user() == 1 ? cout << "\nLogin Successful"
                                     << getch1()
                                     << menu()
                              : cout << "\nLogin Un_Successful" << getch1();
            break;
        case 2:
            temp.create_account();
            save_into_file(temp);
            getch1();
            break;
        case 3:
            search();
            getch1();
            break;
        }
    } while (choice != 0);
    return 0;
}
