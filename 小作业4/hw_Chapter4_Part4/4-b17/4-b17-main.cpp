/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
void Judge_a();
void different_shigeng();
void same_shigeng();
void xugeng();
double a, b, c;
int main()
{
	cout << "请输入一元二次方程的三个系数a,b,c:" << endl;
	double delta;
	cin >> a >> b >> c;
	if (fabs(a) < 1e-6)
	{
		a = 0;
	}
	if (fabs(b) < 1e-6)
	{
		b = 0;
	}
	if (fabs(c) < 1e-6)
	{
		c = 0;
	}
	delta = b * b - 4 * a * c;
	Judge_a();
	if (delta >= 0 && a != 0)
	{
		if (delta == 0)
		{
			same_shigeng();
		}
		else
		{
			different_shigeng();
		}
	}
	else if (delta < 0 && a != 0)
	{
		xugeng();
	}
	return 0;
}