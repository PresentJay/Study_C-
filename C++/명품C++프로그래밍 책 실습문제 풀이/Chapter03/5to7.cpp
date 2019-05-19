#include <iostream>
#include <cstdlib>
using namespace std;

class Random {

public:
	Random() {}
	int next() { return rand() % RAND_MAX + 1; }
	int nextInRange(int start, int end) { return rand() % (end - start + 1) + start; }
	int nextEven();
	int sel_Odd_Even();
};

int Random::nextEven() {
	int n;
	do {
		n = rand() % 11;
	} while ((n % 2 != 0));

	return n;
}

int main() {
	Random r;
	int answer, answer2, n;
	while (1) {
		answer = 0;
		answer2 = 0;
		cout << "일반 출력:1  원하는출력:2  짝수 출력:3  홀짝선택:4 >> ";
		cin >> answer;
		switch (answer) {
		case 1:
			cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
			for (int i = 0; i < 10; i++) {
				n = r.next();
				cout << n << '\t';
			}
			break;

		case 2:
			cout << "시작 값 입력 >> ";
			cin >> answer;
			cout << "끝 값 입력 >> ";
			cin >> answer2;
			cout << endl << endl << "-- " << answer << "에서 " << answer2 << " 까지의 랜덤 정수 10 개 -- " << endl;
			for (int i = 0; i < 10; i++) {
				int n = r.nextInRange(answer, answer2);
				cout << n << '\t';
			}
			break;

		case 3:
			for (int i = 0; i < 10; i++) {
				cout << r.nextEven() << '\t';
			}
			break;

		case 4:
			
			do {
				cout << "기본값호출:1   선택호출:2  >> ";
				cin >> answer2;
			} while (answer2 < 1 || answer2 > 2);
			do {
				cout << "홀수:1  짝수:2  >> ";
				cin >> answer;
			} while (answer < 1 || answer > 2);
			if (answer2 == 1) {
				if (answer == 1) {
					for (int i = 0; i < 10; i++) {
						do {
							n = r.next();
						} while (n % 2 == 1);
						cout << n << '\t';
					}
				}
				else {
					for (int i = 0; i < 10; i++) {
						do {
							n = r.next();
						} while (n % 2 == 0);
						cout << n << '\t';
					}
				}
			}
			else {
				if (answer == 1) {
					cout << "시작 값 >> ";
					cin >> answer;
					cout << "끝값 >> ";
					cin >> answer2;
					for (int i = 0; i < 10; i++) {
						do {
							n = r.nextInRange(answer,answer2);
						} while (n % 2 == 1);
						cout << n << '\t';
					}
				}
				else {
					cout << "시작 값 >> ";
					cin >> answer;
					cout << "끝값 >> ";
					cin >> answer2;
					for (int i = 0; i < 10; i++) {
						do {
							n = r.nextInRange(answer,answer2);
						} while (n % 2 == 0);
					}
					cout << n << '\t';
				}
			}
			break;

		default:
			break;
		}
		cout << endl << endl;
	}
	system("PAUSE");
}