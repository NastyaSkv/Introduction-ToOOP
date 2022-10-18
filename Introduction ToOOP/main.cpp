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
	//private:
public:
	double x;
	double y;

};

void main()
{
	setlocale(LC_ALL, " ");
	cout << "Hello OOP" << endl;

	int a;     // объявление переменной 'а' типа int
	Point A;   // объявление переменной 'А' типа 'Point'
			   // объявление объекта 'А' структуры 'Point'
			   // объявление экземпляра 'А' структуры 'Point'
	A.x = 2.2; //обращение по имени, здесь ставится точка
	A.y = 3.4;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; //сохраняем адрес в указатель
	cout << pA->x << tab << pA->y << endl; //обращение по адресу - стрелка



}