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
	//String str2 = 8; //explicit constructor ��� ������� ����������
	String str2(8);    //explicit constructor ����� ������� ������ ���
	str2.print();

	String str3 = "Hello"; //Single-Argument constructro 'char'
    str3.print();

	String str4();         //Default constructor//����� �� ���������� ������� �����������, � �� �������� ������,
	                       //����� ����������� ������� str4(), ������� �� ��������� ������� ����������
	                       //� ���������� �������� ���� 'String'.
	                       // �.� ����� ������� �������� defaultConstructor ����������,
	//str3.print();
	//���� ����� ���� ������� DefaultConstructor, ��� �������� ��������� �������:
	String str5{}; //����� ����� ������������ �� ���������
	str5.print();

	//String str6 = str3; //CopyConstructor
	//String str6(str3); //CopyConstructor
	String str6{str3}; //CopyConstructor

	str6.print();

	//�������������, ��������� ����� ����������� ����� ������� ��� ������ () ��� {}
#endif // CALLING_CONSTRUCTOR


	

#ifdef CONSTRUCTORS_CHECK


	//����������� ����� 'string' ����������� ������.
	//���������� ��������� �������� �������� ��������:
	//   string str1;    ��������� ������ ������ �������� 80 ����
	//   srring str2;    ��������� ������ ������ �������� 8 ����
	//   string str3 = "Hello"; ����������� ������ ���������������� ��������� "Hello"
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