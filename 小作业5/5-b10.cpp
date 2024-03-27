/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
//判断闰年
int Judgeleap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
//判断星期
int zeller(int y, int m, int d)
{
	int w, c;
	if (m == 1 || m == 2)
	{
		m = m + 12;
		y = y - 1;
	}
	c = y / 100;
	y %= 100;
	w = y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1;
	while (w < 0)
		w += 7;
	w %= 7;
	return w;
}
//打印月标尺
void Print_month(int quarter)
{
	int begin_month = (quarter - 1) * 3 + 1;
	for (int i = begin_month; i < begin_month + 3; i++)
	{
		cout << "           " << setiosflags(ios::right) << setw(2) << i << "月";
		cout << resetiosflags(ios::right);
		if (i != begin_month + 2)
			cout << "                 "; 	
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		if (i != 2)
			cout << "     "; 
	}
	cout << endl;
}
//打印日
void Print_day(int Month_firstday_week[], int Month_days[])
{
	int Init_location[3];//存储初始打印的位置
	int Saturday_location[3] = { 1,1,1 };//存储每月每个周六的日子
	int maxrow;		//一个季度中月份的最大行
	int Max_row[3];//求该月份最多几行
	bool Is_print_over[3] = { 0,0,0 };//判断该月份是否输出结束
	//求出一个季度的月份中最大行
	for (int i = 0; i < 3; i++)
		Max_row[i] = (Month_days[i] + Month_firstday_week[i]) / 7 + !((Month_days[i] + Month_firstday_week[i]) % 7 == 0);
	maxrow = max(max(Max_row[0], Max_row[1]), Max_row[2]);
	//求这个季度中每个月打印的初始位置
	for (int i = 0; i < 3; i++)
		Init_location[i] = Month_firstday_week[i];
	for (int row = 0; row < maxrow; row++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (!Is_print_over[i])
			{
				for (int k = 0; k < Init_location[i]; k++)
					cout << "    "; 
				for (int j = Saturday_location[i]; j <= Month_days[i]; j++)
				{
					cout << setiosflags(ios::left) << setw(4) << j;
					Init_location[i]++;
					if (j == Month_days[i])
						Is_print_over[i] = 1;
					if (Init_location[i] == 7)
					{
						Saturday_location[i] = j + 1;
						if (i != 2)
							cout << "    ";	
						if (!Is_print_over[i])
							Init_location[i] = 0;	
						break;
					}
				}
			}
			if (Is_print_over[i])
			{
				if (Init_location[i] == 7 && i == 2)
					Init_location[i] = 0;
				for (int k = Init_location[i]; k <= 6; k++)
				{
					cout << "    ";
					Init_location[i]++;
					if (Init_location[i] == 7 && i != 2)
					{
						cout << "    ";
						Init_location[i] = 0;
						break;
					}
				}
			}
		}
		cout << endl;
	}
}
int main()
{
	int year;
	int leap;
	//输入年份
	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (year < 1900 || year>2100)
			continue;
		break;
	}
	//判断闰年
	leap = Judgeleap(year);
	cout << year << "年的日历:" << endl << endl;
	int Month_days[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	//每个月第一天的星期
	int Month_firstday_week[12] = { 0 };
	for (int i = 0; i < 12; i++)
		Month_firstday_week[i] = zeller(year, i + 1, 1);
	//开始打印
	for (int quarter = 1; quarter <= 4; quarter++)
	{
		Print_month(quarter);
		Print_day(&Month_firstday_week[(quarter-1) * 3], &Month_days[(quarter-1) * 3]);
		cout << endl;
	}
	cout << endl;
	return 0;
}