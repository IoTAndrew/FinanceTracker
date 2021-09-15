#pragma once
#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>

//declaration of the transaction class
class transaction
{
public:
	transaction(std::string typeof0 = " ", std::string description0 = " ", float amount0 = 0, std::string date0 = " ", float coefficient0 = 0.0);

	void input();
	void set_typeof(std::string type);
	std::string get_typeof();
	void show_table();
	float amount_getter(); //return an amount based on type of transaction

	friend std::ostream& operator<<(std::ostream& out, const transaction& tr);
	friend std::istream& operator>>(std::istream& in, transaction& tr);

private:
	std::string typeof;
	std::string description;
	float amount;
	std::string date;
	float coefficient; //the coefficient determines whether the income exceeded the expenses or not
};



#endif