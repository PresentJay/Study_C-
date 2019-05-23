#include "Circlemanager.h"
#include "cir.h"
#include <iostream>


Circlemanager::Circlemanager(int size) {
	this->size = size;
	p = new Circle[size];
	int r;
	string n;
	for (int i = 0; i < size; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> n >> r;
		p[i].setCircle(n, r);
	}
}


Circlemanager::~Circlemanager() { delete[] p; }

void Circlemanager::searchByArea() {
	int r;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> r;
	cout << r << "보다 큰 원을 검색합니다." << endl;
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > r) cout << p[i].getName() << "의 면적은 " << p[i].getArea() << ",";
	}
	cout << endl;
}

void Circlemanager::searchByName() {
	string n;
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> n;
	for (int i = 0; i < size; i++) {
		if (n == p[i].getName()) {
			cout << n << "의 면적은 " << p[i].getArea() << endl;
			break;
		}
	}
}