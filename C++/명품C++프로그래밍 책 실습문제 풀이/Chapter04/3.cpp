#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cout << "���ڿ� �Է�>> ";
	getline(cin, str);

	int asum = 0;
	int c_index = 0;
	string c_str = str;
	while (1) {
		c_index = c_str.find('a');
		if (c_index == -1) break;
		c_str = c_str.substr(c_index + 1);
		asum++;
	}

	cout << "���� a�� " << asum << "�� �ֽ��ϴ�." << endl;
	system("PAUSE");
}