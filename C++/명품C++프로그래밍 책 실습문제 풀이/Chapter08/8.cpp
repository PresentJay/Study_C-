#include <iostream>
#include <string>
using namespace std;

class BasePrinter {
	string model, manufacturer;
	int printedCount, availableCount;
public:
	BasePrinter(string model, string manu, int pagecount) { this->model = model; manufacturer = manu; availableCount = pagecount; printedCount = 0; }
	void show() { cout << model << " ," << manufacturer << " ,남은 종이 " << availableCount << "장"; }
	bool capablePrint(int pages = 0) { if (availableCount >= pages) return true; else return false; }
	void print(int pages) { cout << "프린트하였습니다." << endl; printedCount+=pages; availableCount-=pages; }
};

class InkjetPrinter : public BasePrinter {
	int availableInk;
public:
	InkjetPrinter(string model, string manu, int pagecount, int ink) : BasePrinter(model, manu, pagecount) { availableInk = ink; }
	void show() { BasePrinter::show(); cout << " ,남은 잉크 " << availableInk << endl; }
	bool capablePrint(int pages = 0) { if (BasePrinter::capablePrint(pages) && availableInk >= availableInk) return true; else return false; }
	void printInkJet(int pages) { if (capablePrint(pages)) { BasePrinter::print(pages); availableInk-=pages; } else cout << "용지가 부족하여 프린트할 수 없습니다." << endl; }
};

class LaserPrinter : public BasePrinter {
	int availableToner;
public:
	LaserPrinter(string model, string manu, int pagecount, int toner) : BasePrinter(model, manu, pagecount) { availableToner = toner; }
	void show() { BasePrinter::show(); cout << " ,남은토너 " << availableToner << endl; }
	bool capablePrint(int pages = 0) { if (BasePrinter::capablePrint(pages) && availableToner >= availableToner) return true; else return false; }
	void printLaser(int pages) { if (capablePrint(pages)) { BasePrinter::print(pages); availableToner-=pages; } else cout << "용지가 부족하여 프린트할 수 없습니다." << endl; }
};

int main() {
	int Answer_I_1, Answer_I_2;
	char Answer_C;
	InkjetPrinter IP("Officejet V40","HP",5,10);
	LaserPrinter LP("SCX-6x45","삼성전자",3,20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl << "잉크젯 : ";
	IP.show();
	cout << "레이저 : ";
	LP.show();

	do {
		cout << endl << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> Answer_I_1 >> Answer_I_2;
		if (Answer_I_1 == 1) IP.printInkJet(Answer_I_2);
		else if (Answer_I_1 == 2) LP.printLaser(Answer_I_2);
		IP.show();
		LP.show();
		cout << "계속 프린트하시겠습니까(y/n)>>";
		cin >> Answer_C;
	} while (Answer_C != 'n');
}