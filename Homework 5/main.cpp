//Проверочный код в секции CONVERSION_FROM_CLASS_TO_OTHER_TYPES должен заработать.
//(код-копия с рабочего classFaction)
#include<iostream>
#include <typeinfo>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------------------\n"
class Fraction; //Объявление класса
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1; //фильтрация деления на НОЛЬ
		this->denominator = denominator;
	}

	//				CONSTRUCTORS:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor:" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:" << this << endl;
	}
	Fraction(double other)
	{
		this->integer = (int)other;
		double i = other - this->integer;
		for (this->denominator = 1; i - (int)i != 0; i *= 10, this->denominator *= 10)this->numerator = i;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//			   OPERATORS
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		integer++;
		return old;
	}

	operator int()const
	{
		return this->integer + this->numerator / this->denominator;
	}
	operator double()const
	{
		return this->integer + double(this->numerator) / this->denominator;
	}

	//				METHODS		 
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer = numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		/*int buffer = inverted.numerator;
		inverted.numerator = inverted.denominator;
		inverted.denominator = buffer;*/
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction Reduct() //сокращение дробей
	{
		for (int i = 10; i > 1; i--)
		{
			if (this->numerator % i == 0 && this->denominator % i == 0)
			{
				this->numerator = this->numerator / i;
				this->denominator = this->denominator / i;
				i++;
			}
		} return *this;
	}
};

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0) os << 0;
	return os;
}
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());*/
	/*Fraction result
	(
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	);
	return result;*/

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator/(const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	).to_proper();*/
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
//				  COMPARISON OPERATORS
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool  operator>=(const Fraction& left, const Fraction& right)
{
	return left > right || left == right;
}
bool  operator<=(const Fraction& left, const Fraction& right)
{
	//return left < right || left == right;
	return !(left > right);
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATOR_CHECK
//#define COMPOUND_ASSIGNMENTS_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
#define CONVERSION_FROM_CLASS_TO_OTHER_TYPES

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK 
	Fraction A;
	cout << A << endl;
	Fraction B = 5;   //Single-argument const
	cout << B << endl;

	Fraction C(2, 3);
	cout << C << endl;

	Fraction D(2, 3, 4);
	cout << D << endl;
#endif
#ifdef ARITHMETICAL_OPERATOR_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	Fraction C = A * B;
	cout << C << endl;
	cout << A / B << endl;
	cout << A + B << endl;

	for (double i = 0; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
#endif
#ifdef COMPOUND_ASSIGNMENTS_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	A *= B;
	cout << A << endl;
#endif
#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 10);
	/*if (A == B)
	{
		cout << "Дроби равны" << endl;
	}
	else
	{
		cout << "Дроби разные " << endl;
	}*/
	cout << (Fraction(1, 2) <= Fraction(5, 9)) << endl;
#endif
#ifdef TYPE_CONVERSIONS_BASICS
	//(type)value;	//C-like notation (Ñ-ïîäîáíàÿ ôîðìà çàïèñè)
//type(value);	//Functional notation (Ôóíêöèîíàëüíàÿ ôîðìà çàïèñè)

//Warning: Conversion from 'type' to 'type', possible loss of data.

//cout << (double)8 / 5 << endl;

	int a = 2;		//No conversions
	double b = 3;	//Conversion from less to more.
	int c = b;		//Conversion from more to less with no data loss.
	int d = 2.999;	//Conversion from more to less with data loss.
	cout << d << endl;
#endif
#ifdef	CONVERSION_FROM_OTHER_TO_CLASS
	//Fraction A = 5;           //неявное преобразование без 'explicit'
	Fraction A = Fraction(5);   //явное преобразование из-за 'explicit'
	cout << A << endl;
	cout << delimiter << endl;
	Fraction B;
	cout << delimiter << endl;
	//B = 8;                    //неявное преобразование без 'explicit'
	B = (Fraction)8;            //явное преобразование из-за 'explicit'
	cout << delimiter << endl;
	cout << B << endl;
#endif
#ifdef CONVERSION_FROM_CLASS_TO_OTHER_TYPES
	Fraction A(0, 3, 2);
	int a = A;
	cout << a << endl;

	double b = A;
	cout << b << endl;

	Fraction B = 2.05;
	B.Reduct();
	cout << B << endl;
	
#endif
}
