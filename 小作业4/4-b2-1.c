/*2253744 �־��� ��*/
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
		printf("��������[1900-2100]���¡��գ�\n");
		int n = scanf("%d %d %d", &y, &m, &d);
		while ((good = getchar()) != EOF && good != '\n');
		if (n != 3)
		{
			printf("�����������������\n");
			continue;
		}
		if (y < 1900 || y>2100)
		{
			printf("��ݲ���ȷ������������\n");
			continue;
		}
		if (m < 1 || m > 12)
		{
			printf("�·ݲ���ȷ������������\n");
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
				printf("�ղ���ȷ������������\n");
				continue;
			}
		}
		else if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if (d < 0 || d>31)
			{
				printf("�ղ���ȷ������������\n");
				continue;
			}
		}
		else
		{
			if (d < 0 || d>30)
			{
				printf("�ղ���ȷ������������\n");
				continue;
			}
		}
		w = zeller(y, m, d);
		switch (w)
		{
		case 0:
			printf("������\n");
			break;
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
		}
		break;
	}
	return 0;
}