#include <iostream>
#include <string>
using namespace std;

class person {
	string name;
	string tel;
public:
	person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

person::person() {
	name = "";
	tel = "";
}

void	person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	person *people = new person[3];
	string n,p;
	cout << "�̸��� ��ȭ ��ȣ�� �Է��� �ּ���" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "��� " << i + 1 << ">> ";
		cin >> n >> p;
		people[i].set(n, p);
	}
	cout << "��� ����� �̸��� ";
	for (int i = 0; i < 3; i++) 	cout << people[i].getName() << " ";
	cout << endl << "��ȭ��ȣ �˻��մϴ�. �̸��� �Է��ϼ���>>";
	cin >> n;

	for (int i = 0; i < 3; i++) if (people[i].getName() == n) cout << "��ȭ��ȣ�� " << people[i].getTel() << endl;
	system("PAUSE");
}