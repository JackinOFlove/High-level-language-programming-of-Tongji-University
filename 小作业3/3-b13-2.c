/*2253744 �־��� ��*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int year, month, day;
	char good;
	while (1)
	{
		printf("���������(2000-2030)���·�(1-12) : ");
		scanf("%d %d", &year, &month);
		while ((good = getchar()) != EOF && good != '\n');
		if (year < 2000 || year>2030 || month < 1 || month>12)
		{
			printf("����Ƿ�������������\n");
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
			printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
			scanf("%d", &week);
			while ((good = getchar()) != EOF && good != '\n')
			{
				printf("����Ƿ�������������\n");
			}
			if (week < 0 || week>6)
			{
				printf("����Ƿ�������������\n");
				continue;
			}
			printf("\n");
			printf("%d��%d�µ�����Ϊ:\n", year, month);
			printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
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