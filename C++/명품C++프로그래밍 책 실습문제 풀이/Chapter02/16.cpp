#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[10000];
	int alpha[27];

	cout << "���� �ؽ�Ʈ�� �Է��ϼ���. ������׷��� �׸��ϴ�." << endl << "�ؽ�Ʈ�� ���� ; �Դϴ�. 10000������ �����մϴ�." << endl;
	cin.getline(str, 10000, ';');
	fill_n(alpha, 27, 0);
	

	for (int i = 0; i < strlen(str); i++) {
		if (isalpha(str[i]))
			alpha[26]++;
		for (char j = 'a'; j <= 'z'; j++) {
			if (j == tolower(str[i]))
				alpha[(int)j - 97]++;
		}
	}

	cout << "�� ���ĺ� �� " << alpha[26] << endl << endl;

	for (int i = 0; i < 26; i++) {
		cout << (char)(97 + i) << "(" << alpha[i] << ")";
		if (alpha[i] < 10)
			cout << "    : ";
		else
			cout << "   : ";
		for (int j = 0; j < alpha[i]; j++)
			cout << '*';

		cout << endl;
	}

	cout << endl << endl <<  "version Extra..." << endl << endl;

	int max=0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > max)
			max = alpha[i];
	}
	for (int i = max; i > 0; i--) {
		for (int j = 0; j < 26; j++) {
			if (alpha[j] >= i)
				cout << "*   ";
			else
				cout << "    ";
		}
		cout << endl;
	}
	for (char i = 'a'; i <= 'z';i++)
		cout << i << "   ";
	cout << endl;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] < 10)
			cout << alpha[i] << "   ";
		else
			cout << alpha[i] << "  ";
	}
	cout << endl;
	system("PAUSE");
}