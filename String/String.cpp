#include "String.h"


//-----------------------------------------------------------------------------------------------------------------//

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 ////////////////////////////////////Начало определения класса(Class declaration)////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//        Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "Constructor: \t" << this << endl;
}
String::String(const char str[]) : String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//Функция strlen() возвращает размер строки в символах,
	//и нам нужно добавить еще один Байт для NULL-Terminator-a
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Сonstructor: \t" << this << endl;
}
String::String(const String& other) :String(new char[size] {})
{   //DeepCopy - побитовое копирование
	//this->size = other.size;
	//this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor: " << this << endl;
}

String::String(String&& other)noexcept :size(other.size), str(other.str)//r-value reference
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str; //shallow copy

	//Reset other:
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor: " << this << endl;
}
String::~String()
{
	delete[]str;
	cout << "Destructor: \t" << this << endl;
}
//        Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[]this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignemt: " << this << endl;
	return *this;
}

String& String::operator=(String&& other)noexcept //r-value reference
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
const char& String::operator[](int i)const
{
	return str[i];
}
char& String:: operator[](int i)
{
	return str[i];
}
//         Methods:
void String::print()const
{
	cout << "Obj:\t\t" << this << endl;
	cout << "Size: \t\t" << size << endl;
	cout << "Addr: \t\t" << &str << endl;
	cout << "Str: \t\t" << str << endl;
	cout << delimiter << endl;
}

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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////Конец определения класса(Class declaration)/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
