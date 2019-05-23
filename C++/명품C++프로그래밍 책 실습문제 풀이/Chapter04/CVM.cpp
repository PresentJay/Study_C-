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

void CoffeeVendingMachine::show() { cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl; }

void CoffeeVendingMachine::run() {
	cout << "***** 커피자판기를 작동합니다. *****" << endl;
	int answer;

	do {
		cout << "메뉴를 눌러주세요(1:에스프레소, 2:아메리카노, 3:설탕커피, 4:잔량보기, 5:채우기, 6:종료)>>";
		cin >> answer;
		switch (answer) {
		case 1:if (tong[0].getSize() > 0 && tong[1].getSize() > 0) { selectEspresso();	cout << "에스프레소 드세요" << endl; }  else   cout << "원료가 부족합니다." << endl; break;
		case 2:if (tong[0].getSize() > 0 && tong[1].getSize() > 1) { selectAmericano();	cout << "아메리카노 드세요" << endl; }  else   cout << "원료가 부족합니다." << endl;	break;
		case 3:if (tong[0].getSize() > 0 && tong[1].getSize() > 1 && tong[2].getSize() > 0) { selectSugarCoffee();		cout << "설탕커피 드세요" << endl; } else   cout << "원료가 부족합니다." << endl;	break;
		case 4:show(); break;
		case 5:fill(); show(); break;
		case 6:cout << "***** 커피자판기를 종료합니다. *****" << endl; break;
		default: cout << "메뉴선택이 잘못되었습니다. 다시 시도해주세요!" << endl;
		}
	} while (answer !=6 );
}