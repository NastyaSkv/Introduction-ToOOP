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

	int a;     // ���������� ���������� '�' ���� int
	Point A;   // ���������� ���������� '�' ���� 'Point'
			   // ���������� ������� '�' ��������� 'Point'
			   // ���������� ���������� '�' ��������� 'Point'
	A.x = 2.2; //��������� �� �����, ����� �������� �����
	A.y = 3.4;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; //��������� ����� � ���������
	cout << pA->x << tab << pA->y << endl; //��������� �� ������ - �������



}