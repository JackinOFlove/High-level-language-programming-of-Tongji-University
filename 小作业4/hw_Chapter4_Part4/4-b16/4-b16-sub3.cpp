/*2253744 �־��� ��*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void same_shigeng(double a, double b, double c)
{
	double x1;
	x1 = -b / (2 * a);
	if (fabs(x1) < 1e-6)
	{
		x1 = 0;
	}
	cout << "���������ʵ����" << endl;
	cout << "x1=x2=" << x1 << endl;
}