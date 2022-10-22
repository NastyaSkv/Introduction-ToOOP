#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------\n"

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
	/*Point() //default
	{
		x = y = double();   //double()-значение по умолчанию для типа double
		cout << "Constructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:" << this << endl;
	}*/
	Point(double x = 0, double y = 0) //универсальный конструктор
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)  //Copy Connstructor
	{
		this->x = other.x;
		this->y = other.y;
		cout << "Copy Constructor: " << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//            OPERATORS    //Оператор присваивания
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator++() //Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int/*здесь возможен только int*/) //Postfix increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	//      METHODS:
	double distance(const Point& other)const //const - гарантия безопасности
	{
		/*double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;*/
		//оптимизируем:
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = B.get_x() - B.get_x();
	double distance = sqrt(x_distance*x_distance+y_distance*y_distance);
	return distance;*/
	//оптимизируем:
	return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}
//#define STRUCT_POINT
//#define GET_SET_CHECK
//#define DISTANCE_CHECK //Analysis Homework 2
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_OPERATOR_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
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
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки B до точки A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif
#ifdef CONSTRUCTORS_CHECK
	Point A; //Default constructor
	A.print();

	Point B = 5; //Single-Argument constructor
	B.print();

	Point C(2, 3);
	C.print();

	Point D = C;  //Copy Constructor
	D.print();    //здесь к-р отработал неявно
	Point E;
	E = D;
	E.print();
#endif
#ifdef ASSIGNMENT_OPERATOR_CHECK
	int  a, b, c;
	a = b = c = 0;
	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3);
	cout << delimiter << endl;
#endif
#ifdef ARITHMETICAL_OPERATORS_CHECK
/*  //для прмера
	int a = 2;
	int b = 3;
	int c = a + b;*/

	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;

	A.print();
	B.print();
	C.print();
	++C;
	C.print();
	Point D = C++;
	C.print();
	D.print();

	for (Point i; i.get_x() < 10; ++i)
	{
		i.print();
	}
#endif



}