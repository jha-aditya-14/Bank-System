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
//
#include "user_Account.h"
// Headers Close
using namespace std;

// int center_X = 25;
// int center_Y = 10;
int Acno = 141;

void save_into_file(Account &obj, long pos = -1)
{
	ofstream file;
	file.open("Account_data.dat", ios::out | ios::binary);
	if (pos < 0)
	{
		file.seekp(ios::end);
	}
	else if (pos >= 0)
	{
		file.seekp(pos);
	}
	file.write((char *)&obj, sizeof(obj));
	file.close();
}
void read_from_file(Account &obj, long pos = -1)
{
	ifstream file;
	file.open("Account_data.dat", ios::in | ios::binary);
	file.read((char *)&obj, sizeof(obj));
	while (!file.eof())
	{
		if (pos < 0)
		{
			obj.show_account_details();
			getch();
			file.read((char *)&obj, sizeof(obj));
		}
		else if (file.tellg() == pos)
		{
			obj.show_account_details();
			getch();
			file.read((char *)&obj, sizeof(obj));
			break;
		}
	}
	file.close();
	// return obj;
}
long search(int pass, long long input, int hide = 0)
{
	int flag = 0;
	cout << endl;
	long pos;
	Account obj;
	ifstream file;
	file.open("Account_data.dat", ios::in | ios::binary);
	pos = file.tellg();
	file.read((char *)&obj, sizeof(obj));
	while (!file.eof())
	{
		if (
			obj.get_passcode() == pass &&
			((obj.get_acc_no() == (int)input) || (obj.get_phone() == input)))
		{
			if (!hide)
			{
				cout << "\nAccount Found ";
				cout << "\n\nDetails========\n";
				obj.show_account_details();
			}
			getch();
			flag = 1;
			file.close();
			return pos;
		}
		pos = file.tellg();
		file.read((char *)&obj, sizeof(obj));
	}
	if (flag == 0)
	{
		if (!hide)
		{
			cout << endl
				 << left1 << "Record Not Found";
			getch();
		}
		file.close();
	}
	return -1;
}
long search(int hide = 0)
{
	int pass;
	int choice;
	long long int input;
	system("cls");
	cout << "1.Search Using passcode - account number" << endl
		 << "2.Search Using passcode - phone number" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << left1 << "Enter Acc_no";
		cin >> input;
		cout << left1 << "Enter Passcode";
		cin >> pass;
		break;
	case 2:
		cout << left1 << "Enter Phone number";
		cin >> input;
		cout << left1 << "Enter Passcode";
		cin >> pass;
		break;
	}
	return search(pass, input, hide);
}
int delete_from_file()
{
	// int pass, input;
	char choice;
	long int del_pos;
	long int read_pos;
	del_pos = search();
	cout << del_pos;
	if (del_pos < 0)
	{
		return 0;
	}
	Account obj;
	fstream file, file1;
	file.open("Account_data.dat", ios::in | ios::binary);
	file1.open("Account_data1.dat", ios::out | ios::binary);
	// file1.open("Account_data.dat", ios::out | ios::binary);
	cout << "\nConfirm delete";
	cin >> choice;
	read_pos = file.tellg();
	file.read((char *)&obj, sizeof(obj));
	while (!file.eof())
	{
		if ((choice == 'y' || choice == 'Y') && (del_pos == read_pos))
		{
			cout << "\nDeleted\n";
			getch();
		}
		else
		{
			file1.write((char *)&obj, sizeof(obj));
		}
		read_pos = file.tellg();
		file.read((char *)&obj, sizeof(obj));
	}
	file.close();
	file1.close();
	remove("Account_data.dat");
	rename("Account_data1.dat", "Account_data.dat");
	getch();
	return 0;
}
long get_cur_balance()
{
	Account obj;
	long pos = search(1);
	fstream file;
	file.open("Account_data.dat", ios::in | ios::binary);
	file.seekg(pos);
	file.read((char *)&obj, sizeof(obj));
	cout << endl
		 << left1 << "Balance is " << obj.get_balance();
	getch();
	file.close();
	return pos;
}
void add_balance(int flag = 1)
{
	Account obj;
	long amt;
	long pos = search();
	cout << pos;
	if (flag > 0)
	{
		cout << "\n\nEnter Amount to be added : ";
	}
	else
	{
		cout << "\n\nEnter Amount to be deducted : ";
	}
	cin >> amt;
	amt = fabs(amt);
	if (flag < 0)
	{
		amt *= -1;
	}
	fstream file;
	file.open("Account_data.dat", ios::in | ios::out | ios::binary);
	file.seekg(pos);
	file.read((char *)&obj, sizeof(obj));
	obj.add_into_balance(amt);
	cout << endl
		 << left1 << "Balance now is " << obj.get_balance();
	getch();
	file.seekg(pos);
	file.write((char *)&obj, sizeof(obj));
	file.close();
}
void deduct_balance()
{
	add_balance(-1);
}
// void update_details()
void mini_statement()
{
	Account obj;
	long pos = search(1);
	fstream file;
	file.open("Account_data.dat", ios::in | ios::binary);
	file.seekg(pos);
	file.read((char *)&obj, sizeof(obj));
	cout << "\n\t Mini statement for "
		 << "today" << endl;
	cout << "\nAccount Number : " << obj.get_acc_no() << endl;
	cout << "\nTransaction part is incomplete";
	getch();
	file.close();
}
int login_user(int acc_no = 0, int passcode = 0, long long int phone = 0)
{
	fstream file("Login.dat", ios::in | ios::out | ios::binary);
	file.read((char *)&login, sizeof(login));
	while (!file.eof())
	{
		if (login.acc_no == acc_no &&
			(login.passcode == passcode || login.phone == phone))
		{
			file.close();
			return 1;
		}
		file.read((char *)&login, sizeof(login));
	}
	file.close();
	return 0;
}
void fund_transfer()
{
	int acno;
	Account obj;
	long amt;
	long pos;
	cout << "\nEnter Receiptent account no";
	cin >> acno;
	cout << "\nAmount";
	cin >> amt;
	fstream file("Account_data.dat", ios::in | ios::out | ios::binary);
	pos = file.tellg();
	file.read((char *)&obj, sizeof(obj));
	while (!file.eof())
	{
		if (obj.get_acc_no() == acno)
		{
			obj.add_into_balance(amt);
			file.seekg(pos);
			file.write((char *)&obj, sizeof(obj));
		}
		if (obj.get_acc_no() == Acno)
		{
			obj.sub_from_balance(amt);
			file.seekg(pos);
			file.write((char *)&obj, sizeof(obj));
		}
		pos = file.tellg();
		file.read((char *)&obj, sizeof(obj));
	}
	cout << "\nFund Transfered";
}
void menu()
{
	long pos;
	Account obj;
	int choice = 0;
	do
	{
		system("cls");
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
		cout << "| Bank management System|" << endl;
		// cout << "" << endl;
		cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
		cout << "WELCOME TO THE MAIN MENU:\n";
		cout << "1.Create new account" << endl
			 << "2.Show Account Details" << endl
			 << "3.Search within Account Details" << endl
			 << "4.Update account details" << endl
			 << "5.Delete Existing Account " << endl
			 << "6.Get balance of Account" << endl
			 << "7.Add balance into Account " << endl
			 << "8.Withdraw from Account " << endl
			 << "9.Get a Mini Statement " << endl
			 << "10.Transfer Fund" << endl
			 /*<<  "2.Update information of existing account" << endl
			 << "3.For transactions" << endl
			 << "4.Check the details of existing account" << endl
			 << "5.Removing existing account" << endl
			 << "6.View customer's list" << endl*/
			 << "0.Exit\n\n\nEnter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			obj.create_account();
			save_into_file(obj);
			break;
		case 2:
			read_from_file(obj);
			break;
		case 3:
			search();
			break;
		case 4:
			pos = search();
			read_from_file(obj, pos);
			obj.update_details();
			save_into_file(obj, pos);
			break;
		case 5:
			delete_from_file();
			break;
		case 6:
			get_cur_balance();
			break;
		case 7:
			add_balance();
			break;
		case 8:
			deduct_balance();
			break;
		case 9:
			mini_statement();
			break;
		case 10:
			fund_transfer();
			break;
		default:
			break;
		}
	} while (choice != 0);
}
int main()
{
	int ch;
	int acno;
	int pass;
	do
	{
		system("cls");

		cout << "\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
		cout << "\n\t\t| Bank management System      		  |" << endl;
		cout << "" << endl;
		cout << "\n\t\t\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;

		cout << "\n\t 1.Login To your Account.";
		cout << "\n\t 2.Open An Account.";
		cout << "\n\t 3.Help.";
		cout << "\n\t 0.Exit";

		cout << "\n\n\tEnter your choice ::";
		if (cin >> ch)
		{
			switch (ch)
			{
			case 1:
				cout << "\n\t Enter Account Number:";
				cin >> acno;
				cout << "\n\t Enter 4-digit passcode :";
				cin >> pass;
				system("cls");
				if (login_user(acno, pass))
					menu();
				break;
			case 2:
				// createAccount();
				// break;
			default:
				break;
			}
		}

	} while (ch != 0);
	menu();
	return 0;
}
/*	// void SetConsoleColor(WORD COLOR)
	// {
	// 	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	// 	SetConsoleTextAttribute(screen, COLOR);
	// }

	// void gotoxy(int x, int y)
	// {

	// 	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	// 	COORD max_size = GetLargestConsoleWindowSize(screen);
	// 	COORD pos;
	// 	SetConsoleColor(BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	// 	pos.X = (max_size.X - 20) / 2;
	// 	pos.Y = (0);
	// 	SetConsoleCursorPosition(screen, pos);
	// }

	void center(int x = center_X, int y = center_Y)
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		// COORD max_size = GetLargestConsoleWindowSize(screen);
		COORD pos;
		pos.X = x;
		pos.Y = y;
		// pos.X = ((max_size.X * 2 / 5) + x);
		// pos.Y = ((max_size.Y / 3) + y);
		SetConsoleCursorPosition(screen, pos);
	}

	void Color(int color, int j = 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | j);
	}
	int main()
	{
		center();
		cout << "Hello\n";
		system("pause");
	}
*/
/*	// struct date_type
	// {
	// 	int date_type;
	// 	int month;
	// 	int year;
	// };
	// class Account
	// {
	// 	char name[60];
	// 	int acc_no, age;
	// 	char address[60];
	// 	char citizenship[15];
	// 	double phone;
	// 	char acc_type[10];
	// 	float amt;
	// 	date_type dob;
	// 	date_type deposit;
	// 	date_type withdraw;

	// 	float interest(float t, float amount, int rate)
	// 	{
	// 		float SI;
	// 		SI = (rate * t * amount) / 100.0;
	// 		return (SI);
	// 	}
	// };

	// void close(void)
	// {
	// 	cout << "End of the project......";
	// }

	// void menu(void)
	// {
	// 	int choice;
	// 	system("cls");
	// 	center();
	// 	cout << "BANKING MANAGEMENT SYSTEM\n\n\n";
	// 	cout << "WELCOME TO THE MAIN MENU:\n";
	// 	cout << "\n1:Create new Account\n2.Update_type information of existing Account\n3.For transactions\n4.Check the details of existing Account\n5.Removing existing Account\n6.View Account's list\n7.Exit\n\n\n\n\nEnter your choice : ";
	// 	cin >> choice;
	// 	// switch (choice)
	// 	// {
	// 	// case 1:
	// 	// 	new_acc();
	// 	// 	break;
	// 	// case 2:
	// 	// 	edit();
	// 	// 	break;
	// 	// case 3:
	// 	// 	transact();
	// 	// 	break;
	// 	// case 4:
	// 	// 	see();
	// 	// 	break;
	// 	// case 5:
	// 	// 	erase();
	// 	// 	break;
	// 	// case 6:
	// 	// 	view_list();
	// 	// 	break;
	// 	// case 7:
	// 	// 	close();
	// 	// 	break;
	// 	// }
	// }
	// int main_exit;
	// int main()
	// {
	// 	char pass, password("123");
	// 	center(-20, 0);
	// 	cout << "Enter Login Password ... ";
	// 	cin >> pass;
	// 	if (pass.compare(password) == 0)
	// 	{
	// 		cout << "\n\nPassword Match!";
	// 		cout << "\nGoto The Next Step.....";
	// 		menu();
	// 	}
	// 	else
	// 	{
	// 		cout << "\n\nWrong password!!\a\a\a";
	// 	login_try:
	// 		cout << "\nEnter 1 to try again and 0 to exit:";
	// 		cin >> main_exit;
	// 		if (main_exit == 1)
	// 		{
	// 			main();
	// 		}
	// 		else if (main_exit == 0)
	// 		{
	// 			close();
	// 		}
	// 		else
	// 		{
	// 			cout << "\nInvalid!";
	// 			goto login_try;
	// 		}
	// 	}
	// 	return 0;
	// }
*/
