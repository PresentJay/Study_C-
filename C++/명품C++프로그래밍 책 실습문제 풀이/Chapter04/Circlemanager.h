#ifndef CIRCLEMANAGER_H
#define CIRCLEMANAGER_H
#include "cir.h"

class Circlemanager {
	Circle *p;
	int size;
public:
	Circlemanager(int size);
	~Circlemanager();
	void searchByName();
	void searchByArea();
};

#endif // !CIRCLEMANAGER_H
