#include "Shop.h"

Shop::Shop(int id, string n)
{
	numberShop = id;
	name = n;
	size = 0;
	work = NULL;
}

bool Shop::operator+=(Worker* worker)
{
	for(int i=0;i<size;i++)
		if (worker->operator==(work[i])) {
			cout << "This worker already in shop." << endl;
			return false;
		}
	Worker** temp = new Worker * [size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = work[i];
	temp[size++] = worker;
	delete work;
	work = temp;
	return true;
}

bool Shop::operator==(Shop s)
{
	return numberShop == s.numberShop;
}

bool Shop::operator==(int sid)
{
	return numberShop == sid;
}

Worker* Shop::operator[](string eid)
{
	for (int i = 0; i < size; i++)
		if (work[i]->operator==(eid))
			return work[i];
	return nullptr;
}

int Shop::sumSalaries()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += work[i]->salary();
	return sum;
}

void Shop::print()
{
	cout << "Shop id: " << numberShop << endl;
	cout << "Shop chain: " << name << endl;
}
