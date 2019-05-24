#pragma once

#include <iostream>
#include "Worker.h"

using namespace std;

Worker::~Worker(){
	cout << "¬иртуальный деструктор вызвалс€" << endl;
}

void Worker::add() {
	slave *tmp = new slave;
	cout << "¬ведите им€: ";
	cin >> tmp->name;
	cout << "¬ведите фамилию: ";
	cin >> tmp->secondName;
	cout << "¬ведите телефон: ";
	cin >> tmp->phone;
	cout << "¬ведите адрес: ";
	cin >> tmp->address;
	cout << "¬ведите <процентрую ставку/сумму в час/зарплату в мес€ц>: ";
	cin >> tmp->sum;
	if (num == 0) {
		last = tmp;
		last->prev = NULL;
	}
	else {
		tmp->prev = last;
		last = tmp;
	}
	num++;
}

void Worker::pin() {
	slave *tmp = last;
	for (int i = num; i > 0; i--) {
		cout << num - i + 1 << "-    ";
		cout.width(15);
		cout << tmp->name;
		cout.width(20);
		cout << tmp->secondName;
		cout.width(15);
		cout << tmp->phone;
		cout.width(20);
		cout << tmp->address;
		cout.width(4);
		cout << tmp->sum << endl;
		tmp = tmp->prev;
	}
}