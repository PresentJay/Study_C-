#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char input_char[100];

	cout << "문자열 입력>>";
	cin.getline(input_char, 100);

	for (int i = 0; input_char[i]; i++) {
		for (int j = 0; j <= i; j++)
			cout << input_char[j];
		cout << endl;
	}
	system("PAUSE");
}