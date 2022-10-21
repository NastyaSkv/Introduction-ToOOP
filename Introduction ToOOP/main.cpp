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
	double distance(Point other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = B.get_x() - B.get_x();
	double distance = sqrt(x_distance*x_distance+y_distance*y_distance);
	return distance;
}

//#define STRUCT_POINT
//#define GET_SET_CHECK
#define DISTANCE_CHECK
//#define CONSTRUCTORS_CHECK

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

	#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(5, 7);
	A.print();
	B.print();
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
#endif

#ifdef CONSTRUCTORS_CHECK
	Point A; //Default constructor
	A.print();

	Point B = 5; //Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();
#endif//Homework 2
}