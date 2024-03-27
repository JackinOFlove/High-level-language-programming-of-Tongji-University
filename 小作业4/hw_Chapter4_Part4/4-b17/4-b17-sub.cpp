/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void Judge_a()
{
	extern double a;
	if (a == 0)
	{
		cout << "不是一元二次方程" << endl;
	}
}
void different_shigeng()
{
	double x1, x2, delta;
	extern double a, b, c;
	delta = b * b - 4 * a * c;
	x1 = (-b + sqrt(delta)) / (2 * a);
	x2 = (-b - sqrt(delta)) / (2 * a);
	if (fabs(x1) < 1e-6)
	{
		x1 = 0;
	}
	if (fabs(x2) < 1e-6)
	{
		x2 = 0;
	}
	if (x1 < x2)
	{
		double temp = x1;
		x1 = x2;
		x2 = temp;
	}
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << x1 << endl;
	cout << "x2=" << x2 << endl;
}
void same_shigeng()
{
	double x1;
	extern double a, b, c;
	x1 = -b / (2 * a);
	if (fabs(x1) < 1e-6)
	{
		x1 = 0;
	}
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << x1 << endl;
}
void xugeng()
{
	double shibu, xubu,delta;
	extern double a, b, c;
	delta = b * b - 4 * a * c;
	shibu = -b / (2 * a);
	xubu = sqrt(-delta) / (2 * a);
	if (fabs(shibu) < 1e-6)
	{
		shibu = 0;
	}
	if (fabs(xubu) < 1e-6)
	{
		xubu = 0;
	}
	if (fabs(xubu - 1) < 1e-6)
	{
		xubu = 1;
	}
	if (fabs(xubu + 1) < 1e-6)
	{
		xubu = -1;
	}
	cout << "有两个虚根：" << endl;
	if (xubu != 0)
	{
		xubu = fabs(xubu);
		if (xubu == 1)
		{
			if (shibu != 0)
			{
				cout << "x1=" << shibu << "+" << "i" << endl;
				cout << "x2=" << shibu << "-" << "i" << endl;
			}
			else
			{
				cout << "x1=i" << endl;
				cout << "x2=-i" << endl;
			}
		}
		else
		{
			if (shibu != 0)
			{
				cout << "x1=" << shibu << "+" << xubu << "i" << endl;
				cout << "x2=" << shibu << "-" << xubu << "i" << endl;
			}
			else
			{
				cout << "x1=" << xubu << "i" << endl;
				cout << "x2=-" << xubu << "i" << endl;
			}
		}
	}
	else
	{
		cout << "x1=" << shibu << endl;
		cout << "x2=" << shibu << endl;
	}
}