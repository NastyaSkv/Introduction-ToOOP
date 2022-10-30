#include<iostream>
using namespace std;

class String
{
	size_t size;	//ðàçìåð ñòðîêè â Áàéòàõ
	char* str;		//óêàçàòåëü íà ñòðîêó â äèíàìè÷åñêîé ïàìÿòè
public:
	const char* get_str()const
	{
		return str;
	}
	//				Constructors:
	explicit String(size_t size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t" << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	//				Methods:
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;	//пустая строка размером 80 байт
	str1.print();
	cout << str1 << endl;

	String str2(22);
	str2.print();

	String str3 = "Hello";
	str3.print();
	str3 = str3;

	String str4 = str3;		//CopyConstructor
	cout << str4 << endl;

	String str5;			//Default constructor
	str5 = str4;			//Copy assignment
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;
#endif // OPERATOR_PLUS_CHECK


}