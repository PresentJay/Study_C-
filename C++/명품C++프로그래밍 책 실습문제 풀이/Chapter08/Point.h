#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>
using namespace std;
class Point {
	int x, y;
public:
	Point(int x, int y) { this->x = x; this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
protected:
	void move(int x, int y) { this->x = x; this->y = y; }
};

class ColorPoint : public Point {
	string color;
public:
	ColorPoint(int x=0, int y=0, string color="BLACK") : Point(x, y) { this->color = color; }
	void setPoint(int x, int y) { move(x, y); }
	void setColor(string color) { this->color = color; }
	void show() { cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl; }
};

#endif // !POINT_H
