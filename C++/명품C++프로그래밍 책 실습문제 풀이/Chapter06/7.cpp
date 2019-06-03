#include <iostream>
#include <ctime>
using namespace std;

class Random {
public:
	static void seed() { srand((unsigned)time(0)); }	
	static int nextInt(int min = 0, int max = 32767) { int Rdata = rand() % max + min; return Rdata; }
	static char nextAlphabet() {
		char Rdata;
		do {
			Rdata = rand() % 58 + 65;
		} while (Rdata > 90 && Rdata < 97);
		return Rdata;
	}
	static double nextDouble() { double Rdata = (rand()%999999+1)/(double)1000000; return Rdata; }
};



void main() {
	Random::seed();
	cout << "1���� 100���� ������ ���� 10���� ����մϴ�." << endl;
	for (int i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';
	cout << endl << "���ĺ��� �����ϰ� 10���� ����մϴ�." << endl ;
	for (int i = 0; i < 10; i++) cout << Random::nextAlphabet() << ' ';
	cout << endl << "������ �Ǽ��� 10���� ����մϴ�." << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << ' ';
		if (i == 4) cout << endl;
	}
	cout << endl;
}
