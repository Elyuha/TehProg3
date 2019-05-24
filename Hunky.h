#pragma once

#include "Worker.h"

class HunkyHour : public Worker {
public:
	HunkyHour();
	~HunkyHour();
	int payday();
};

class HunkyStat : public Worker {
public:
	HunkyStat();
	~HunkyStat();
	int payday();
};

class HunkyPro : public Worker {
public:
	HunkyPro();
	~HunkyPro();
	int payday();
};
