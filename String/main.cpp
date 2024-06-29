#include "String.h"
#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_CHECK
//#define CALLING_CONSTRUCTOR

void main()
{
	setlocale(LC_ALL, "");
#ifdef OPERATOR_PLUS_CHECK

	String str1 = "Hello";
	String str2 = "World";

	//String str3 = str1 + str2;
	String str3;
	cout << delimiter << endl;
	str3 = str1 + str2;
	cout << delimiter << endl;
	cout << str3 << endl;

	cout << str1 << endl;
	cout << str2 << endl;
#endif // OPERATOR_PLUS_CHECK

#ifdef CALLING_CONSTRUCTOR
	String str1;  //default constructor
	str1.print();

	//Single-Argument constructor 'int'
	//String str2 = 8; //explicit constructor так вызвать невозможно
	String str2(8);    //explicit constructor можно вызвать только так
	str2.print();

	String str3 = "Hello"; //Single-Argument constructro 'char'
    str3.print();

	String str4();         //Default constructor//«десь не вызываетс€ никакой конструктор, и не создаЄтс€ объект,
	                       //здесь объ€вл€етс€ функци€ str4(), котора€ не принимает никаких параметров
	                       //и возвращает значение типа 'String'.
	                       // т.е таким образом вызывать defaultConstructor Ќ≈¬ќ«ћќ∆Ќќ,
	//str3.print();
	//≈сли нужно €вно вызвать DefaultConstructor, это делаетс€ следующим образом:
	String str5{}; //явный вызов конструктора по умолчанию
	str5.print();

	//String str6 = str3; //CopyConstructor
	//String str6(str3); //CopyConstructor
	String str6{str3}; //CopyConstructor

	str6.print();

	//—ледовательно, абсолютно любой конструктор можно вызватю при помощи () или {}
#endif // CALLING_CONSTRUCTOR


	

#ifdef CONSTRUCTORS_CHECK


	//реализовать класс 'string' описывающий строку.
	//обеспечить следующие варианты создани€ обьектов:
	//   string str1;    —оздаетс€ пуста€ строка размером 80 байт
	//   srring str2;    —оздаетс€ пуста€ строка размером 8 байт
	//   string str3 = "Hello"; создаваема€ строка инициализируетс€ значением "Hello"
	//   string str4 = "World";
	//   string str5 =  str3 + str4;
	//   cout<<str5<<endl;

	String str1;       //Default constructor
	str1.print();
	//String str2=8;       //Conversion from 'int' to 'String'
	String str2(8);        // Single-argument 'int' constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = "World";
	str4.print();
	cout << str3 << endl;
	cout << str4 << endl;

	//String str5 = str3 + str4;
	String str5;
	str5 = str3 + str4;
	str5.print();
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK


}