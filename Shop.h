#pragma once
#include "SeniorSalesman.h"
#include "Kupa.h"
#include "Manager.h"

class Shop {
private:
	int numberShop;
	string name;
	int size;
	Worker** work;
public:
	Shop(int, string);
	bool operator+=(Worker*);
	bool operator==(Shop);
	bool operator==(int);
	Worker* operator[](string);
	int sumSalaries();
	void print();
};
