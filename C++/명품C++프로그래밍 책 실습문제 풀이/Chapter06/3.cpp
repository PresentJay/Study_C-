#include <iostream>
using namespace std;

int big(int x, int y, int z = 100) { int bigger = 0; x > y ? x < z ? bigger = x : bigger = z : y < z ? bigger = y : bigger = z; return bigger; }

int main() {
	int x = big(3, 5);
	int y = big(300, 60);
	int z = big(30, 60, 50);
	cout << x << ' ' << y << ' ' << z << endl;
}