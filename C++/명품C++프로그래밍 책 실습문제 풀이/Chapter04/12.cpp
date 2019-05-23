#include "Circlemanager.h"
#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "원의 개수 >> ";  cin >> num;
	Circlemanager CM(num);
	CM.searchByName();
	CM.searchByArea();
	

	system("PAUSE");
}