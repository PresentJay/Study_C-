#include <iostream>
using namespace std;

class Matrix {
	int column[4];
public:
	Matrix(int w = 0, int x = 0, int y = 0, int z = 0) { column[0] = w; column[1] = x; column[2] = y; column[3] = z; }
	void show() { cout << "Matrix = { ";  for (int i = 0; i < 4; i++) cout << column[i] << ' '; cout << '}' << endl; }
	friend Matrix operator + (Matrix op1, Matrix op2) { Matrix temp; for (int i = 0; i < 4; i++)  temp.column[i] = op1.column[i] + op2.column[i]; return temp;}
	friend Matrix &operator += (Matrix &op1, Matrix op2) { for (int i = 0; i < 4; i++) op1.column[i] += op2.column[i]; return op1; }
	friend bool operator == (Matrix op1, Matrix op2) { if (op1.column[0] == op2.column[0] && op1.column[1] == op2.column[1] && op1.column[2] == op2.column[2] && op1.column[3] == op2.column[3]) return true; else return false; }
	/*
	Matrix operator +(Matrix op2) { Matrix temp; for (int i = 0; i < 4; i++) temp.column[i] = column[i] + op2.column[i]; return temp; }
	Matrix &operator += (Matrix op2) { for (int i = 0; i < 4; i++) column[i] += op2.column[i]; return *this; }
	bool operator == (Matrix op2) { if (column[0] == op2.column[0] && column[1] == op2.column[1] && column[2] == op2.column[2] && column[3] == op2.column[3]) return true; else return false; }
	*/
};

int main() {
	Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c;
	c = a + b;
	a += b;
	a.show(); b.show(); c.show();
	if (a == c) cout << "a and c are the smae" << endl;
}