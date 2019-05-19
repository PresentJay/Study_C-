#include <iostream>
#include <string>
using namespace std;

class Acount {
	string Owner;
	int id_number, balance;
public:
	Acount(string name, int id, int bal) {	Owner = name;  id_number = id;  balance = bal; }
	void deposit(int add_mass) { balance += add_mass; }
	string getOwner() { return Owner; }
	int withdraw(int minus_mass);
	int inquiry() { return balance; }
};

int Acount::withdraw(int minus_mass) {
	if (balance > minus_mass) {
		balance -= minus_mass;
		return balance;
	}
	else {
		cout << "출금 실패! >> 잔액이 부족합니다." << endl;
		return balance;
	}
}

int main() {
	Acount a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;

	system("PAUSE");
}