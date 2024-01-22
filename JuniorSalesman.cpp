#include "JuniorSalesman.h"

JuniorSalesman::JuniorSalesman(string n, string i, int j, int s):Worker(n,i,j,s)
{
	sales = NULL;
	size = 0;
}

JuniorSalesman::~JuniorSalesman()
{
	if (sales)
		delete sales;
}

float JuniorSalesman::salary()
{
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += sales[i];
	return (basicSalary + sum / size + size) * job / 100;
}

void JuniorSalesman::operator+=(int sale)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = sales[i];
	temp[size++] = sale;
	delete sales;
	sales = temp;
}

void JuniorSalesman::print()
{
	Worker::print();
	cout << " Salary: " << salary() << endl << "Sales: ";
	for (int i = 0; i < size; i++)
		cout << sales[i] << " ";
	cout << endl;
	
}
