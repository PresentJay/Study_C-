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
	cout << "이름과 전화 번호를 입력해 주세요" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		cin >> n >> p;
		people[i].set(n, p);
	}
	cout << "모든 사람의 이름은 ";
	for (int i = 0; i < 3; i++) 	cout << people[i].getName() << " ";
	cout << endl << "전화번호 검색합니다. 이름을 입력하세요>>";
	cin >> n;

	for (int i = 0; i < 3; i++) if (people[i].getName() == n) cout << "전화번호는 " << people[i].getTel() << endl;
	system("PAUSE");
}