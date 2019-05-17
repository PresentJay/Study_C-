#include <iostream>
using namespace std;
int main() {

	int input, i = 1;
	int dimension;

	cout << "바꿀 자릿수 체크>> ";
	cin >> dimension;
	int cash = pow(10, dimension - 1);
	do {
		cout << dimension << "자리 숫자 입력 >> ";
		cin >> input;
	} while (input%cash == 0);	//자릿수 확인

	int *num_n = new int[dimension];

	for (int j = dimension-1; j >= 0; j--) {
		cash = pow(10, j);
		num_n[j] = input / cash;
		input -= cash * num_n[j];
	}

	for (int j = 0; j < dimension; j++)		cout << num_n[j];

	cout << endl;
	delete[] num_n;
}