#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
	string name;
	string id;
	int job, basicSalary;
public:
	Worker(string, string, int, int);
	virtual float salary() = 0;
	bool operator==(Worker*);
	bool operator==(string);
	virtual void print();
};