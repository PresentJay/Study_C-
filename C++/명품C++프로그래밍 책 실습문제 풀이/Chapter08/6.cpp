#include "BaseArray.h"

int main() {
	MyStack mStack(100);
	int n;
	cout << "ť�� ������ 5���� ������ �Է��϶�>> ";
	for (int i = 0; i < 5; i++) {
		cin >> n;
		mStack.push(n);
	}
	cout << "ť�� �뷮:" << mStack.capacity() << ", ť�� ũ��:" << mStack.length() << endl;
	cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
	while (mStack.length() != 0) { cout << mStack.pop () << ' '; }
	cout << endl << "ť�� ���� ũ�� : " << mStack.length() << endl;
}