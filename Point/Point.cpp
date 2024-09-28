#include "Point.h"


double Point:: get_x()const
{
	return x;
}
double Point:: get_y()const
{
	return y;
}
void Point:: set_x(double x)
{
	this->x = x;
}
void Point:: set_y(double y)
{
	this->y = y;
}
Point::Point()
{
	x = y = 0;
	cout << "DefaultConstructor: \t" << this << endl;
}
Point::Point(double x)
{
	this->x = x;
	this->y = 0;
	cout << "1ArgConstructor" << this << endl;
}
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
	cout << "Constructor: \t" << this << endl;
}

Point& Point:: operator++()
{
	x++;
	y++;
	return *this;
}
Point& Point:: operator++(int)
{
	Point old = *this;
	x++;
	y++;
	return old;
}
double Point:: distance(Point other)
{
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
void Point:: print()const
{
	cout << "X = " << x << "\tY = " << y << endl;
}
Point::~Point()
{
	cout << "Detructor: \t" << this << endl;
}

Point operator+(const Point& left, const Point& right)
{
	Point resoult;
	resoult.set_x(left.get_x() + right.get_x());
	resoult.set_y(left.get_y() + right.get_y());
	return resoult;
}
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/

	return left.get_x() == right.get_x() && left.get_y() == right.get_y();

}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
	return os;
}
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
	
}
