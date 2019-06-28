#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read() { cout << name << ":" << endl << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> "; cin >> x >> y; }
	void write() { cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl; }
protected:
	LoopAdder(string name = "") { this->name = name; }
	int getX() { return x; }
	int getY() { return y; }
	virtual int calculate() = 0;
public:
	void run() { read(); sum = calculate(); write(); }
};

class ForLoopAdder : public LoopAdder {
public:
	ForLoopAdder(string name = "") : LoopAdder(name) {}
	int calculate() { int sum = 0; for (int i = getX(); i <= getY(); i++) sum += i; return sum; }
};

class DoWhileLoopAdder : public LoopAdder {
public:
	DoWhileLoopAdder(string name = "") : LoopAdder(name) {}
	int calculate() { int sum = 0; int i = getX(); do { sum += i; i++; } while (i <= getY()); return sum; }
};

class WhileLoopAdder : public LoopAdder {
public:
	WhileLoopAdder(string name = "") : LoopAdder(name) {}
	int calculate() { int sum = 0; int i = getX(); while (i <= getY()) { sum += i; i++; } return sum; }
};