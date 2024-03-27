/*2253744 林觉凯 软件*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define Pi 3.14159
int main()
{
	cout << "请输入一个[1..100亿]间的数字:" << endl;
	double a;
	cin >> a;
	int i, f, f1, f2;
	double n;
	f = (int)rint(modf(a, &n) * 100);
	f1 = f / 10;
	f1 = (int)fmin(9.0, (double)f1);
	f2 = f - f1 * 10;
	f2 = (int)fmin(9.0, (double)f2);
	i = (int)fmod(a, 1000000000.0);
	cout << f  << endl;
	cout << i << endl;
	cout << f1 << endl;
	cout << f2 << endl;
	cout << setiosflags(ios::left);
	cout << setw(6) << "十亿位" << ":" << int(a / 1000000000.0) << endl;
	cout << setw(6) << "亿位" << ":" << i / 100000000 % 10 << endl;
	cout << setw(6) << "千万位" << ":" << i / 10000000 % 10 << endl;
	cout << setw(6) << "百万位" << ":" << i / 1000000 % 10 << endl;
	cout << setw(6) << "十万位" << ":" << i / 100000 % 10 << endl;
	cout << setw(6) << "万位" << ":" << i / 10000 % 10 << endl;
	cout << setw(6) << "千位" << ":" << i / 1000 % 10 << endl;
	cout << setw(6) << "百位" << ":" << i / 100 % 10 << endl;
	cout << setw(6) << "十位" << ":" << i / 10 % 10 << endl;
	cout << setw(6) << "圆" << ":" << i / 1 % 10 << endl;
	cout << setw(6) << "角" << ":" << f1 << endl;
	cout << setw(6) << "分" << ":" << f2 << endl;
	return 0;
}