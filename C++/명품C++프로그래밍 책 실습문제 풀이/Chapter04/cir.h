#ifndef CIR_H
#define CIR_H
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:
	void setCircle(string name, int radius);
	double getArea();
	string getName();
};

#endif