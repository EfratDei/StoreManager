#pragma once
#include "Reshet.h"

class ReshetC :public Reshet {
private:
	string supplier;
public:
	ReshetC(string, string);
	~ReshetC() {};
	void print();
};