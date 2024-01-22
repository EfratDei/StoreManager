#pragma once
#include "Worker.h"

class JuniorSalesman :public Worker {
private:
	int* sales;
	int size;
public:
	JuniorSalesman(string, string, int, int);
	~JuniorSalesman();
	float salary();
	void operator+=(int);
	void print();
};