#include "ReshetF.h"

ReshetF::ReshetF(string name, int s):Reshet(name)
{
	suppliers = s;
}

void ReshetF::print()
{
	Reshet::print();
	cout << "Number of suppliers: " << suppliers << endl;
}
