#include <iostream>
#include <fstream>
#include "Hunky.h"
#include "Worker.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	HunkyHour HH;
	HunkyStat HS;
	HunkyPro HP;
	Worker *W;
	bool exit;
	int choise;
	do {
		system("CLS");
		cout << "��� �� ���� �������?" << endl
			<< "1) ��������� ��������" << endl
			<< "2) �������� ����������" << endl
			<< "3) �����" << endl
			<< "��� �����: " << endl;
		cin >> choise;
		switch (choise) {
		case 1: {
			cout << "1) ��������� ������" << endl
				<< "2) ������� ��������" << endl
				<< "3) � ���������� �������" << endl
				<< "��� �����: " << endl;
			cin >> choise;
			switch (choise) {
			case 1: {
				W = &HH;
				W->payday();
				break;
			}
			case 2: {
				W = &HS;
				W->payday();
				break;
			}
			case 3: {
				W = &HP;
				W->payday();
				break;
			}
			}
			system("pause");
			exit = true;
			break;
		}
		case 2: {
			cout << "1) ��������� ������" << endl
				<< "2) ������� ��������" << endl
				<< "3) � ���������� �������" << endl
				<< "��� �����: " << endl;
			cin >> choise;
			switch (choise) {
			case 1: {
				HH.add();
				break;
			}
			case 2: {
				HS.add();
				break;
			}
			case 3: {
				HP.add();
				break;
			}
			}
			exit = true;
			break;
		}
		case 3: {

			exit = false;
			break;
		}
		}
	} while (exit == true);
}