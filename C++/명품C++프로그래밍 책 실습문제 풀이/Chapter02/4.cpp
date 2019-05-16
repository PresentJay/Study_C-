#include <iostream>
using namespace std;

int main() {
	double D_array[6];
	D_array[5] = 0;
	cout << sizeof(D_array)/sizeof(D_array[0])-1 << " 개의 실수를 입력하라>>";	//배열의 크기 구하는 방법 : sizeof(배열변수) 나누기 sizeof[0]    <-  sizeof가 바이트단위 크기이기 때문.
	for (int i = 0; i < 5; i++) {
		cin >> D_array[i];
		if (D_array[i] > D_array[5])
			D_array[5] = D_array[i];
	}
	cout << "제일 큰 수 = " << D_array[5] << endl;
	system("PAUSE");
}