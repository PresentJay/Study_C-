#include <iostream>
#include <string>

using namespace std;

class Trace {
public:
	static string debug[100][2];
	static int index;
	static void put(string tag, string info) { index++;  debug[index][0] = tag; debug[index][1] = info; }
	static void print(string tag) { cout << "----- " << tag << "�±��� Trace ������ ����մϴ�. -----" << endl; for (int i = 0; i <= index; i++) if (debug[i][0] == tag) cout << debug[i][0] << ':' << debug[i][1] << endl; }
	static void print() { cout << "----- ��� Trace ������ ����մϴ�. -----" << endl; for (int i = 0; i <= index; i++) cout << debug[i][0] << ':' << debug[i][1] << endl; }
};

int Trace::index = -1;
string Trace::debug[100][2] = {};

void f() {
	int a, b, c;
	cout << "�� ���� ������ �Է��ϼ���>>";
	cin >> a >> b;
	Trace::put("f()", "������ �Է� �޾���");
	c = a + b;
	Trace::put("f()", "�� ���");
	cout << "���� " << c << endl;
}

int main() {
	Trace::put("main()", "���α׷� �����մϴ�");
	f();
	Trace::put("main()", "����");

	Trace::print("f()");
	Trace::print();
}