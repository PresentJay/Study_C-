#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char choosing_menu[20];
	int mass, sail = 0;

	while(sail<20000){
		cout << "���������� 2000��, �Ƹ޸�ī�� 2300��, īǪġ�� 2500���Դϴ�." << endl << "�ֹ�>> ";
		cin >> choosing_menu >> mass;
		
		if (strcmp(choosing_menu, "����������") == 0) {
			cout << 2000 * mass;
			sail += 2000 * mass;
		}
		else if (strcmp(choosing_menu, "�Ƹ޸�ī��") == 0) {
			cout << 2300 * mass;
			sail += 2300 * mass;
		}
		else if (strcmp(choosing_menu, "īǪġ��") == 0) {
			cout << 2500 * mass;
			sail += 2500 * mass;
		}
		else {
			cout << "�޴������� �߸��Ǿ����ϴ�." << endl;
			mass = 0;
		}
		if (mass != 0)
			cout << "���Դϴ�. ���ְ� �弼��." << endl;
	}

	cout << "���� " << sail << "���� �Ǹ��Ͽ� ī�並 �ݽ��ϴ�. ���� ����~~~" << endl;
	system("PAUSE");
}