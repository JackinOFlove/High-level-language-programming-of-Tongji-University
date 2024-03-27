/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void different_shigeng(double a, double b, double c, double delta)
{
	double x1, x2;
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