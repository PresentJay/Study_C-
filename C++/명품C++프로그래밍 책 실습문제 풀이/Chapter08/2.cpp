#include "Circle.h"

int main() {
	int i = 5, max = 0;
	NamedCircle pizza[5];
	cout << i << " ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
	for (int j = 0; j < i; j++) {
		cout << j + 1 << ">> ";
		int cint; string cstr;
		cin >> cint >> cstr;
		if (cint > pizza[max].getRadius()) max = j;
		pizza[j].setRadius(cint);
		pizza[j].setName(cstr);
	}
	cout << "���� ������ ū ���ڴ� " << pizza[max].getName() << "�Դϴ�" << endl;
}