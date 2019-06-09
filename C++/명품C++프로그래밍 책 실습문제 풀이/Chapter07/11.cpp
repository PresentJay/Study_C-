#include <iostream>

using namespace std;

class Stack {
	int index, list[100];
public:
	Stack() { index = -1; }
	Stack &operator << (int op2) { index++; list[index] = op2; return *this; }
	bool operator !() { if (index == -1) return true; else return false; }
	Stack &operator >> (int &op2) { op2 = list[index]; list[index] = 0; index--; return *this; }
};

int main() {
	Stack stack;
	stack << 3 << 5 << 10;
	while (1) {
		if (!stack) break;
		int x;
		stack >> x;
		cout << x << ' ';
	}
	cout << endl;
}