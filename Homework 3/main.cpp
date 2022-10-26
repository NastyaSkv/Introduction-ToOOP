//ДЗ 3: Реализовать класс Fraction, описывающий простую дробь.
//В классе должны быть все необходимые методы, так же нужно обеспечить
//выполнение арифметических и других важных операций над дробями;

//ДЗ 4: Для класса Fraction перегрузить:
//1. Составные присваивания : +=, -=, *=, /=;
//2. Операторы сравнения : == , != , > , < , >= , <= ;
//3. Написать метод reduce(), который сокращает дробь;

#include<iostream>
using namespace std;

#define delimiter "\n----------------------------------------------------\n"

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
		if (o == 0)o = 1; //фильтрация деления на НОЛЬ
		this->o = o;
	}

	//			  CONSTRUCTOR
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
		this->o = other.o;
		return *this;
	}
	Fraction& operator+= (const Fraction& other)
	{
		this->x = this->x + other.x;
		this->y = other.y;
		return *this;
	}
	Fraction& operator-= (const Fraction& other)
	{
		this->x = this->x - other.x;
		this->y = other.y;
		return *this;
	}
	Fraction& operator*= (const Fraction& other)
	{
		this->x = this->x * other.x;
		this->y = this->y * other.y;
		return *this;
	}
	Fraction& operator/= (const Fraction& other)
	{
		this->x = this->x * other.y;
		this->y = this->y * other.x;
		return *this;
	}

	//            METHODS
	void Unified(Fraction& other) //приведение к общему знаменателю
	{
		this->x = this->y * other.y / this->y * this->x;
		other.x = this->y * other.y / other.y * other.x;
		this->y = this->y * other.y;
		other.y = this->y;
	}
	Fraction Reduction() //сокращение дробей
	{
		for (int i = 10; i > 1; i--)
		{
			if (this->x % i == 0 && this->y % i == 0)
			{
				this->x = this->x / i;
				this->y = this->y / i;
				i++;
			}
		} return *this;
	}
	Fraction Integer()  //выделение общей части
	{
		if (this->x > this->y)
		{
			this->o = this->x / this->y;
			this->x = this->x - this->o * this->y;
		}
		return *this;
	}
	Fraction Sum(const Fraction& other)const   //Сумма
	{
		Fraction res;
		res.x = this->x + other.x;
		res.y = this->y;
		return res;
	}
	Fraction Difference(const Fraction& other)const   //Разность
	{
		Fraction res;
		res.x = this->x - other.x;
		res.y = this->y;
		return res;
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
bool operator==(const Fraction& left, const Fraction& right)
{
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return left.get_x() != right.get_x() || left.get_y() != right.get_y();
}
bool operator>(const Fraction& left, const Fraction& right)
{
	return left.get_x() > right.get_x() && left.get_y() == right.get_y();
}
bool operator<(const Fraction& left, const Fraction& right)
{
	return left.get_x() < right.get_x() && left.get_y() == right.get_y();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	return left.get_x() >= right.get_x() && left.get_y() == right.get_y();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return left.get_x() <= right.get_x() && left.get_y() == right.get_y();
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

	Fraction C, D;
	C = A; D = B;
	if (C.get_y() != D.get_y())C.Unified(D);

	/*  //HOMEWORK 3
		Fraction N;
		N = A.Sum(B);                         //считаем сумму
		N.Reduction();                        //сокращаем
		N.Integer();                          //выделяем целую часть
		cout << "Сумма дробей: A + B = " << N << endl;

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
		cout << "Деление дробей: A : B = " << W << endl<<endl;
	*/
	//HOMEWORK 4
	if (C == D)cout << "Дроби равны" << endl;
	else if (C != D)cout << "Дроби НЕ равны" << endl;
	if (C > D)cout << A << " > " << B << endl;
	else if (C < D)cout << A << " < " << B << endl;
	if (C >= D)cout << A << " >= " << B << endl;
	else if (C <= D)cout << A << " <= " << B << endl << endl;

	cout << delimiter << endl;
	cout << "A = " << C << "\t\t" << "B = " << D << endl << endl;
	Fraction redB = D;
	redB.Reduction();

	Fraction sum = C;       //СУММА
	sum += D;
	cout << "A += B  |->  " << "A = " << sum << "\t";
	sum.Reduction();
	cout << "   |->  " << "A = " << sum << "\t" << "B = " << redB << endl;
	
	Fraction dif = C;      //РАЗНОСТЬ
	dif -= D;
	cout << "A -= B  |->  " << "A = " << dif << "\t";
	dif.Reduction();
	cout << "   |->  " << "A = " << dif << "\t" << "B = " << redB << endl;
	
	Fraction mult = C;     //УМНОЖЕНИЕ
	mult *= D;
	cout << "A *= B  |->  " << "A = " << mult << "\t";
	mult.Reduction();
	cout << "   |->  " << "A = " << mult << "\t" << "B = " << redB << endl;
	
	Fraction div = C;      //ДЕЛЕНИЕ
	div /= D;
	cout << "A /= B  |->  " << "A = " << div << "\t";
	div.Reduction();
	cout << "   |->  " << "A = " << div << "\t" << "B = " << redB << endl;
}