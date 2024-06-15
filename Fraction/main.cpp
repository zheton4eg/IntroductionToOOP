#include <iostream>
using namespace std;

class Fraction
{
	int integer;      //����� �����
	int numerator;    //���������
	int denominator;  //�����������
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//        Constructors:

	Fraction()
	{
		integer = 0;
		numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor: \t" << this << endl;
	}
	//single-argumenr constructor

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "singleArgumentContructor: " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor: \t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor: \t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//       Methods:

	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	void print()const
	{
		if (integer)cout << integer;
		if (numerator != 0)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
	
};
Fraction operator*(Fraction& left,Fraction& right)
{
	left.to_improper();
	right.to_improper();
	Fraction resoult;
	resoult.set_numerator(left.get_numerator()*right.get_numerator());
	resoult.set_denominator(left.get_denominator()*right.get_denominator());
	return resoult;

}

//#define Constructors_check

void main()
{
	setlocale(LC_ALL, "");
#ifdef Constructors_check
	Fraction A;    //default constructor
	A.print();

	Fraction B = 5;//Single-argument constructor
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();
#endif // Constructors_check

	Fraction A(2, 3, 4);
	A.print();
	Fraction B (3, 4, 5);
	B.print();
	A.to_improper().print();
	A.to_proper().print();

	Fraction C = A * B;
	C.print();
} 