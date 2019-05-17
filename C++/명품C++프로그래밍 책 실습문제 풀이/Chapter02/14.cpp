#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char choosing_menu[20];
	int mass, sail = 0;

	while(sail<20000){
		cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl << "주문>> ";
		cin >> choosing_menu >> mass;
		
		if (strcmp(choosing_menu, "에스프레스") == 0) {
			cout << 2000 * mass;
			sail += 2000 * mass;
		}
		else if (strcmp(choosing_menu, "아메리카노") == 0) {
			cout << 2300 * mass;
			sail += 2300 * mass;
		}
		else if (strcmp(choosing_menu, "카푸치노") == 0) {
			cout << 2500 * mass;
			sail += 2500 * mass;
		}
		else {
			cout << "메뉴선택이 잘못되었습니다." << endl;
			mass = 0;
		}
		if (mass != 0)
			cout << "원입니다. 맛있게 드세요." << endl;
	}

	cout << "오늘 " << sail << "원을 판매하여 카페를 닫습니다. 내일 봐요~~~" << endl;
	system("PAUSE");
}