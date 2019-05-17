#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char input_names[5][100], strlen_maximum[100]="";

	cout << sizeof(input_names) / sizeof(input_names[0]) << " 명의 이름을 ';'으로 구분하여 입력하세요" << endl << ">>";
	
	for (int i = 0; i < sizeof(input_names) / sizeof(input_names[0]); i++) {
		cin.getline(input_names[i], 100, ';');
		cout << i + 1 << " : " << input_names[i] << endl;
		if (strlen(input_names[i]) > strlen(strlen_maximum))
			strcpy_s(strlen_maximum, input_names[i]);
	}

	cout << "가장 긴 이름은 " << strlen_maximum << endl;

	system("PAUSE");
}