#include "cir.h"

void Circle::setCircle(string name, int radius) { this->name = name; this->radius = radius; }
double Circle::getArea() { double result = radius * radius*3.14; return result; }
string Circle::getName() { return name; }
