#include "Circle.h"
#include <iostream>

using namespace std;

int main() {
	Circle *arr;
	int setting_r_num, r, count=0;

	cout << "���� ���� >> ";
	cin >> setting_r_num;
	arr = new Circle[setting_r_num];
	for (int i = 0; i < setting_r_num; i++) {
		cout << "�� " << i + 1 << "�� ������ >> ";
		cin >> r;
		arr[i].setRadius(r);
		if (arr[i].getArea() > 100) count++;
	}
	cout << "������ 100���� ū ���� " << count << "�� �Դϴ�" << endl;
	system("PAUSE");
}