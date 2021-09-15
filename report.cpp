#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include "report.h"
#include "transaction.h"

using namespace std;

//addmoney method
void report::addmoney() {
	transaction newtransaction;
	newtransaction.set_typeof("Income");
	newtransaction.input();
	records.push_back(newtransaction);
}

//spendmoney method
void report::spendmoney() {
	transaction newtransaction;
	newtransaction.set_typeof("Expense");
	newtransaction.input();
	records.push_back(newtransaction);
}

//report on transactions
void report::diffreport() {
	float sum = 0;

	cout << left << setw(15) << "Type" << setw(30) << "Description" << setw(20) << "Amount" << "Date" << endl;
	for (auto i : records) {
		i.show_table();
		sum += i.amount_getter();	//fix needed
	}

	cout << "\nAnd your leftover money amount: " << sum << endl;

	if (sum <= 0) {
		cout << "You wasted all of your money! :(\n" << endl;
	}
	else {
		cout << "Spare money left!\n" << endl;
	}
}

//sortedreport, method for reports that have some kind of sorting
void report::sortedreport() {
	cout << "Choose an option from below: " << endl;
	cout << "1. All transactions in one listing" << endl;
	cout << "2. Expenses first then income" << endl;
	cout << "3. Income first then expenses" << endl;
	cout << "Enter a number to choose: ";

	int option = 0;
	
	cin >> option;
	cin.clear();
	cin.ignore();

	if (option == 1) {
		cout << left << setw(15) << "Type" << setw(30) << "Description" << setw(20) << "Amount" << "Date" << endl;
		for (auto i : records) {
			i.show_table();
		}
	}
	else if (option == 2) {
		cout << left << setw(15) << "Type" << setw(30) << "Description" << setw(20) << "Amount" << "Date" << endl;
		for (auto i : records) {
			if (i.get_typeof() == "Expense") {
				i.show_table();
			}
		}

		for (auto i : records) {
			if (i.get_typeof() == "Income") {
				i.show_table();
			}
		}
	}
	else if (option == 3) {
		cout << left << setw(15) << "Type" << setw(30) << "Description" << setw(20) << "Amount" << "Date" << endl;
		for (auto i : records) {
			if (i.get_typeof() == "Income") {
				i.show_table();
			}
		}

		for (auto i : records) {
			if (i.get_typeof() == "Expense") {
				i.show_table();
			}
		}
	}
	else {
		cout << "\n\nInvalid input, try again\n" << endl;
	}
}

//method that saves the file
void report::savefile() {
	ofstream file;

	file.open("records.txt", ios::app);
	for (auto i : records) {
		file << i;
	}
	file.close();
	cout << "Saved successfully!" << endl;
}

//method for reading the file
void report::readfile() {
	ifstream file;
	transaction tr;

	if (!file) {
		cout << "Unable to open the file." << endl;
	}

	file.open("records.txt");
	while (file >> tr) {
		records.push_back(tr);
	}
	file.close();
	cout << "File read successfully!" << endl;
	cout << "If you have emptied the file before, it will be empty now." << endl;
}

//method for clearing the vector
void report::clearvector() {
	char answer;

	cout << "Are you sure you want to clear the records? Answer (y/n): ";
	cin >> answer;
	cin.clear();
	cin.ignore();
	if (answer == 'y') {
		records.clear();
	}
	else if (answer == 'n') {

	}
	else {
		cout << "\n\nInvalid input, try again\n" << endl;
	}
}

//method that clears the file
void report::clearfile() {
	ofstream file;
	char answer;

	cout << "Would you like to clear the file too? Answer (y/n): ";
	cin >> answer;
	cin.clear();
	cin.ignore();
	if (answer == 'y') {
		file.open("records.txt");
		file << " ";
		file.close();
	}
	else if (answer == 'n') {

	}
	else {
		cout << "\n\nInvalid input, try again\n" << endl;
	}
}