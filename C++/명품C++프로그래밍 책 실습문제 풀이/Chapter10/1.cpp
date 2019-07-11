#include <iostream>
using namespace std;

template <class T>
T biggest(T element[], int size) {
	int max = element[0];
	for (int i = 1; i < size; i++) {
		if (max < element[i]) max = element[i];
	}
	return max;
}

int main() {
	int x[] = { 1,10,100,5,4 };
	cout << biggest(x, 5) << endl;
}