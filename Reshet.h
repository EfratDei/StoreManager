#pragma once
#include "Shop.h"

class Reshet {
private:
	string name;
	Shop** shops;
	int size;
public:
	Reshet(string);
	virtual ~Reshet() = 0;
	void operator+=(Shop*);
	bool operator==(string);
	Shop* operator[](int);
	Worker* operator[](string);
	virtual void print();
	int sumSalaries();
};