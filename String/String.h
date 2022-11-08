#pragma once
//StringSeparation
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::size_t;

////////////////////////////////////////////////////////////////////////
//////////////   ќбъ€вление класса - class daclaration    //////////////

class String;
String operator+(const String& left, const String& right);
ostream& operator<<(ostream& os, const String& obj);


class String
{
	size_t size;   //размер строки
	char* str;     //указатель на строку в динамической пам€ти
public:
	const char* get_str() const;
	char* get_str();
	size_t get_size()const;

	//     CONSTRUCTORS:
	/*String()     //дефолтный конструктор
	{
		this->size = 80;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << endl;
	}
	String(size_t size)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Constructor:\t" <<this<< endl;
	}*/ //совместим 2 конструктора в один
	explicit String(size_t size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();

	//      OPERATORS
	String& operator=(const String& other);
	String& operator=(String&& other);
	String& operator+=(const String& other);
	char operator[](int i)const;
	char& operator[](int i);

	//      METHODS
	void print()const;
};

//////////////             онец объ€вление класса         //////////////
////////////////////////////////////////////////////////////////////////
