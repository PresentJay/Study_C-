#include "Circle.h"
#include <iostream>

using namespace std;

int main() {
	Circle *arr;
	int setting_r_num, r, count=0;

	cout << "원의 개수 >> ";
	cin >> setting_r_num;
	arr = new Circle[setting_r_num];
	for (int i = 0; i < setting_r_num; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		arr[i].setRadius(r);
		if (arr[i].getArea() > 100) count++;
	}
	cout << "면적이 100보다 큰 원은 " << count << "개 입니다" << endl;
	system("PAUSE");
}