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
		cout << "�Ϲ� ���:1  ���ϴ����:2  ¦�� ���:3  Ȧ¦����:4 >> ";
		cin >> answer;
		switch (answer) {
		case 1:
			cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10 ��--" << endl;
			for (int i = 0; i < 10; i++) {
				n = r.next();
				cout << n << '\t';
			}
			break;

		case 2:
			cout << "���� �� �Է� >> ";
			cin >> answer;
			cout << "�� �� �Է� >> ";
			cin >> answer2;
			cout << endl << endl << "-- " << answer << "���� " << answer2 << " ������ ���� ���� 10 �� -- " << endl;
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
				cout << "�⺻��ȣ��:1   ����ȣ��:2  >> ";
				cin >> answer2;
			} while (answer2 < 1 || answer2 > 2);
			do {
				cout << "Ȧ��:1  ¦��:2  >> ";
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
					cout << "���� �� >> ";
					cin >> answer;
					cout << "���� >> ";
					cin >> answer2;
					for (int i = 0; i < 10; i++) {
						do {
							n = r.nextInRange(answer,answer2);
						} while (n % 2 == 1);
						cout << n << '\t';
					}
				}
				else {
					cout << "���� �� >> ";
					cin >> answer;
					cout << "���� >> ";
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