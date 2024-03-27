/*2253744 林觉凯 软件*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define Pi 3.14159
int main()
{
	cout << "请输入三角形的两边及其夹角:" << endl;
	int a, b, angel;
	cin >> a >> b >> angel;
	cout << setiosflags(ios::fixed) << setprecision(3);
	double area = 0.5 * sin(angel * Pi / 180) * a * b;
	area = (float)area;
	cout << "三角形的面积为 : " << area << endl;
	return 0;
}