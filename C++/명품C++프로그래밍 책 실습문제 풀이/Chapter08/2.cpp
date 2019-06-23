#include "Circle.h"

int main() {
	int i = 5, max = 0;
	NamedCircle pizza[5];
	cout << i << " 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int j = 0; j < i; j++) {
		cout << j + 1 << ">> ";
		int cint; string cstr;
		cin >> cint >> cstr;
		if (cint > pizza[max].getRadius()) max = j;
		pizza[j].setRadius(cint);
		pizza[j].setName(cstr);
	}
	cout << "가장 면적이 큰 피자는 " << pizza[max].getName() << "입니다" << endl;
}