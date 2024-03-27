/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
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
	char good;
	bool leap;
	while (1)
	{
		printf("请输入年[1900-2100]、月、日：\n");
		int n = scanf("%d %d %d", &y, &m, &d);
		while ((good = getchar()) != EOF && good != '\n');
		if (n != 3)
		{
			printf("输入错误，请重新输入\n");
			continue;
		}
		if (y < 1900 || y>2100)
		{
			printf("年份不正确，请重新输入\n");
			continue;
		}
		if (m < 1 || m > 12)
		{
			printf("月份不正确，请重新输入\n");
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
				printf("日不正确，请重新输入\n");
				continue;
			}
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 0 || d>31)
			{
				printf("日不正确，请重新输入\n");
				continue;
			}
		}
		else
		{
			if (d < 0 || d>30)
			{
				printf("日不正确，请重新输入\n");
				continue;
			}
		}
		w = zeller(y, m, d);
		switch (w)
		{
		case 0:
			printf("星期日\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
		}
		break;
	}
	return 0;
}