#include <iostream>

using namespace std;

int main() {
	int *p = new int [5];
	if (!p) return 0;
	double result = 0.0;
	cout << "���� 5�� �Է�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> p[i];
		result += (double)p[i];
	}
	cout << "��� " << result / 5 << endl;
	delete[] p;
	system("PAUSE");
}