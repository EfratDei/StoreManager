#pragma once
#include "Worker.h"

class Kupa :public Worker {
private:
	int number;
public:
	Kupa(string, string, int, int);
	float salary();
	void operator++();
	void print();
};