//1. Написать метод ? ? ? distance(? ? ? ) который возвращает расстояние до указанной точки;
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
	double get_c()const
	{
		return c;
	}
	void set_c(double c)
	{
		this->c = c;
	}
	double get_d()const
	{
		return d;
	}
	void set_d(double d)
	{
		this->d = d;
	}

	Point()
	{
		this->c = 0;
		this->d = 0;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	~Point() {}

	void Print()const
	{
		cout << c << ";" << d << endl;
	}
	void Print_xy(double x, double y)
	{
		cout << x << ";" << y << endl;
	}
	double Distance()
	{
		z = sqrt((x - c) * (x - c) + (y - d) * (y - d));
		return(z);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Point A;
	double C = A.get_c();
	double D = A.get_d();

	Point B(2, 4);
	double X = B.get_x();
	double Y = B.get_y();
	cout << "Расстояние до точки = " << B.Distance() << endl;
	cout << "Расстояние между двумя точками = " << distance(X, Y, C, D) << endl;
}

double distance(double x, double y, double c, double d)
{
	double z = sqrt((x - c) * (x - c) + (y - d) * (y - d));
	return(z);
}