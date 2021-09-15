#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include "report.h"
#include "transaction.h"

using namespace std;

//finance tracker

//main
int main()
{
	int option;
	report Current;
	bool a = true;

	while (a == true) {
		cout << "Hello, please choose an option from the menu: " << endl;
		cout << "1. Initialize (clear all records(and file if needed)). " << endl;
		cout << "2. Save financial records to a file." << endl;
		cout << "3. Read financial records from a file." << endl;
		cout << "4. Add money (income)." << endl;
		cout << "5. Spend money (expense)." << endl;
		cout << "6. Print a report of all transactions with the sum of incomes and expenses at the end." << endl;
		cout << "7. Print a sorted report with sorting of your own choice." << endl;
		cout << "8. Exit the program." << endl;
		cout << "Your option (type in a number): ";

		cin >> option;
		cin.clear();
		cin.ignore();

		switch (option) {
		case 1:
			Current.clearvector();
			Current.clearfile();
			break;
		case 2:
			Current.savefile();
			break;
		case 3:
			Current.readfile();
			break;
		case 4:
			Current.addmoney();
			break;
		case 5:
			Current.spendmoney();
			break;
		case 6:
			Current.diffreport();
			break;
		case 7:
			Current.sortedreport();
			break;
		case 8:
			a = false;
			break;
		default:
			cout << "\n\nInvalid input, try again\n" << endl;
		}
	}
}


