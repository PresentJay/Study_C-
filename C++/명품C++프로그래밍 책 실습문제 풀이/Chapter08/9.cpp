#include <iostream>
#include <string>

using namespace std;


class Airplane {
	string *Passangers;
	string name;
public:
	Airplane() { Passangers = new string[8]{ "---","---","---","---","---","---","---","---" }; }
	void Reservation(int index, string name) { if (Passangers[index - 1] == "---") Passangers[index - 1] = name; else cout << "이미 예약된 좌석입니다." << endl; }
	void setName(string name) { this->name = name; }
	string getName() { return name; }
	void Cancle_Reservation(int index, string name) { if (Passangers[index - 1] == name) Passangers[index - 1] = "---"; else cout << "해당 예약정보가 없습니다." << endl; }
	void Show() { cout << name << ":"; for (int i = 0; i < 8; i++) cout << "\t" << Passangers[i]; cout << endl; }
};

class Airline {
	string name;
	Airplane* airplane;
public:
	Airline(string name, int airplanes) { this->name = name; airplane = new Airplane[airplanes]; }
	void Reserving_by_Airplane(int a_index, int index, string name) { airplane[a_index].Reservation(index, name); }
	void Canceling_by_Airplane(int a_index, int index, string name) { airplane[a_index].Cancle_Reservation(index, name); }
	void SetName_by_Airplane(int a_index, string name) { airplane[a_index].setName(name); }
	string getName_by_Airplane(int a_index) { return airplane[a_index].getName(); }
	void systemON() {
		int answer1, answer2, answer3;
		string answer4;
		cout << "***** " << name << "에 오신것을 환영합니다 *****" << endl;
		do {
			cout << endl << endl << "예약:1, 취소:2, 보기:3, 끝내기:4>> ";
			cin >> answer1;
			switch (answer1) {
			case 1:
				cout << getName_by_Airplane(0) << ":1, " << getName_by_Airplane(1) << ":2, " << getName_by_Airplane(2) << ":3>> ";
				cin >> answer2;
				airplane[answer2 - 1].Show();
				cout << "좌석 번호>> ";
				cin >> answer3;
				cout << "이름 입력>> ";
				cin >> answer4;
				Reserving_by_Airplane(answer2-1, answer3, answer4);
				break;
			case 2:
				cout << getName_by_Airplane(0) << ":1, " << getName_by_Airplane(1) << ":2, " << getName_by_Airplane(2) << ":3>> ";
				cin >> answer2;
				airplane[answer2 - 1].Show();
				cout << "좌석 번호>> ";
				cin >> answer3;
				cout << "이름 입력>> ";
				cin >> answer4;
				Canceling_by_Airplane(answer2-1, answer3, answer4);
				break;
			case 3:
				airplane[0].Show();
				airplane[1].Show();
				airplane[2].Show();
			case 4: break;
			default:
				cout << "잘못된 접근입니다. 다시 시도하십시오" << endl; break;
			}
		} while (answer1 != 4);
		cout << "예약 시스템을 종료합니다." << endl;
	}
};


int main() {
	Airline Hansung("한성항공", 3);
	Hansung.SetName_by_Airplane(0, "07시");
	Hansung.SetName_by_Airplane(1, "12시");
	Hansung.SetName_by_Airplane(2, "17시");
	
	Hansung.systemON();
}