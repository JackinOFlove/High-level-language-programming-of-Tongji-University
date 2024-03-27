/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int year, month, day;
	char good;
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		scanf("%d %d", &year, &month);
		while ((good = getchar()) != EOF && good != '\n');
		if (year < 2000 || year>2030 || month < 1 || month>12)
		{
			printf("输入非法，请重新输入\n");
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
			printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
			scanf("%d", &week);
			while ((good = getchar()) != EOF && good != '\n')
			{
				printf("输入非法，请重新输入\n");
			}
			if (week < 0 || week>6)
			{
				printf("输入非法，请重新输入\n");
				continue;
			}
			printf("\n");
			printf("%d年%d月的月历为:\n", year, month);
			printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
			for (int i = 0; i < week; i++)
			{
				printf("        ");
			}
			int count = week;
			for (int j = 1; j <= day; j++)
			{
				printf("  %2d    ", j);
				count++;
				if (count == 7)
				{
					printf("\n");
					count = 0;
				}
			}
			break;
		}
		printf("\n");
		break;
	}
	return 0;
}