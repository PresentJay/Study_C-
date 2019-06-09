#include <iostream>
using namespace std;

class Statistics {
	int index, *stats;
public:
	Statistics() { index = -1; stats = new int[1]; }
	bool operator !() { if (index == -1) return true; else return false; }
	Statistics& operator << (int op2) { index++; stats[index] = op2; return *this; }
	void operator ~() { for (int i = 0; i <= index; i++) cout << stats[i] << ' '; cout << endl; }
	Statistics & operator >> (int &op2) { int avg = 0; for (int i = 0; i <= index; i++) avg += stats[i]; avg /= index + 1; op2 = avg; return *this; }
};

int main() {
	Statistics stat;
	if (!stat) cout << "현재 통계 데이타가 없습니다." << endl;

	int x[5];
	cout << "5 개의 정수를 입력하라>>";
	for (int i = 0; i < 5; i++) cin >> x[i];

	for (int i = 0; i < 5; i++) stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg << endl;
}