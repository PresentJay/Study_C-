#include <iostream>
using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	void show() { cout << "radius = " << radius << " ÀÎ ¿ø" << endl; }
	friend Circle operator + (int op1, Circle op2) { Circle temp; temp.radius = op1 + op2.radius; return temp; }
};

int main() {
	Circle a(5), b(4);
	b = 1 + a;
	a.show();
	b.show();
}