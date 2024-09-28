#pragma once
#include <iostream>
using namespace std;
class Point
{
	int x;
	int y;
public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);
	Point();
	Point(double x);
	Point(double x, double y);
	Point& operator++();
	Point& operator++(int);
	double distance(Point other);
	void print()const;
	~Point();
};
Point operator+(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);
std::ostream& operator<<(std::ostream& os, const Point& obj);
double distance(Point A, Point B);