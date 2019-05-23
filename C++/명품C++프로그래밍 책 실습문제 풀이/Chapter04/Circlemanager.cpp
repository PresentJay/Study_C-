#include "Circlemanager.h"
#include "cir.h"
#include <iostream>


Circlemanager::Circlemanager(int size) {
	this->size = size;
	p = new Circle[size];
	int r;
	string n;
	for (int i = 0; i < size; i++) {
		cout << "�� " << i + 1 << "�� �̸��� ������ >> ";
		cin >> n >> r;
		p[i].setCircle(n, r);
	}
}


Circlemanager::~Circlemanager() { delete[] p; }

void Circlemanager::searchByArea() {
	int r;
	cout << "�ּ� ������ ������ �Է��ϼ��� >> ";
	cin >> r;
	cout << r << "���� ū ���� �˻��մϴ�." << endl;
	for (int i = 0; i < size; i++) {
		if (p[i].getArea() > r) cout << p[i].getName() << "�� ������ " << p[i].getArea() << ",";
	}
	cout << endl;
}

void Circlemanager::searchByName() {
	string n;
	cout << "�˻��ϰ��� �ϴ� ���� �̸� >> ";
	cin >> n;
	for (int i = 0; i < size; i++) {
		if (n == p[i].getName()) {
			cout << n << "�� ������ " << p[i].getArea() << endl;
			break;
		}
	}
}