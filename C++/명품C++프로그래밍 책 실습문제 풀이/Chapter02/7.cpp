#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char input_string[100];

	do
	{
		cout << "종료하고싶으면 yes를 입력하세요>>";
		cin.getline(input_string, 100);
	} while (strcmp(input_string, "yes") != 0);

	system("PAUSE");
}