#include <iostream>

using namespace std;

class CoffeeMachine {
	int coffee, water, sugar;
public:
	CoffeeMachine(int cof, int wat, int sug) {	coffee = cof; water = wat;  sugar = sug;	}
	void show() { cout << "Ŀ�� �ӽ� ����,\tĿ��:" << coffee << "\t��:" << water << "\t����:" << sugar << endl; }
	void drinkEspresso() { coffee--;  water--; }
	void drinkAmericano() { coffee--; water -= 2; }
	void drinkSugarCoffee() { coffee--; water -= 2; sugar--; }
	void fill() { coffee = 10; water = 10; sugar = 10; }
};

int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();

	system("PAUSE");
}