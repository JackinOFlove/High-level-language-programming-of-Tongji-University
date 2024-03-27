/*2253744 林觉凯 软工 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
bool Judge_leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}
int Cal_days(int year, int month, int day, bool leap)
{
	int month_days[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	int number = 0;
	if (day <= 0 || day > month_days[month - 1])
		return 0;
	for (int i = 0; i < month - 1; i++)
		number += month_days[i];
	number += day;
	return number;
}
int main()
{
	bool leap;
	int year, month, day, number;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);
	if (month < 1 || month > 12)
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}
	leap = Judge_leap(year);
	number = Cal_days(year, month, day, leap);
	if (number == 0)
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
	printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, number);
	return 0;
}