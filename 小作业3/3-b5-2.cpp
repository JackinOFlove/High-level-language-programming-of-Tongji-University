/*2253744 �־��� �� */
#include <iostream>
using namespace std;
int main()
{
	int year, month, day;
	cout<<"�������꣬�£���"<<endl;
	cin >> year >> month >> day;
	int days = 0;
	switch (month)
	{
	case 12:
		if (day > 31 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 335 + day;
			else
				days = 334 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 11:
		if (day > 30 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 305 + day;
			else
				days = 304 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 10:
		if (day > 31 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 274 + day;
			else
				days = 273 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 9:
		if (day > 30 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 244 + day;
			else
				days = 243 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 8:
		if (day > 31 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 213 + day;
			else
				days = 212 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 7:
		if (day > 31 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 182 + day;
			else
				days = 181 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 6:
		if (day > 30 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 152 + day;
			else
				days = 151 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 5:
		if (day > 31 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 121 + day;
			else
				days = 120 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 4:
		if (day > 30 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 91 + day;
			else
				days = 90 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 3:
		if (day > 31 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 60 + day;
			else
				days = 59 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 2:
		if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
		{
			if (day > 29 || day < 1)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			}
			else
				days = 31 + day;
		}
		else
		{
			if (day > 28 || day < 1)
			{
				cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
				break;
			}
			else
				days = 31 + day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	case 1:
		if (day > 31 || day < 1)
		{
			cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = day;
			else
				days = day;
		}
		cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << days << "��" << endl;
		break;
	default:
		cout << "�������-�·ݲ���ȷ" << endl;
	}
	return 0;
}