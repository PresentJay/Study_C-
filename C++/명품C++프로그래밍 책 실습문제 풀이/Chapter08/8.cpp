#include <iostream>
#include <string>
using namespace std;

class BasePrinter {
	string model, manufacturer;
	int printedCount, availableCount;
public:
	BasePrinter(string model, string manu, int pagecount) { this->model = model; manufacturer = manu; availableCount = pagecount; printedCount = 0; }
	void show() { cout << model << " ," << manufacturer << " ,���� ���� " << availableCount << "��"; }
	bool capablePrint(int pages = 0) { if (availableCount >= pages) return true; else return false; }
	void print(int pages) { cout << "����Ʈ�Ͽ����ϴ�." << endl; printedCount+=pages; availableCount-=pages; }
};

class InkjetPrinter : public BasePrinter {
	int availableInk;
public:
	InkjetPrinter(string model, string manu, int pagecount, int ink) : BasePrinter(model, manu, pagecount) { availableInk = ink; }
	void show() { BasePrinter::show(); cout << " ,���� ��ũ " << availableInk << endl; }
	bool capablePrint(int pages = 0) { if (BasePrinter::capablePrint(pages) && availableInk >= availableInk) return true; else return false; }
	void printInkJet(int pages) { if (capablePrint(pages)) { BasePrinter::print(pages); availableInk-=pages; } else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl; }
};

class LaserPrinter : public BasePrinter {
	int availableToner;
public:
	LaserPrinter(string model, string manu, int pagecount, int toner) : BasePrinter(model, manu, pagecount) { availableToner = toner; }
	void show() { BasePrinter::show(); cout << " ,������� " << availableToner << endl; }
	bool capablePrint(int pages = 0) { if (BasePrinter::capablePrint(pages) && availableToner >= availableToner) return true; else return false; }
	void printLaser(int pages) { if (capablePrint(pages)) { BasePrinter::print(pages); availableToner-=pages; } else cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl; }
};

int main() {
	int Answer_I_1, Answer_I_2;
	char Answer_C;
	InkjetPrinter IP("Officejet V40","HP",5,10);
	LaserPrinter LP("SCX-6x45","�Ｚ����",3,20);

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl << "��ũ�� : ";
	IP.show();
	cout << "������ : ";
	LP.show();

	do {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> Answer_I_1 >> Answer_I_2;
		if (Answer_I_1 == 1) IP.printInkJet(Answer_I_2);
		else if (Answer_I_1 == 2) LP.printLaser(Answer_I_2);
		IP.show();
		LP.show();
		cout << "��� ����Ʈ�Ͻðڽ��ϱ�(y/n)>>";
		cin >> Answer_C;
	} while (Answer_C != 'n');
}