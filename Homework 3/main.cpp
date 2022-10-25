//Реализовать класс Fraction, описывающий простую дробь.
//В классе должны быть все необходимые методы, так же нужно обеспечить
//выполнение арифметических и других важных операций над дробями;
#include<iostream>
using namespace std;

class Fraction
{
	int x;
	int y;
	int o;

public:
	int get_x()const
	{
		return x;
	}
	int get_y()const
	{
		return y;
	}
	int get_o()const
	{
		return o;
	}
	void set_x(int x)
	{
		this->x = x;
	}
	void set_y(int y)
	{
		this->y = y;
	}
	void set_o(int o)
	{
		this->o = o;
	}

	//CONSTRUCTOR
	Fraction(int x = 0, int y = 0, int o = 0)
	{
		this->x = x;
		this->y = y;
		this->o = o;
	}
	~Fraction()
	{
		//cout << "DESTRUCTOR" << endl;
	}
	//            OPERATORS              
	Fraction& operator=(const Fraction& other)
	{
		this->x = other.x;
		this->y = other.y;
		return *this;
	}

	//METHODS
	Fraction Unified(const Fraction& other)const  //приведение к общему знаменателю
	{
		Fraction C, D, rezz;
		C.y = this->y * other.y;           // C = A
		C.x = C.y / this->y * this->x;
		D.y = C.y;                        // D = B
		D.x = D.y / other.y * other.x;
		rezz.x = C.x + D.x;
		rezz.y = C.y;
		return rezz;
	}

	Fraction Reduction() //сокращение дробей
	{
		Fraction r;
		for (int i = 10; i > 1; i--)
		{
			if (this->x % i == 0 && this->y % i == 0)
			{
				this->x = this->x / i;
				this->y = this->y / i;
				i++;
			}
		} return r;
	}

	Fraction Integer()  //выделение общей части
	{
		Fraction res;
		if (this->x > this->y)
		{
			this->o = this->x / this->y;
			this->x = this->x - this->o * this->y;
		}
		return res;
	}

	Fraction Sum(const Fraction& other)const   //Сумма
	{
		Fraction res;
		if (this->y != other.y)return Unified(other);
		else
		{
			res.x = this->x + other.x;
			res.y = this->y;
			return res;
		}
	}

	Fraction Difference(const Fraction& other)const   //Разность
	{
		Fraction res;
		res.x = -other.x;
		res.y = other.y;
		if (this->y != other.y)return Unified(res);
		else
		{
			res.x = this->x - other.x;
			res.y = this->y;
			return res;
		}
	}

	Fraction Multiplication(const Fraction& other)const //умножение
	{
		Fraction res;
		res.x = this->x * other.x;
		res.y = this->y * other.y;
		return res;
	}
	
	Fraction Division(const Fraction& other)const //деление
	{
		Fraction res;
		res.x = this->x * other.y;
		res.y = this->y * other.x;
		return res;
	}
};

//OPERATORS
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_x() == 0)
	{
		os << obj.get_o();
	}
	else if (obj.get_x() == obj.get_y())
	{
		os << "1";
	}
	else if (obj.get_o() != 0)
	{
		os << obj.get_o() << '(' << obj.get_x() << '/' << obj.get_y() << ')';
	}
	else
	{
		os << obj.get_x() << '/' << obj.get_y();
	}
	return os;
}

void main()
{
	setlocale(LC_ALL, "");
	int r, t;

	cout << "Введите числитель и знаменатель дроби А: " << endl; cin >> r >> t;
	Fraction A(r, t);
	cout << "Дробь А: " << A << endl << endl;

	cout << "Введите числитель и знаменатель дроби В: " << endl; cin >> r >> t;
	Fraction B(r, t);
	cout << "Дробь В: " << B << endl << endl;

	Fraction C;
	C = A.Sum(B);                         //считаем сумму
	C.Reduction();                        //сокращаем
	C.Integer();                          //выделяем целую часть
	cout << "Сумма дробей: A + B = " << C << endl;

	Fraction P;
	P = A.Difference(B);                  //считаем разность
	P.Reduction();                        //сокращаем
	P.Integer();                          //выделяем целую часть
	cout << "Разность дробей: A - B = " << P << endl;

	Fraction E;
	E = A.Multiplication(B);              //умножаем
	E.Reduction();                        //сокращаем
	E.Integer();                          //выделяем целую часть
	cout << "Умножение дробей: A * B = " << E << endl;

	Fraction W;
	W = A.Division(B);                    //делим
	W.Reduction();                        //сокращаем
	W.Integer();                          //выделяем целую часть
	cout << "Деление дробей: A : B = " << W << endl;
}