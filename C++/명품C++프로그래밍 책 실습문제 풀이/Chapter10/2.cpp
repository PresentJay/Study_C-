#include <iostream>
using namespace std;

template <class T>
bool equalArrays(T leftItem[], T rightItem[], int size) {
	bool flag = true;
	for (int i = 0; i < size; i++) {
		if (leftItem[i] != rightItem[i]) flag = false;
	}
	return flag;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	int y[] = { 1,10,100,5,4 };
	if (equalArrays(x, y, 5)) cout << "같다";
	else cout << "다르다";
	cout << endl;
}