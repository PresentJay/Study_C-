#include <iostream>
//#include <cstring>
#include <string>
using namespace std;

int main() {
	string password, pw_tester;

	/*
	char password[100];
	char pw_tester[100];*/

	cout << "새 암호를 입력하세요>>";
	cin >> password;
	cout << "새 암호를 다시 한 번 입력하세요>>";
	cin >> pw_tester;

	/*
	if (strcmp(password, pw_tester) == false)
		cout << "같습니다" << endl;
	else
		cout << "같지 않습니다" << endl;
	*/

	if (password == pw_tester)
		cout << "같습니다" << endl;
	else
		cout << "같지 않습니다" << endl;

	system("PAUSE");
}