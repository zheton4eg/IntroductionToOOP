#include <iostream>
using namespace std;
#define delimiter "\n--------------------------------------------\n"
class String
{
	int size;       //������ ������
	char* str;      //��������� �� ������ � ������

public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//        Constructors:
	explicit String(int size = 80):size(size), str(new char[size]{})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "Constructor: \t" << this << endl;
	}
	String(const char str[]): String(strlen(str)+1)
	{
		//this->size = strlen(str) + 1;
		//������� strlen() ���������� ������ ������ � ��������,
		//� ��� ����� �������� ��� ���� ���� ��� NULL-Terminator-a
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "�onstructor: \t" << this << endl;
	}
	String(const String& other):String(new char[size]{})
	{   //DeepCopy - ��������� �����������
		//this->size = other.size;
		//this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor: " << this << endl;
	}

	String(String&& other)noexcept:size(other.size), str(other.str)//r-value reference
	{
		//Shallow copy:
		//this->size = other.size;
		//this->str = other.str; //shallow copy

		//Reset other:
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor: " << this << endl;
	}
	~String()
	{
		delete[]str;
		cout << "Destructor: \t" << this << endl;
	}
	//        Operators
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignemt: " << this << endl;
		return *this;
	}

	String& operator=(String&& other)noexcept //r-value reference
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignment: \t" << this << endl;
		return *this;

	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//         Methods:
	void print()const
	{
		cout << "Obj:\t\t" << this << endl;
		cout << "Size: \t\t" << size << endl;
		cout << "Addr: \t\t" << &str << endl;
		cout << "Str: \t\t" << str << endl;
		cout << delimiter << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String buffer(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//buffer.get_str()[i] = left.get_str()[i];
		buffer[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return buffer;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_CHECK
#define CALLING_CONSTRUCTOR

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