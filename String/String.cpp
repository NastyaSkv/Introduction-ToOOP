#include"String.h"

//----------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////
//////////////   Определение класса - class definition    //////////////

const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}
std::size_t String::get_size()const
{
	return size;
}

//     CONSTRUCTORS:
String::String(size_t size) :size(size), str(new char[size] {})
{
	//this->size = size; //при верхней форме записи эта строка уже не нужна
	//this->str = new char[size] {};
	cout << "DefConstructor:\t" << endl;
}
String::String(const char str[]) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1; посчитали размер
	//this->str = new char[size] {};
	//копируем полученную строку в выделенную:
	for (int i = 0; i < size; i++)this->str[i] = str[i];
	cout << "Constructor:\t" << endl;
}
String::String(const String& other) :String(other.str)   //Copy C-r
{
	//this->size = other.size;
	//this->str = new char[size] {};
	//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyConstructor:" << this << endl;
}
String::String(String&& other) :size(other.size), str(other.str)
{
	//this->size = other.size;
	//this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor: " << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t" << endl;
}
//      OPERATORS
String& String::operator=(const String& other)
{
	if (this == &other)return *this;  //проверка на "дурака"
	delete[] this->str;               //удаление предыдущих данных
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char String::operator[](int i)const  //i - index
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//      METHODS
void String::print()const
{
	cout << "size:\t" << size << endl;  //строка
	cout << "str:\t" << str << endl;    //размер строки
}

String operator+(const String& left, const String& right)
{
	/*String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		cat.get_str()[i + left.get_size() - 1] = right.get_str()[1];*/
		//усложним
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];

	return cat;
}
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//////////////            Конец определения класса         //////////////
////////////////////////////////////////////////////////////////////////