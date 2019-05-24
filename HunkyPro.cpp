#include "Hunky.h"
#include <iostream>
#include <fstream>

using namespace std;

HunkyPro::HunkyPro() {
	last = NULL;
	fstream file("WorkersP.txt", ios::in | ios::out | ios::app);
	if (!file.is_open()) {
		cout << "���� ��������� � ��������� ������� �� ����� ���� ������ ��� ������" << endl;
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

HunkyPro::~HunkyPro() {
	slave *tmp = last;
	fstream file("WorkersP.txt", ios::out | ios::trunc);
	if (!file.is_open()) {
		cout << "���� ��������� � ��������� ������� �� ����� ���� ������ ��� ������" << endl;
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
	cout << "HP" << endl;
}

int HunkyPro::payday() {
	slave *tmp = last;
	if (num == 0) {
		cout << "���� ������ ����" << endl;
		return 0;
	}
	int i;
	this->pin();
	cout << "������� ����� ���������, ��� �������� ����� ��������� ��������: ";
	cin >> i;
	while (i > 1) {
		tmp = tmp->prev;
		i--;
	}
	cout << "������� ����� ������: ";
	cin >> i;
	double res = (i * tmp->sum) / 100;
	cout << "�������� ����� = " << res << endl;
	return 0;
}