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
		 this->x=x;
	}
	 void set_y(double y)
	{
		this->y=y;
	}
	/* Point()
	 {
		 x = y = 0;
		 cout << "DefaultConstructor: \t" << this << endl;
	 }
	 Point(double x)
	 {
		 this->x = x;
		 this->y = 0;
		 cout << "1ArgConstructor" << this << endl;
	 }*/
	 Point(double x=0,double y=0)
	 {
		 this->x = x;
		 this->y = y;
		 cout << "Constructor: \t" << this << endl;
	 }
	 ~Point()
	 {
		 cout << "Detructor: \t" << this << endl;
	 }
	 void print()const
	 {
		 cout << "X = " << x << "\tY = " << y << endl;
	 }

};
#define STRUCT_POINT

void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello OOP!" << endl;
#ifdef STRUCT_POINT
	Point A;

	Point B = 5;

	Point C(2, 3);
	C.print();
	
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	B.print();
	//int* pA = &A;
	//cout << pA->x << "\t" << pA->y << endl;
#endif  STRUCT_POINT
} 