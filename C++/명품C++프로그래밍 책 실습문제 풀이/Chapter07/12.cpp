#include <iostream>
using namespace std;

class SortedArray {
	int size;
	int *p;
	void sort() {
		for (int i = 0; i < size; i++) {
			for (int j = i; j < size; j++) {
				if (p[i] > p[j]) {
					int temp = p[j];
					p[j] = p[i];
					p[i] = temp;
				}
			}
		}
	}
public:
	SortedArray() { size = 0; p = NULL; }
	SortedArray(SortedArray& src) {  this->size = src.size; this->p = new int[this->size]; for(int i = 0; i < this->size; i++) this->p[i] = src.p[i]; }
	SortedArray(int p[], int size) { this->size = size; 	this->p = new int[size]; 	for (int i = 0; i < size; i++) 	this->p[i] = p[i]; sort(); }
	~SortedArray() { if (p) delete[]p; }
	//SortedArray operator + (SortedArray& op2) { SortedArray temp; temp.size = size + op2.size; temp.p = new int[size]; for (int i = 0; i < temp.size; i++) i < size ? temp.p[i] = p[i] : temp.p[i] = op2.p[i];  return temp; }
	//SortedArray operator + (SortedArray& op2) { int *templist = new int[size + op2.size]; for (int i = 0; i < size + op2.size; i++) i < size ? templist[i] = p[i] : templist[i] = op2.p[i]; SortedArray temp(templist, size + op2.size); return temp; }
	SortedArray& operator = (const SortedArray& op2) { delete[]p; size = op2.size; p = new int[size]; for (int i = 0; i < size; i++) p[i] = op2.p[i]; sort();  return *this; }
	friend SortedArray operator + (SortedArray op1, SortedArray op2) { SortedArray temp; temp.size = op1.size + op2.size; temp.p = new int[temp.size]; for (int i = 0; i < temp.size; i++) i < op1.size ? temp.p[i] = op1.p[i] : temp.p[i] = op2.p[i-op1.size]; return temp; }
	void show() { cout << "배열 출력 : "; for (int i = 0; i < size; i++) cout << p[i] <<         ' '; cout << endl; }
};

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;
	
	a.show();
	b.show();
	c.show();
}