#include <iostream>
using namespace std;

int main() {
	double D_array[6];
	D_array[5] = 0;
	cout << sizeof(D_array)/sizeof(D_array[0])-1 << " ���� �Ǽ��� �Է��϶�>>";	//�迭�� ũ�� ���ϴ� ��� : sizeof(�迭����) ������ sizeof[0]    <-  sizeof�� ����Ʈ���� ũ���̱� ����.
	for (int i = 0; i < 5; i++) {
		cin >> D_array[i];
		if (D_array[i] > D_array[5])
			D_array[5] = D_array[i];
	}
	cout << "���� ū �� = " << D_array[5] << endl;
	system("PAUSE");
}