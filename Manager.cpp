#include "Manager.h"

Manager::Manager(string n, string i, int j, int s, int l) :Worker(n, i, j, s)
{
	level = l;
}

float Manager::salary()
{
	return basicSalary * level * job / 100;
}

void Manager::print()
{
	Worker::print();
	cout << " Salary: " << salary() << " Rank: " << level << endl;
}
