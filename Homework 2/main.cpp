/*//1. Написать метод ? ? ? distance(? ? ? ) который возвращает расстояние до указанной точки;
//2. Написать функцию ? ? ? distance(? ? ? ) которая возвращает расстояние между двумя точками;
#include<iostream>
#include<cmath>
using namespace std;

double distance(double x, double y, double c, double d);

class Point
{
	double x;
	double y;
	double c;
	double d;
	double z;
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
	/*
	void Print()const
	{
		cout << c << ";" << d << endl;
	}
	void Print_xy(double x, double y)
	{
		cout << x << ";" << y << endl;
	}
	
	double Distance(Point other)
	{
		return(sqrt(pow(this->x - other.x, 2) + (pow(this->y - other.y, 2));
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Point A(2, 3);

	Point B(8, 9);

	cout << "Расстояние до точки = " << B.Distance(A) << endl;
	//cout << "Расстояние между двумя точками = " << distance(X, Y, C, D) << endl;
}

double distance(double x, double y, double c, double d)
{
	double z = sqrt((x - c) * (x - c) + (y - d) * (y - d));
	return(z);
}
*/