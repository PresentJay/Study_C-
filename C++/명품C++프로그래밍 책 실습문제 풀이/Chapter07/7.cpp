#include <iostream>
using namespace std;

class Matrix {
	int column[4];
public:
	Matrix(int w = 0, int x = 0, int y = 0, int z = 0) { column[0] = w; column[1] = x; column[2] = y; column[3] = z; }
	void show() { cout << "Matrix = { ";  for (int i = 0; i < 4; i++) cout << column[i] << ' '; cout << '}' << endl; }
	/*
	Matrix &operator << (int* source) { for (int i = 0; i < 4; i++) column[i] = source[i]; return *this; }
	Matrix &operator >> (int* destination) { for (int i = 0; i < 4; i++) destination[i] = column[i]; return *this; }
	*/
	friend Matrix &operator << (Matrix &op1, int* op2) { for (int i = 0; i < 4; i++) op1.column[i] = op2[i]; return op1; }
	friend Matrix &operator >> (Matrix &op1, int* op2) { for (int i = 0; i < 4; i++) op2[i] = op1.column[i]; return op1; }
};

int main() {
	Matrix a(4, 3, 2, 1), b;
	int x[4], y[4] = { 1,2,3,4 };
	a >> x;
	b << y;

	for (int i = 0; i < 4; i++) cout << x[i] << ' ';
	cout << endl;
	b.show();
}