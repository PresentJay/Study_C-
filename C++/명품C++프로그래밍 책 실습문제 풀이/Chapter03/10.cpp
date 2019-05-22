#include <iostream>
using namespace std;

class Add {
	int a, b;
public:
	void setValue(int x, int y) { a = x; b = y; }
	int calculate() { return a + b; }
};

class Sub {
	int a, b;
public:
	void setValue(int x, int y) { a = x; b = y; }
	int calculate() { return a - b; }
};

class Mul {
	int a, b;
public:
	void setValue(int x, int y) { a = x; b = y; }
	int calculate() { return a * b; }
};

class Div {
	int a, b;
public:
	void setValue(int x, int y) { a = x; b = y; }
	int calculate() { return a / b; }
};

int main() {
	int iA, iB;
	char c;
	Add a;
	Sub s;
	Mul m;
	Div d;

	while (1) {
		cout << "두 정수와 연산자를 입력하세요>>";
		cin >> iA >> iB >> c;
		switch (c) {
		case '+':
			a.setValue(iA, iB);
			cout << a.calculate() << endl;
			break;
		case '-':
			s.setValue(iA, iB);
			cout << s.calculate() << endl;
			break;
		case '*':
			m.setValue(iA, iB);
			cout << m.calculate() << endl;
			break;
		case '/':
			d.setValue(iA, iB);
			cout << d.calculate() << endl;
			break;
		default:
			break;
		}
	}
}