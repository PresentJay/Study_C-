#include <iostream>
using namespace std;

class AbstractStack {
public:
	virtual bool push(int n) = 0;
	virtual bool pop(int& n) = 0;
	virtual int size() = 0;
};

class IntStack : public AbstractStack {
	int *array;
	int max, index;
public:
	IntStack(int size = 1) { max = size; array = new int[size]; index = -1; }
	bool push(int n) { if (index == max - 1) return false; else { index++; array[index] = n; return true; } }
	bool pop(int& n) { if (index == -1) return false; else { n = array[index]; array[index] = NULL; index--; return true; } }
	int size() { return index + 1; }
	void alert() { cout << "현재 사이즈 >> " << size() << endl; }
};

int main() {
	int cashnum = 0;
	IntStack intStack(5);
	cout.setf(ios::boolalpha);
	intStack.alert();
	cout << "숫자 5개 입력 >> ";
	for (int i = 0; i < 5; i++) {
		int num;
		cin >> num;
		intStack.push(num);
	}
	intStack.alert();
	intStack.pop(cashnum);
	cout << cashnum << endl;
	intStack.alert();
	for (int i = 0; i < 4; i++) {
		intStack.pop(cashnum);
		cout << cashnum << " ";
	}
	cout << endl;
}