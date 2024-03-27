/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void xugeng(double a, double b, double c, double delta)
{
	double shibu, xubu;
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