#include <iostream>

using namespace std;

int main() {
	int answer, mass;
	cout << "**** �¸��忡 ���� ���� ȯ���մϴ�. *****" << endl;
	
	do {
		cout << "«��:1, ¥��:2, ������:3, ����:4>>  ";
		cin >> answer;
		if (answer < 4) {
			cout << "���κ�?";
			cin >> mass;
			if (answer == 1)
				cout << "«�� ";
			else if (answer == 2)
				cout << "¥�� ";
			else if (answer == 3)
				cout << "������ ";

			cout << mass << "�κ� ���Խ��ϴ�" << endl;
		}
		else
			cout << "�ٽ� �ֹ��ϼ���!!" << endl;
	} while (answer != 4);

	cout << "���� ������ �������ϴ�." << endl;

	system("PAUSE");
}