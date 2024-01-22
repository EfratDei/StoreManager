#pragma once
#include "ReshetC.h"
#include "ReshetF.h"

void menu(Reshet**, int);
void addShop(Reshet**, int);
void addEmployee(Reshet**, int);
void addShopping(Reshet**, int);
void returnItem(Reshet**, int);
void printChain(Reshet**, int);
void sumSalariesChain(Reshet**, int);
void sumSalariesShop(Reshet**, int);
void printShop(Reshet**, int);
void printEmployee(Reshet**, int);
Reshet* findReshet(Reshet**, int, string);


int main() {
	Reshet** reshatot = new Reshet * [3];
	reshatot[0] = new ReshetC("Golbary", "Moshe Gabay");
	reshatot[0]->operator+=(new Shop(65,"Golbary"));
	reshatot[1] = new ReshetF("Super Sal", 4);
	reshatot[1]->operator+=(new Shop(3, "Super Sal"));
	reshatot[1]->operator+=(new Shop(81, "Super Sal"));
	reshatot[2] = new ReshetC("TNT", "Ruti Sulemani");
	reshatot[2]->operator+=(new Shop(3, "TNT"));
	menu(reshatot, 3);
}

void menu(Reshet** reshatot, int size) {
	while (true) {
		cout << "1.Add shop" << endl;
		cout << "2.Add employee" << endl;
		cout << "3.Add shopping" << endl;
		cout << "4.Return item" << endl;
		cout << "5.Print chain" << endl;
		cout << "6.Sum salaries chain" << endl;
		cout << "7.Sum salaries shop" << endl;
		cout << "8.Print shop" << endl;
		cout << "9.Print employee" << endl;
		cout << "10.Exit" << endl;
		cout << endl << "Enter your choice:";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1:
			addShop(reshatot, size);
			break;
		case 2:
			addEmployee(reshatot, size);
			break;
		case 3:
			addShopping(reshatot, size);
			break;
		case 4:
			returnItem(reshatot, size);
			break;
		case 5:
			printChain(reshatot, size);
			break;
		case 6:
			sumSalariesChain(reshatot, size);
			break;
		case 7:
			sumSalariesShop(reshatot, size);
			break;
		case 8:
			printShop(reshatot, size);
			break;
		case 9:
			printEmployee(reshatot, size);
			break;
		case 10:
			cout << "Bye bye." << endl;
			exit(1);
		default:
			cout << "Wrong choice." << endl;
		}
	}
}

void addShop(Reshet** reshatot, int size) {
	string chainName;
	int shopID;
	cout << "Enter <chain name> <shop id>" << endl;
	cin >> chainName >> shopID;
	Reshet* reshet = findReshet(reshatot, size, chainName);
	if (reshet)
		*reshet += (new Shop(shopID, chainName));
	else
		cout << "No reshet with such name exists." << endl;
}

void addEmployee(Reshet** reshatot, int size) {
	string ename, eid, cname;
	int jobPercent, salary, sid;
	char type;
	cout << "Enter <name> <id> <type> <%job> <salary> <chain name> <shop id>" << endl;
	cout << "Allowed types: A- Manager, B - SeniorSalesman, C - JuniorSalesman, D - Kupa " << endl;
	cin >> ename >> eid >> type >> jobPercent >> salary >> cname >> sid;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		Shop* shop = (*reshet)[sid];
		if (shop) {
			Worker* worker;
			switch (type) {
			case 'A':
				worker = new Manager(ename, eid, jobPercent, salary, 1);
				break;
			case 'B':
				worker = new SeniorSalesman(ename, eid, jobPercent, salary);
				break;
			case 'C':
				worker = new JuniorSalesman(ename, eid, jobPercent, salary);
				break;
			case 'D':
				worker = new Kupa(ename, eid, jobPercent, salary);
				break;
			default:
				cout << "No such type." << endl;
				return;
			}
			*shop += (worker);
		}
		else
			cout << "No such store in this reshet." << endl;
	}
	else
		cout << "No such reshet." << endl;
}

