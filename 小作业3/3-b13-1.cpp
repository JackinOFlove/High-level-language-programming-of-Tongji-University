/*2253744 �־��� ��*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int year, month, day;
	while (1)
	{
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (year < 2000 || year>2030 || month < 1 || month>12)
		{
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		switch (month)
		{
		case 1:
			day = 31;
			break;
		case 2:
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400) == 0)
			{
				day = 29;
				break;
			}
			else
			{
				day = 28;
				break;
			}
		case 3:
			day = 31;
			break;
		case 4:
			day = 30;
			break;
		case 5:
			day = 31;
			break;
		case 6:
			day = 30;
			break;
		case 7:
			day = 31;
			break;
		case 8:
			day = 31;
			break;
		case 9:
			day = 30;
			break;
		case 10:
			day = 31;
			break;
		case 11:
			day = 30;
			break;
		case 12:
			day = 31;
			break;
		}
		while (1)
		{
			int week;
			cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
			cin >> week;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "����Ƿ�������������" << endl;
				continue;
			}
			if (week < 0 || week >  6)
			{
				cout << "����Ƿ�������������" << endl;
				continue;
			}
			cout << endl;
			cout << year << "��" << month << "�µ�����Ϊ��" << endl;
			cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
			for (int i = 0; i < week; i++)
			{
				cout << "        ";
			}
			int count = week;
			for (int j = 1; j <=day; j++)
			{
				cout << setiosflags(ios::right) << "  " << setw(2) << j << "    ";
				count++;
				if (count == 7)
				{
					cout << endl;
					count = 0;
				}
			}
			break;
		}
		cout << endl;
		break;
	}
	return 0;
}