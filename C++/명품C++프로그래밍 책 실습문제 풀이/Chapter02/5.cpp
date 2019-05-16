#include <iostream>
using namespace std;

int main() {
	int x_ch_size = 0;
	char input_String[100];
	cout << "문자들을 입력하라(100개 미만)." << endl;
	try
	{
		cin.getline(input_String, 100);
	}
	catch (const std::exception&)
	{
		cout << "오류" << endl;
		return 0;
	}

	
	for (int i = 0; i < 100; i++) {
		if (input_String[i] == 'x')
			x_ch_size++;
	}

	cout << "x의 개수는 " << x_ch_size << endl;
	system("PAUSE");
}