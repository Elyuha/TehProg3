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
		cout << "Что вы хоте сделать?" << endl
			<< "1) Вычислить зарплату" << endl
			<< "2) Добавить сотрудника" << endl
			<< "3) Выход" << endl
			<< "Ваш выбор: " << endl;
		cin >> choise;
		switch (choise) {
		case 1: {
			cout << "1) Почасовая оплата" << endl
				<< "2) Штатный работник" << endl
				<< "3) С процентной ставкой" << endl
				<< "Ваш выбор: " << endl;
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
			cout << "1) Почасовая оплата" << endl
				<< "2) Штатный работник" << endl
				<< "3) С процентной ставкой" << endl
				<< "Ваш выбор: " << endl;
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