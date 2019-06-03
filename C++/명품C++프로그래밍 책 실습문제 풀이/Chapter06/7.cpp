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
	cout << "1에서 100까지 랜덤한 정수 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) cout << Random::nextInt(1, 100) << ' ';
	cout << endl << "알파벳을 랜덤하게 10개를 출력합니다." << endl ;
	for (int i = 0; i < 10; i++) cout << Random::nextAlphabet() << ' ';
	cout << endl << "랜덤한 실수를 10개를 출력합니다." << endl;
	for (int i = 0; i < 10; i++) {
		cout << Random::nextDouble() << ' ';
		if (i == 4) cout << endl;
	}
	cout << endl;
}
