/*2253744 �־��� ��*/
#include <iostream>
using namespace std;
int min(int a, int b,int c = 2147483647,int d = 2147483647)
{
	if (b < a)
	{
		a = b;
	}
	if (c < a)
	{
		a = c;
	}
	if (d < a)
	{
		a = d;
	}
	return a;
}
int main()
{
	int num, a, b, c, d;
	while (1)
	{
		cout << "���������num��num����������" << endl;
		cin >> num;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num < 2 || num > 4)
		{
			cout << "�����������" << endl;
			break;
		}
		if (num == 2)
		{
			cin >> a >> b;
			if (cin.good() == 0 || a <= 0 || b <= 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(1024, '\n');
			break;
		}
		else if (num == 3)
		{
			cin >> a >> b >> c;
			if (cin.good() == 0 || a <= 0 || b <= 0 || c <= 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(1024, '\n');
			break;
		}
		else if (num == 4)
		{
			cin >> a >> b >> c >> d;
			if (cin.good() == 0 || a <= 0 || b <= 0 || c <= 0 || d <= 0)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(1024, '\n');
			break;
		}
	}
	switch (num)
	{
	case 2:
		cout << "min=" << min(a, b) << endl;
		break;
	case 3:
		cout << "min=" << min(a, b, c) << endl;
		break;
	case 4:
		cout << "min=" << min(a, b, c, d) << endl;
		break;
	default:
		break;
	}
	return 0;
}