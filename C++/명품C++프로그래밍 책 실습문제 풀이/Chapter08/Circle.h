#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; }
};

class NamedCircle : public Circle {
	string name;
public:
	NamedCircle(int radius=0, string name="") { setRadius(radius); this->name = name; }
	void setName(string name) { this->name = name; }
	void show() { cout << "반지름이 " << getRadius() << "인 " << name << endl; }
	string getName() { return name; }
};

#endif // !CIRCLE_H