void addShopping(Reshet** reshatot, int size) {
	int sid, value;
	string cname, eid;
	cout << "Enter <shop id> <chain name> <value> <employee id>:";
	cin >> sid >> cname >> value >> eid;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		Shop* shop = (*reshet)[sid];
		if (shop) {
			Worker* worker = (*shop)[eid];
			if (worker) {
				JuniorSalesman* junior = dynamic_cast<JuniorSalesman*>(worker);
				if (junior) {
					*junior += value;
					cout << "Shopping added successfuly." << endl;
				}
				else
					cout << "This worker can't do this action." << endl;
			}
			else
				cout << "Couldn't find this worker at this store." << endl;
		}
		else
			cout << "Couldn't find this shop at this reshet." << endl;
	}
	else
		cout << "Couldn't find this reshet." << endl;
}

void returnItem(Reshet** reshatot, int size) {
	int sid, value;
	string cname, eid;
	cout << "Enter <shop id> <chain name> <value> <employee id>:";
	cin >> sid >> cname >> value >> eid;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		Shop* shop = (*reshet)[sid];
		if (shop) {
			Worker* worker = (*shop)[eid];
			if (worker) {
				SeniorSalesman* senior = dynamic_cast<SeniorSalesman*>(worker);
				if (senior) {
					*senior -= value;
					cout << "Item returned successfuly." << endl;
				}
				else
					cout << "This worker can't do this action." << endl;
			}
			else
				cout << "Couldn't find this worker at this store." << endl;
		}
		else
			cout << "Couldn't find this shop at this reshet." << endl;
	}
	else
		cout << "Couldn't find this reshet." << endl;
}

void printChain(Reshet** reshatot, int size) {
	string cname;
	cout << "Enter <chain name>:";
	cin >> cname;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		reshet->print();
	}
	else
		cout << "Couldn't find this reshet." << endl;
}

void sumSalariesChain(Reshet** reshatot, int size) {
	string cname;
	cout << "Enter <chain name>:";
	cin >> cname;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		cout << cname << " salaries: " << reshet->sumSalaries() << endl;
	}
	else
		cout << "Couldn't find this reshet." << endl;
}

void sumSalariesShop(Reshet** reshatot, int size) {
	int sid;
	string cname;
	cout << "Enter <shop id> <chain name>:";
	cin >> sid >> cname;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		Shop* shop = (*reshet)[sid];
		if (shop) {
			cout << cname << " " << sid << " salaries: " << shop->sumSalaries() << endl;
		}
		else
			cout << "Couldn't find this shop at this reshet." << endl;
	}
	else
		cout << "Couldn't find this reshet." << endl;
}

void printShop(Reshet** reshatot, int size) {
	int sid;
	string cname;
	cout << "Enter <shop id> <chain name>:";
	cin >> sid >> cname;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		Shop* shop = (*reshet)[sid];
		if (shop) {
			shop->print();
		}
		else
			cout << "Couldn't find this shop at this reshet." << endl;
	}
	else
		cout << "Couldn't find this reshet." << endl;
}

void printEmployee(Reshet**reshatot,int size){
	string eid;
	string cname;
	cout << "Enter <employee id> <chain name>:";
	cin >> eid >> cname;
	Reshet* reshet = findReshet(reshatot, size, cname);
	if (reshet) {
		Worker* worker = (*reshet)[eid];
		if (worker)
			worker->print();
		else
			cout << "Couldn't find this worker at this reshet." << endl;
	}
	else
		cout << "Couldn't find this reshet." << endl;
}

Reshet* findReshet(Reshet** reshatot, int size, string name){
	for (int i = 0; i < size; i++)
		if (*(reshatot[i]) == name)
			return reshatot[i];
	return nullptr;
}