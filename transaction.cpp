#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>
#include "report.h"
#include "transaction.h"

using namespace std;

//input for transactions
void transaction::input() {
	cout << "Description of transaction(numbers or shortly in words): ";
	cin >> description;

	cin.clear();
	cin.ignore();
	cout << "Amount of money involved: ";
	cin >> amount;
	cin.clear();
	cin.ignore();
	if (amount <= 0) {
		cout << "\n\nYou have entered an incorrect amount. Clear the records manually and try again.\n" << endl;
		return;
	}

	cout << "Date of transaction (any date format): ";
	cin >> date;
}

//type setter
void transaction::set_typeof(string type) {
	typeof = type;
}

//type getter
string transaction::get_typeof() {
	return typeof;
}

//showtable - show data in table form
void transaction::show_table() {
	cout << left << setw(15) << typeof << setw(30) << description << setw(20) << amount << date << endl;
}

//amount getter
float transaction::amount_getter() {
	string type = "Income";

	if (type.compare(typeof) == 0) {
		return amount;
	}
	else {
		return (0 - amount);
	}
}

//operator overloading
ostream& operator<<(ostream& out, const transaction& tr) {
	out << tr.typeof << ' ' << tr.description << "\n" << tr.amount << ' ' << tr.date << ' ' << endl;
	return out;
}

//operator overloading
istream& operator>>(istream& in, transaction& tr) {
	in >> tr.typeof >> tr.description >> tr.amount >> tr.date;
	return in;
}

//initializer list
transaction::transaction(std::string typeof0, std::string description0, float amount0, std::string date0, float coefficient0)
	: typeof(typeof0), description(description0), amount(amount0), date(date0), coefficient(coefficient0) {}