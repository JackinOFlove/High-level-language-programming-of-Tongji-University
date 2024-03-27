/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int year, month, day;
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (year < 2000 || year>2030 || month < 1 || month>12)
		{
			cout << "输入非法，请重新输入" << endl;
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
			cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
			cin >> week;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
			if (week < 0 || week >  6)
			{
				cout << "输入非法，请重新输入" << endl;
				continue;
			}
			cout << endl;
			cout << year << "年" << month << "月的月历为：" << endl;
			cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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