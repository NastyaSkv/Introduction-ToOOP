//(код-копия с рабочего String)
//Проверочный код должен заработать

#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String
{
	size_t size;   //размер строки
	char* str;     //указатель на строку в динамической памяти
public:
	const char* get_str() const
	{
		return str;
	}

	//     CONSTRUCTORS:
	explicit String(size_t size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1; //посчитали размер
		this->str = new char[size] {};
		//копируем полученную строку в выделенную:
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << endl;
	}
	String(const String& other)   //Copy C-r
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << endl;
	}
	//      OPERATORS
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+(String& other)
	{
		this->size += other.size;
		for (int i = 0; i < this->size - 2;)
		{
			for (int z = 0; z < this->size - other.size - 1; z++, i++)
			{
				this->str[i] = this->str[z];
			}
			for (int j = 0; j < other.size - 1; j++, i++)
			{
				this->str[i] = other.str[j];
			}
		}
		return *this;
	}

	//      METHODS
	void print()const
	{
		cout << "size:\t" << size << endl;  //строка
		cout << "str:\t" << str << endl;    //размер строки
	}
};

ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK

	String str1;   //пустая строка размером 80 байт

	str1.print();  //выведем строку
	cout << str1 << endl;

	String str2(22);
	str2.print();

	String str3 = "Hello"; //здесь Hello - строковая константа
	str3.print();

	String str4 = str3;     //Copy Constructor
	cout << str4 << endl;

	String str5;
	str5 = str4;
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef OPERATOR_PLUS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;

#endif // OPERATOR_PLUS_CHECK
}