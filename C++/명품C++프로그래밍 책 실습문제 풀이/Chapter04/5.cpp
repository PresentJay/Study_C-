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
		cout << "아래에 한 줄을 입력하세요.(exit를 입력하면 종료합니다)" << endl;
		getline(cin, str);
		if (str == "exit") break;
		str[n%str.size()-1] = n % 24 + 96; // n%M+N = N부터 (N+M-1)까지
		cout << str << endl;
	}
	system("PAUSE");
}