#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char input_names[5][100], strlen_maximum[100]="";

	cout << sizeof(input_names) / sizeof(input_names[0]) << " ���� �̸��� ';'���� �����Ͽ� �Է��ϼ���" << endl << ">>";
	
	for (int i = 0; i < sizeof(input_names) / sizeof(input_names[0]); i++) {
		cin.getline(input_names[i], 100, ';');
		cout << i + 1 << " : " << input_names[i] << endl;
		if (strlen(input_names[i]) > strlen(strlen_maximum))
			strcpy_s(strlen_maximum, input_names[i]);
	}

	cout << "���� �� �̸��� " << strlen_maximum << endl;

	system("PAUSE");
}