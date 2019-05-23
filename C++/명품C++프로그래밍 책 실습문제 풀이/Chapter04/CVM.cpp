#include "CVM.h"
#include <iostream>
using namespace std;

void CoffeeVendingMachine::fill() {
	tong[0].fill();
	tong[1].fill();
	tong[2].fill();
}

void CoffeeVendingMachine::selectAmericano() {
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();
}

void CoffeeVendingMachine::selectEspresso() {
	tong[0].consume();
	tong[1].consume();
}

void CoffeeVendingMachine::selectSugarCoffee() {
	tong[0].consume();
	tong[1].consume();
	tong[1].consume();
	tong[2].consume();
}

void CoffeeVendingMachine::show() { cout << "Ŀ�� " << tong[0].getSize() << ", �� " << tong[1].getSize() << ", ���� " << tong[2].getSize() << endl; }

void CoffeeVendingMachine::run() {
	cout << "***** Ŀ�����Ǳ⸦ �۵��մϴ�. *****" << endl;
	int answer;

	do {
		cout << "�޴��� �����ּ���(1:����������, 2:�Ƹ޸�ī��, 3:����Ŀ��, 4:�ܷ�����, 5:ä���, 6:����)>>";
		cin >> answer;
		switch (answer) {
		case 1:if (tong[0].getSize() > 0 && tong[1].getSize() > 0) { selectEspresso();	cout << "���������� �弼��" << endl; }  else   cout << "���ᰡ �����մϴ�." << endl; break;
		case 2:if (tong[0].getSize() > 0 && tong[1].getSize() > 1) { selectAmericano();	cout << "�Ƹ޸�ī�� �弼��" << endl; }  else   cout << "���ᰡ �����մϴ�." << endl;	break;
		case 3:if (tong[0].getSize() > 0 && tong[1].getSize() > 1 && tong[2].getSize() > 0) { selectSugarCoffee();		cout << "����Ŀ�� �弼��" << endl; } else   cout << "���ᰡ �����մϴ�." << endl;	break;
		case 4:show(); break;
		case 5:fill(); show(); break;
		case 6:cout << "***** Ŀ�����Ǳ⸦ �����մϴ�. *****" << endl; break;
		default: cout << "�޴������� �߸��Ǿ����ϴ�. �ٽ� �õ����ּ���!" << endl;
		}
	} while (answer !=6 );
}