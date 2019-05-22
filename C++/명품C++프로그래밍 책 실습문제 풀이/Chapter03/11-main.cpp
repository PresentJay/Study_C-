#include <iostream>
#include "cal.h"
using namespace std;

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