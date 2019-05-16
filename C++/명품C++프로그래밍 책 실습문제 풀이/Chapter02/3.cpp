#include <iostream>
using namespace std;

int main() {
	int input_A, input_B;

	cout << "두 수를 입력하라>>";
	cin >> input_A >> input_B;
	if (input_A > input_B)
		cout << "큰 수 = " << input_A << endl;
	else
		cout << "큰 수 = " << input_B << endl;

	system("PAUSE");
}