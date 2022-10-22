//1. Написать метод ? ? ? distance(? ? ? ) который возвращает расстояние до указанной точки;
//2. Написать функцию ? ? ? distance(? ? ? ) которая возвращает расстояние между двумя точками;
#include<iostream>
using namespace std;

class Point
{
	double x;
	double y;

public:

	double get_x()const
	{
		return x;
	}
	void set_x()
	{
		this->x = x;
	}
	double get_y()const
	{
		return y;
	}
	void set_y()
	{
		this->y = y;
	}

	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
	}
	~Point() {}
	
	double Distance(const Point& other) const //Method
	{
		return sqrt(pow(this->x - other.x, 2) + (pow(this->y - other.y, 2)));
	}
};

double distance(const Point& A, const Point& B) //Function
{
	return sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)));
}

void main()
{
	setlocale(LC_ALL, "");
	Point A(2, 3);
	Point B(8, 9);

	cout << "Расстояние до точки = " << A.Distance(B) << endl;              //Method
	cout << "Расстояние между двумя точками = " << distance(A, B) << endl;  //Function
}

