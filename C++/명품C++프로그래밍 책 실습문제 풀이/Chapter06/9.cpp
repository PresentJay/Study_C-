#include <iostream>
#include <string>
using namespace std;

class Board {
	static string post[100];
	static int index;
public:
	static void add(string contents) { index++; post[index] = contents; }
	static void print() { cout << "************* �Խ����Դϴ�. *************" << endl; for (int i = 0; i <= index; i++) cout << i << ": " << post[i] << endl; }
};

string Board::post[100] = {  };
int Board::index = -1;

int main() {
	Board::add("�߰����� ���� ���� ���� �����Դϴ�.");
	Board::add("�ڵ� ����� ���� �̿��� �ּ���.");
	Board::print();
	Board::add("���Ҹ� �л��� ������ȸ �Ի��Ͽ����ϴ�. �������ּ���");
	Board::print();
}