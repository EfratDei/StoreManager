#pragma once
#include "Reshet.h"

class ReshetF :public Reshet {
private:
	int suppliers;
public:
	ReshetF(string, int);
	~ReshetF() {};
	void print();
};