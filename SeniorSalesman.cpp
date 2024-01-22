#include "SeniorSalesman.h"

SeniorSalesman::SeniorSalesman(string n, string i, int j, int s) :JuniorSalesman(n, i, j, s)
{
	cancels = NULL;
	size = 0;
}

float SeniorSalesman::salary()
{
	return JuniorSalesman::salary() * 1.5;
}

void SeniorSalesman::operator-=(int cancel)
{
	int* temp = new int[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = cancels[i];
	temp[size++] = cancel;
	delete cancels;
	cancels = temp;
}

void SeniorSalesman::print()
{
	JuniorSalesman::print();
	cout << "Returns: ";
	for (int i = 0; i < size; i++)
		cout << cancels[i] << " ";
	cout << endl;
}
