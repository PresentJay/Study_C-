#include <iostream>
using namespace std;
int main() {

	int input, i = 1;
	int dimension;

	cout << "�ٲ� �ڸ��� üũ>> ";
	cin >> dimension;
	int cash = pow(10, dimension - 1);
	do {
		cout << dimension << "�ڸ� ���� �Է� >> ";
		cin >> input;
	} while (input%cash == 0);	//�ڸ��� Ȯ��

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