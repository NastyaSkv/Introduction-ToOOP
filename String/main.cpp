#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	size_t size;   //размер строки
	char* str;     //указатель на строку в динамической памяти
public:
	const char* get_str() const
	{
		return str;
	}
	 char* get_str() 
	{
		return str;
	}
	size_t get_size()const
	{
		return size;
	}

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
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor: " << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t" << endl;
	}
	//      OPERATORS
	String& operator=(const String& other)
	{
		if (this == &other)return *this;  //проверка на "дурака"
		delete[] this->str;               //удаление предыдущих данных
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
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
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	char& operator[](int i)const  //i - index
	{
		return str[i];
	}

	//      METHODS
	void print()const
	{
		cout << "size:\t" << size << endl;  //строка
		cout << "str:\t" << str << endl;    //размер строки
	}
};

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

//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;   //пустая строка размером 80 байт
				   //здесь отрабатывает конструктор по умолчанию
	str1.print();  //выведем строку
	cout << str1 << endl;

	//если мы хотим создавать строки нужного размера
	//String str2 = 22; //из-за explicit мы не можем так сделать
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
	/*String str3;
	str3= str1 + str2;
	cout << str3 << endl;*/
	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK
}