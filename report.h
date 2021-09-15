#pragma once
#ifndef REPORT_H_INCLUDED
#define REPORT_H_INCLUDED
#include "transaction.h"
#include <iostream>
#include <iomanip>
#include <istream>
#include <fstream>
#include <vector>

//declaration of the report class
class report {
public:
	void diffreport();
	void sortedreport();
	void addmoney();
	void spendmoney();
	void savefile();
	void readfile();
	void clearvector();
	void clearfile();
private:
	std::vector<transaction> records;
};

#endif