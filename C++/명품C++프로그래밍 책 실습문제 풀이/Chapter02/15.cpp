#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char str[30];
	char opp;
	int a, b, result;
	while (1){
		cout << "? ";
		for (int i = 0; i < 3; i++) {
			cin.getline(str, 30, ' ');
			switch (i) {
			case 0:
				a = atoi(str);
				break;
			case 1:
				if (strlen(str) == 1)
					opp = str[0];
				break;
			case 2:
				b = atoi(str);
				break;
			default:
				break;
			}
		}
		switch (opp) {
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			result = a / b;
			break;
		case '%':
			result = a % b;
			break;
		default:
			opp = ' ';
			break;
		}
		if (opp != ' ')
			cout << a << " " << opp << " " << b << " = " << result << endl;

	}
	system("PAUSE");
}