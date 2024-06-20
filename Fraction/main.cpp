#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#define delimeter "\n-----------------------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction left, const Fraction& right);

class Fraction
{
	int integer;      //цела€ часть
	int numerator;    //числитель
	int denominator;  //знаминатель
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

	explicit Fraction(int integer)
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
	//operators: 
	Fraction& operator*=(Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction& operator/=(Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment: \t\t " << this << endl;
		return *this;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor: \t " << this << endl;
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
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator > denominator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GSD = more;// DSG - Greatest Common Divisor
		numerator /= GSD;
		denominator /= GSD;
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
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction resoult;
	resoult.set_numerator(left.get_numerator()*right.get_numerator());
	resoult.set_denominator(left.get_denominator()*right.get_denominator());
	return resoult;*/


	/*Fraction resoult
	{
		left.get_numerator()* right.get_numerator(),
		left.get_denominator()* right.get_denominator()
	};
	resoult.to_proper();
	return resoult;*/

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()

	).to_proper().reduce();

}

Fraction operator/(const Fraction left, const Fraction& right)
{
	return left * right.inverted();
}
//           Comparison operators

bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return !(left < right);
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return !(left > right);
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())cout << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj = Fraction(integer, numerator, denominator);*/
	const int SIZE = 256;
	char buffer[SIZE] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);

	int numbers[3] = {};
	int n = 0;
	const char delimeters[] = " /()";
	for (char* pch = strtok(buffer, delimeters); pch; pch = strtok(NULL, delimeters))
		numbers[n++] = atoi(pch);//‘ункци€ atoi()принимает строку, и возвращает целочисленный аналог этой строки,
	//т.е, строку преобразует в число.
//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1: obj = Fraction(numbers[0]); break;
	case 2: obj = Fraction(numbers[0], numbers[1]); break;
	case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
	return is;
}


//#define Constructors_check
//#define ARITHMETICAL_OPERATORS_CHECK
//#define CONVERSION_FROM_OTHER_TO_CLASS
#define CONVERSIONS_HOME_WORK
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

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();
	Fraction B(3, 4, 5);
	B.print();
	/*A.to_improper().print();
	A.to_proper().print();

	Fraction C = A / B;
	C.print();*/

	A *= B;
	//cout << A << endl;
	A.print();
	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

	/*
	Fraction B;
	cout << "¬ведите простую дробь: "; cin >> B;
	cout << B << endl;
*/

	Fraction A = (Fraction)5; //Conversion from less to more(from 'int' to 'Fraction')
	//Single-Argument Constructor

#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	cout << A << endl;

	cout << delimeter << endl;
	Fraction B;

	B = Fraction(8);          //Conversion from less to more (from 'int' to 'Fraction')
	//Copy Assignment

	cout << B << endl;
	cout << delimeter << endl;
#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSIONS_HOME_WORK
	Fraction A = 2.75;
	cout << A << endl;
#endif // CONVERSIONS_HOME_WORK

}