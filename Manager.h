#pragma once
#include "Worker.h"

class Manager :public Worker {
private:
	int level;
public:
	Manager(string, string, int, int, int);
	float salary();
	void print();
};