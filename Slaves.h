#pragma once

#include <string>

using namespace std;

struct slave {
	string name; //15
	string secondName; //20
	string phone; //15
	string address; //20
	int sum;
	slave *prev;
};