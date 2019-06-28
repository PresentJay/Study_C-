#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
	double ratio;
	virtual double convert(double src) = 0;
	virtual string getSourceString() = 0;
	virtual string getDestString() = 0;
public:
	Converter(double ratio) { this->ratio = ratio; }
	void run() {
		double src;
		cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�. ";
		cout << getSourceString() << "�� �Է��ϼ���>> ";
		cin >> src;
		cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
	}
};

class WonToDollar : public Converter {
	double convert(double src) { return src * ratio; }
	string getSourceString() { return "��"; }
	string getDestString() { return "�޷�"; }
public:
	WonToDollar(int Won) : Converter(Won) { ratio = 1 / ratio; } 
};

class KmToMile : public Converter {
	double  convert(double src) { return src * ratio; }
	string getSourceString() { return "Km"; }
	string getDestString() { return "Mile"; }
public:
	KmToMile(double Km) : Converter(Km) { ratio = 1 / Km; }
};