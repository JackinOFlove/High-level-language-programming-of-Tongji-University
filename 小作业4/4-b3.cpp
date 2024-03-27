/*2253744 林觉凯 软工*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int zeller(int y, int m, int d)
{
	int w, c;
	if (m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
	}
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	while (w < 0)
	{
		w = w + 7;
	}
	w = w % 7;
	return w;
}
void calender(int y, int m, int d, int w)
{
	cout << y << "年" << m << "月" << endl;
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;
	for (int i = 0; i < w; i++)
	{
		cout << "        ";
	}
	int count = w;
	for (int j = 1; j <= d; j++)
	{
		cout << setiosflags(ios::right) << "  " << setw(2) << j << "    ";
		count++;
		if (count == 7)
		{
			cout << endl;
			count = 0;
		}
	}
}
int main()
{
	int y, m, d,w;
	bool leap;
	while (1)
	{
		cout << "请输入年[1900-2100]、月"<<endl;
		cin >> y >> m;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (y < 1900 || y>2100 )
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (m < 1 || m>12)
		{
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			leap = true;
		}
		else
		{
			leap = false;
		}
		if (m == 2)
		{
			if (leap)
			{
				d = 29;
			}
			else
			{
				d = 28;
			}
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			d = 31;
		}
		else
		{
			d = 30;
		}
		w = zeller(y, m, 1);
		cout << endl;
		calender(y, m, d, w);
		cout << endl;
		break;
	}
	return 0;
}