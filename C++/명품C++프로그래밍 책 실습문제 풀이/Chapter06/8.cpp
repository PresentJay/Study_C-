#include <iostream>
#include <string>

using namespace std;

class Trace {
public:
	static string debug[100][2];
	static int index;
	static void put(string tag, string info) { index++;  debug[index][0] = tag; debug[index][1] = info; }
	static void print(string tag) { cout << "----- " << tag << "태그의 Trace 정보를 출력합니다. -----" << endl; for (int i = 0; i <= index; i++) if (debug[i][0] == tag) cout << debug[i][0] << ':' << debug[i][1] << endl; }
	static void print() { cout << "----- 모든 Trace 정보를 출력합니다. -----" << endl; for (int i = 0; i <= index; i++) cout << debug[i][0] << ':' << debug[i][1] << endl; }
};

int Trace::index = -1;
string Trace::debug[100][2] = {};

void f() {
	int a, b, c;
	cout << "두 개의 정수를 입력하세요>>";
	cin >> a >> b;
	Trace::put("f()", "정수를 입력 받았음");
	c = a + b;
	Trace::put("f()", "합 계산");
	cout << "합은 " << c << endl;
}

int main() {
	Trace::put("main()", "프로그램 시작합니다");
	f();
	Trace::put("main()", "종료");

	Trace::print("f()");
	Trace::print();
}