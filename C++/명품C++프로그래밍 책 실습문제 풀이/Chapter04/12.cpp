#include "Circlemanager.h"
#include <iostream>
using namespace std;
int main() {
	int num;
	cout << "���� ���� >> ";  cin >> num;
	Circlemanager CM(num);
	CM.searchByName();
	CM.searchByArea();
	

	system("PAUSE");
}