/*2253744 林觉凯 软工 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, day;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);
	int days = 0;
	switch (month)
	{
	case 12:
		if (day > 31 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 335 + day;
			else
				days = 334 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 11:
		if (day > 30 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 305 + day;
			else
				days = 304 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 10:
		if (day > 31 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 274 + day;
			else
				days = 273 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 9:
		if (day > 30 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 244 + day;
			else
				days = 243 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 8:
		if (day > 31 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 213 + day;
			else
				days = 212 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 7:
		if (day > 31 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 182 + day;
			else
				days = 181 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 6:
		if (day > 30 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 152 + day;
			else
				days = 151 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 5:
		if (day > 31 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 121 + day;
			else
				days = 120 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 4:
		if (day > 30 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 91 + day;
			else
				days = 90 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 3:
		if (day > 31 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = 60 + day;
			else
				days = 59 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 2:
		if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
		{
			if (day > 29 || day < 1)
			{
				printf("输入错误-日与月的关系非法\n");
				break;
			}
			else
				days = 31 + day;
		}
		else
		{
			if (day > 28 || day < 1)
			{
				printf("输入错误-日与月的关系非法\n");
				break;
			}
			else
				days = 31 + day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	case 1:
		if (day > 31 || day < 1)
		{
			printf("输入错误-日与月的关系非法\n");
			break;
		}
		else
		{
			if ((year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0))
				days = day;
			else
				days = day;
		}
		printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
		break;
	default:
		printf("输入错误-月份不正确\n");
	}
	return 0;
}