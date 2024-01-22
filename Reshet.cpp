#include "Reshet.h"

Reshet::Reshet(string n)
{
	name = n;
	shops = NULL;
	size = 0;
}

Reshet::~Reshet()
{
	if (shops)
		delete shops;
}

void Reshet::operator+=(Shop* shop)
{
	for(int i=0;i<size;i++)
		if (*shop == *(shops[i])) {
			cout << "This shop already in reshet." << endl;
			return;
		}
	Shop** temp = new Shop * [size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = shops[i];
	temp[size++] = shop;
	delete shops;
	shops = temp;
	cout << "Shop added successfuly." << endl;
}

bool Reshet::operator==(string name)
{
	return this->name == name;
}

Shop* Reshet::operator[](int sid)
{
	for (int i = 0; i < size; i++)
		if (*(shops[i]) == sid)
			return shops[i];
	return nullptr;
}

Worker* Reshet::operator[](string eid)
{
	for (int i = 0; i < size; i++) {
		Worker* worker = (*(shops[i]))[eid];
		if (worker)
			return worker;
	}
	return nullptr;
}

void Reshet::print()
{
	cout << "Chain name: " << name << endl;
}

int Reshet::sumSalaries()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += shops[i]->sumSalaries();
	return sum;
}
