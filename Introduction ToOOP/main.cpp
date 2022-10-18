#include<iostream>
using namespace std;

#define tab "\t"

/*struct Point
{
	double x;
	double y;
};*/

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//      CONSTRUCTORS:
	Point()
	{
		x = y = double();   //double()-значение по умолчанию для типа double
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//      METHODS:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

//#define STRUCT_POINT
//#define GET_SET_CHECK

void main()
{
	setlocale(LC_ALL, " ");
	//cout << "Hello OOP" << endl;

#ifdef STRUCT_POINT
	int a;     // объявление переменной 'а' типа int
	Point A;   // объявление переменной 'А' типа 'Point'
			   // объявление объекта 'А' структуры 'Point'
			   // объявление экземпляра 'А' структуры 'Point'
	A.x = 2.2; //обращение по имени, здесь ставится точка
	A.y = 3.4;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; //сохраняем адрес в указатель
	cout << pA->x << tab << pA->y << endl; //обращение по адресу - стрелка  
#endif // STRUCT_POINT

#ifdef GET_SET_CHECK
	Point A; //объект А состоит из составных частей x и y
	A.set_x(2);
	A.set_y(3);
	//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B;
	B.set_x(5);
	B.set_y(7);
	//cout << B.get_x() << tab << B.get_y() << endl;
	B.print();
#endif

	Point A; //Default constructor
	A.print();

	Point B = 5; //Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();
}