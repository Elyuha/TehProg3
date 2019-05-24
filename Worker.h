#pragma once

#include "Slaves.h"

class Worker {
protected:
	slave *last;
	int num;
public:
	Worker() {};
	virtual ~Worker();
	virtual int payday() { return 0; };
	void pin();
	void add();
};