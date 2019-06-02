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
	
	cout << "정수를 5 개 입력하라. 배열 x에 삽입한다>>";
	for (int i = 0; i < size; i++) cin >> x[i];

	cout << "정수를 5 개 입력하라. 배열 y에 삽입한다>>";
	for (int i = 0; i < size; i++) cin >> y[i];

	cout << "합친 정수 배열을 출력한다" << endl;
	for (int i = 0; i < size * 2; i++) cout << ArrayUtility2::concat(x, y, size)[i] << ' ';
	cout << endl;

	int *z = ArrayUtility2::remove(x, y, size, retSize);
	cout << "배열 x[]에서 y[]를 뺀 결과를 출력한다. 개수는 " << retSize << endl;
	for (int i = 0; i < retSize; i++) cout << z[i] << ' ';
	cout << endl;
}