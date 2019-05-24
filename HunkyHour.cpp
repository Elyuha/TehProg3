#include "Hunky.h"
#include <iostream>
#include <fstream>

using namespace std;

HunkyHour::HunkyHour() {
	last = NULL;
	fstream file("WorkersH.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "Файл работника с почасовой оплатой не может быть открыт или создан" << endl;
		system("pause");
	}
	else {
		while (!file.eof()) {
			slave *tmp = new slave;
			file >> tmp->name >> tmp->secondName >> tmp->phone >> tmp->address >> tmp->sum;
			if (tmp->name[0] == '\0') {
				delete tmp;
				break;
			}
			tmp->prev = last;
			last = tmp;
			num++;
			
		}
	}
	file.close();
}

HunkyHour::~HunkyHour() {
	slave *tmp = last;
	fstream file("WorkersH.txt", ios::out | ios::trunc);
	if (!file.is_open()) {
		cout << "Файл роботника с почасовой оплатой не может быть открыт или создан" << endl;
		system("pause");
	}
	for (int i = num; i > 0; i--) {
		file << " " << tmp->name << " " << tmp->secondName << " " << tmp->phone << " " << tmp->address << " " << tmp->sum;
		tmp = tmp->prev;
	}
	file.close();
	for (int i = 0; i < num; i++) {
		tmp = last->prev;
		delete last;
		last = tmp;
	}
	cout << "HH" << endl;
}

int HunkyHour::payday() {
	slave *tmp = last;
	if (num == 0) {
		cout << "Тута ничего нету" << endl;
		return 0;
	}
	int i;
	this->pin();
	cout << "Введите номер работника, для которого нужно вычислить зарплату: ";
	cin >> i;
	while (i > 1) {
		tmp = tmp->prev;
		i--;
	}
	cout << "Введите кол-во отработынных часов: ";
	cin >> i;
	cout << "Зарплата равна = " << i * tmp->sum << endl;
	return 0;
}