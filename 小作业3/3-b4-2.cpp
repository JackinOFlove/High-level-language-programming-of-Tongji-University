/*2253744 �־��� ���*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define Pi 3.14159
int main()
{
	cout << "�����������ε����߼���н�:" << endl;
	int a, b, angel;
	cin >> a >> b >> angel;
	cout << setiosflags(ios::fixed) << setprecision(3);
	double area = 0.5 * sin(angel * Pi / 180) * a * b;
	area = (float)area;
	cout << "�����ε����Ϊ : " << area << endl;
	return 0;
}