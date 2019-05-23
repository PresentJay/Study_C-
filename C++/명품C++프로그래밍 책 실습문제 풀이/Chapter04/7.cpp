include "Circle.h"
#include <iostream>
using namespace std;

int main() {
	Circle *arr = new Circle[3];
	int r, count=0;
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		arr[i].setRadius(r);
		if (arr[i].getArea() > 100) count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;

	system("PAUSE");
}