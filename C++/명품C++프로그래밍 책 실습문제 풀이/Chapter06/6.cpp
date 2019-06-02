#include <iostream>
using namespace std;

class ArrayUtility2 {
public:
	static int* concat(int s1[], int s2[], int size) { int *result = new int[size * 2]; for (int i = 0; i < size * 2; i++)  i < 5 ? result[i] = s1[i] : result[i] = s2[i-5];  return result; }
	static int* remove(int s1[], int s2[], int size, int& retSize);
};

int* ArrayUtility2::remove(int s1[], int s2[], int size, int& retSize) {
	int *result = new int [1];
	bool flag;
	for (int i = 0; i < size; i++) {
		flag = false;
		for (int j = 0; j < size; j++) {	if (s1[i] == s2[j]) flag = true;}
		if (!flag) {	result[retSize] = s1[i]; 	retSize++;	}
	}
	if (retSize == 0) return NULL;
	else return result;
}

int main() {
	int x[5], y[5], size=5, retSize=0;
	
	cout << "������ 5 �� �Է��϶�. �迭 x�� �����Ѵ�>>";
	for (int i = 0; i < size; i++) cin >> x[i];

	cout << "������ 5 �� �Է��϶�. �迭 y�� �����Ѵ�>>";
	for (int i = 0; i < size; i++) cin >> y[i];

	cout << "��ģ ���� �迭�� ����Ѵ�" << endl;
	for (int i = 0; i < size * 2; i++) cout << ArrayUtility2::concat(x, y, size)[i] << ' ';
	cout << endl;

	int *z = ArrayUtility2::remove(x, y, size, retSize);
	cout << "�迭 x[]���� y[]�� �� ����� ����Ѵ�. ������ " << retSize << endl;
	for (int i = 0; i < retSize; i++) cout << z[i] << ' ';
	cout << endl;
}