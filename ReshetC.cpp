#include "ReshetC.h"

ReshetC::ReshetC(string name, string s):Reshet(name)
{
	supplier = s;
}

void ReshetC::print()
{
	Reshet::print();
	cout << "Supplier name: " << supplier << endl;
}
