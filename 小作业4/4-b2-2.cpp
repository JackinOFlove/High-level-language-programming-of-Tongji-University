/*2253744 �־��� ��*/
#include <iostream>
#include <cmath>
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
int main()
{
	int w, y, m, d;
	bool leap;
	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		if (y < 1900 || y>2100)
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (m < 1 || m > 12)
		{
			cout << "�·ݲ���ȷ������������" << endl;
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
			if ((leap && (d < 1 || d>29)) || (!leap && (d < 1 || d>28)))
			{
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 0 || d>31)
			{
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		else
		{
			if (d < 0 || d>30)
			{
				cout << "�ղ���ȷ������������" << endl;
				continue;
			}
		}
		w = zeller(y, m, d);
		switch (w)
		{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
		}
		break;
	}
	return 0;
}