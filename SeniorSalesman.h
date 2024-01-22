#pragma once
#include "JuniorSalesman.h"

class SeniorSalesman :public JuniorSalesman {
private:
	int* cancels;
	int size;
public:
	SeniorSalesman(string, string, int, int);
	float salary();
	void operator-=(int);
	void print();
};