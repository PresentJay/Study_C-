#include <iostream>
//#include <cstring>
#include <string>
using namespace std;

int main() {
	string password, pw_tester;

	/*
	char password[100];
	char pw_tester[100];*/

	cout << "�� ��ȣ�� �Է��ϼ���>>";
	cin >> password;
	cout << "�� ��ȣ�� �ٽ� �� �� �Է��ϼ���>>";
	cin >> pw_tester;

	/*
	if (strcmp(password, pw_tester) == false)
		cout << "�����ϴ�" << endl;
	else
		cout << "���� �ʽ��ϴ�" << endl;
	*/

	if (password == pw_tester)
		cout << "�����ϴ�" << endl;
	else
		cout << "���� �ʽ��ϴ�" << endl;

	system("PAUSE");
}