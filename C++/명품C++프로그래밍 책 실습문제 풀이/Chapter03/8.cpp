#include <iostream>
#include <string>
using namespace std;

class Integer {
	int n;
public:
	Integer(int i) { n = i; }
	Integer(string i) { n = stoi(i); }
	int get() { return n; }
	bool isEven() { return (n % 2 == 0); }
	void set(int i) { n = i; }
};

int main() {
	Integer n(30);
	cout << n.get() << ' ';
	n.set(50);
	cout << n.get() << ' ';

	Integer m("300");
	cout << m.get() << ' ';
	cout << m.isEven() << endl;

	system("PAUSE");
}