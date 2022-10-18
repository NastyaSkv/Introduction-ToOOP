//В класс Point добавить get / set - методы.
#include<iostream>
using namespace std;


class Point
{
	double x;
	double y;

public:
	double Get_x()
	{
		return(x);
	}

	void Set_x()
	{
		x = 5.4;
	}

	double Get_y()
	{
		return(y);
	}

	void Set_y(double c)
	{
		y = c;
	}

	void Print_x()
	{
		cout << x << endl;
	}

	void Print_y()
	{
		cout << y << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Point A;
	A.Get_x();
	A.Set_x();
	A.Print_x();

	A.Get_y();
	A.Set_y(1.2);
	A.Print_y();
}