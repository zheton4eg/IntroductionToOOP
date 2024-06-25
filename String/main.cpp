#include <iostream>
using namespace std;
#define delimiter "\n--------------------------------------------\n"
class String
{
	int size;       //размер строки
	char* str;      //указатель на строку в памяти
	 
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
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor: \t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		//Функция strlen() возвращает размер строки в символах,
		//и нам нужно добавить еще один Байт для NULL-Terminator-a
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Сonstructor: \t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor: " << this << endl;
	}

	String(String&& other)noexcept//r-value reference
	{
        //Shallow copy:
		this->size = other.size;
		this-> str = other.str; //shallow copy

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

#define OPERATOR_PLUS_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

	String str1 = "Hello";
	String str2 = "World";

	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;

	cout << str1 << endl;
	cout << str2 << endl;



#ifdef CONSTRUCTORS_CHECK


	//реализовать класс 'string' описывающий строку.
	//обеспечить следующие варианты создания обьектов:
	//   string str1;    Создается пустая строка размером 80 байт
	//   srring str2;    Создается пустая строка размером 8 байт
	//   string str3 = "Hello"; создаваемая строка инициализируется значением "Hello"
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