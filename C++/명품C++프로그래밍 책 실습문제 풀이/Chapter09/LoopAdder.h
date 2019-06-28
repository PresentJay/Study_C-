#include <iostream>
#include <string>
using namespace std;

class LoopAdder {
	string name;
	int x, y, sum;
	void read() { cout << name << ":" << endl << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> "; cin >> x >> y; }
	void write() { cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl; }
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