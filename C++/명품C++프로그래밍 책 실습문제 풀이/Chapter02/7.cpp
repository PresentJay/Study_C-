#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char input_string[100];

	do
	{
		cout << "�����ϰ������ yes�� �Է��ϼ���>>";
		cin.getline(input_string, 100);
	} while (strcmp(input_string, "yes") != 0);

	system("PAUSE");
}