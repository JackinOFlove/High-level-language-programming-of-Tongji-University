/*2253744 林觉凯 软件*/
#include <iostream>
#include <iomanip>
using namespace std;
#define Pi 3.14159
int main()
{
	cout << "请输入半径和高度:" << endl;
	double r, h;
	cin >> r >> h;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2);
	cout << setw(10) << "圆周长" << " : " << Pi * 2 * r << endl;
	cout << setw(10) << "圆面积" << " : " << Pi * r * r << endl;
	cout << setw(10) << "圆球表面积" << " : " << Pi * 4 * r * r << endl;
	cout << setw(10) << "圆球体积" << " : " << Pi * 4 * r * r * r / 3 << endl;
	cout << setw(10) << "圆柱体积" << " : " << Pi * r * r * h << endl;
	return 0;
}