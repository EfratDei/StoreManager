#include "Kupa.h"

Kupa::Kupa(string n, string i, int j, int s) :Worker(n, i, j, s)
{
	number = 0;
}

float Kupa::salary()
{
	return (basicSalary + number) * job / 100;
}

void Kupa::operator++()
{
	number++;
}

void Kupa::print()
{
	cout << " Salary: " << salary() << " Actions: " << number << endl;
}
