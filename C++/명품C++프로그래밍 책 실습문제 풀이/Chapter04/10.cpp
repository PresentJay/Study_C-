#include <iostream>
#include <string>

using namespace std;

class Person {
	string name;
public:
	Person() { name = ""; }
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void inputName(string name) { this->name = name; }
};

class Family {
	Person *p;
	int size;
public:
	Family(string name, int size);
	void show();
	~Family();
	void setName(int order, string name);
};

Family::Family(string name, int size) {
	this->size = size;
	p = new Person[size];
}


void Family::setName(int order, string name) {
	p[order].inputName(name);
}

void Family::show() {
	for (int i = 0; i < 3; i++) {
		cout << p[i].getName() << "\t";
	}
	cout << endl;
}

Family::~Family() { delete[] p; }

int main() {
	Family *simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mrs. Simpson");
	simpson->setName(2, "Bart Simpson");

	cout << "Simpson가족은 다음과 같이 3명이다." << endl;
	simpson->show();



	delete simpson;
	system("PAUSE");
}