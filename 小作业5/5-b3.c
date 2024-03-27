/*2253744 �־��� �� */
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
	printf("�������꣬�£���\n");
	scanf("%d %d %d", &year, &month, &day);
	if (month < 1 || month > 12)
	{
		printf("�������-�·ݲ���ȷ\n");
		return 0;
	}
	leap = Judge_leap(year);
	number = Cal_days(year, month, day, leap);
	if (number == 0)
	{
		printf("�������-�����µĹ�ϵ�Ƿ�\n");
		return 0;
	}
	printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, number);
	return 0;
}