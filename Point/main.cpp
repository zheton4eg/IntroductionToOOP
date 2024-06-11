#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor: \t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor: \t" << this << endl;
	}
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	~Point()
	{
		cout << "Detructor: \t" << this << endl;
	}

};
double distance(Point A, Point B);
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP!" << endl;
	Point A(2, 3);
	Point B(7,8);
	A.print();
	B.print();	
	cout << "Расстояние от точки 'A' до точки 'B': " << A.distance(B) << endl;
	cout << "Расстояние между точками 'В' и 'А': " << distance(B, A) << endl;
}
double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}