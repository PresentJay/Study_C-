#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand((unsigned)time(0));
	int n;
	string str;
	while (1) {
		n = rand();
		cout << "�Ʒ��� �� ���� �Է��ϼ���.(exit�� �Է��ϸ� �����մϴ�)" << endl;
		getline(cin, str);
		if (str == "exit") break;
		str[n%str.size()-1] = n % 24 + 96; // n%M+N = N���� (N+M-1)����
		cout << str << endl;
	}
	system("PAUSE");
}