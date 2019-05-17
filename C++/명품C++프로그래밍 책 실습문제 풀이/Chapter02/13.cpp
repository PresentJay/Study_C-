#include <iostream>

using namespace std;

int main() {
	int answer, mass;
	cout << "**** 승리장에 오신 것을 환영합니다. *****" << endl;
	
	do {
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>  ";
		cin >> answer;
		if (answer < 4) {
			cout << "몇인분?";
			cin >> mass;
			if (answer == 1)
				cout << "짬뽕 ";
			else if (answer == 2)
				cout << "짜장 ";
			else if (answer == 3)
				cout << "군만두 ";

			cout << mass << "인분 나왔습니다" << endl;
		}
		else
			cout << "다시 주문하세요!!" << endl;
	} while (answer != 4);

	cout << "오늘 영업은 끝났습니다." << endl;

	system("PAUSE");
}