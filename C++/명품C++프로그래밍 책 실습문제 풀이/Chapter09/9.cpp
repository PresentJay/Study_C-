#include <iostream>
#include <string>
using namespace std;

class BasicPrinter {
	string model, manufacturer;
	int printedCount, availableCount;
public:
	BasicPrinter(string mo = "", string ma = "", int av = 0) { model = mo; manufacturer = ma; printedCount = 0; availableCount = av; }
	virtual void print(int pages) = 0;
	virtual void show() = 0;
	string getModel() { return model; }
	string getManufacturer() { return manufacturer; }
	int getprintedCount() { return printedCount; }
	int getAvailableCount() { return availableCount; }
	void printoutPaper(int mass) {	availableCount -= mass; }
};

class InkJetPrinter : public BasicPrinter {
	int availableInk;
public:
	InkJetPrinter(string mo = "", string ma = "", int av = 0, int ink = 0) : BasicPrinter(mo, ma, av) { availableInk = ink; }
	void print(int pages) { if (getAvailableCount() >= pages && availableInk >= pages) { cout << "프린트하였습니다" << endl; printoutPaper(pages); availableInk -= pages; } else cout << "용지가 부족하여 프린트할 수 없습니다." << endl; }
	void show() { cout << getModel() << " ," << getManufacturer() << " ,남은 종이 " << getAvailableCount() << "장 ,남은 잉크 " << availableInk << endl; }
};

class LaserPrinter : public BasicPrinter {
	int availableToner;
public:
	LaserPrinter(string mo = "", string ma = "", int av = 0, int ink = 0) : BasicPrinter(mo, ma, av) { availableToner = ink; }
	void print(int pages) { if (getAvailableCount() >= pages && availableToner >= pages) { cout << "프린트하였습니다" << endl; printoutPaper(pages); availableToner -= pages; } else cout << "용지가 부족하여 프린트할 수 없습니다." << endl; }
	void show() { cout << getModel() << " ," << getManufacturer() << " ,남은 종이 " << getAvailableCount() << "장 ,남은 토너 " << availableToner << endl; }
};

int main() {
	BasicPrinter *printers[2];
	printers[0] = new InkJetPrinter("Officejet V40", "HP", 5, 10);
	printers[1] = new LaserPrinter("SCX-6x45", "삼성전자", 3, 20);

	cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl << "잉크젯 : ";
	printers[0]->show();
	cout << "레이저 : ";
	printers[1]->show();

	int answer_i1, answer_i2;
	char answer_c;

	do {
		cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>>";
		cin >> answer_i1 >> answer_i2;
		printers[answer_i1 - 1]->print(answer_i2);
		printers[0]->show();
		printers[1]->show();
		cout << "계속 프린트 하시겠습니까(y/n)>>";
		cin >> answer_c;
	} while (answer_c != 'n');
}