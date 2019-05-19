#include <iostream>
#include <string>
using namespace std;

class Date {
	int year, month, day;
public:
	Date(int a, int b, int c);
	Date(string d);
	void show();
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

Date::Date(int a, int b, int c) {
	year = a;
	month = b;
	day = c;
}

Date::Date(string d) {
	string a, b, c, cash_string;

	a = d.substr(0,d.find('/'));
	cash_string = d.substr(d.find('/')+1);
	b = cash_string.substr(0, cash_string.find('/'));
	c = cash_string.substr(cash_string.find('/')+1);

	year = stoi(a);
	month = stoi(b);
	day = stoi(c);
}

void Date::show() {
	cout << year << "³â" << month << "¿ù" << day << "ÀÏ" << endl;
}


int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/10/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
	system("PAUSE");
}