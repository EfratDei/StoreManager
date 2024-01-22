#include "Worker.h"

Worker::Worker(string n, string i, int j, int s)
{
	name = n;
	id = i;
	job = j;
	basicSalary = s;
}

bool Worker::operator==(Worker* w)
{
	return id == w->id;
}

bool Worker::operator==(string eid)
{
	return eid == id;
}

void Worker::print()
{
	cout << "Name: " << name << " ID: " << id << " Job Percentage: " << (float)job / 100 << endl;
}
