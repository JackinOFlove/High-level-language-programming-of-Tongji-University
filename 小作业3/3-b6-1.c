/*2253744 �־��� ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	printf("������[0-100��)֮�������:\n");
	double a, n;
	scanf("%lf", &a);
	printf("��д�����:\n");
	int a1, a2, a3, a4;
	a1 = (int)(a / 100000000);
	a2 = (int)(a / 10000 - a1 * 10000);
	a3 = (int)((a / 10000 - a1 * 10000 - a2) * 10000+0.001);
	a4 = (int)rint(modf(a, &n) * 100)+0.001;
	int n1, n2, n3, n4;
	int flag = 0;
	if (a1 != 0)
	{
		n1 = a1 / 10;
		n2 = a1 % 10;
		switch (n1)
		{
		case 0:
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		}
		switch (n2)
		{
		case 0:
			printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
		}
		if (a2 == 0 && a3 == 0 && a4 == 0)
		{
			printf("Բ��\n");
			return 0;
		}
	}
	if (a2 != 0)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		switch (n1)
		{
		case 0:
			if ((n2 != 0 || n3 != 0 || n4 != 0) && a1 != 0)
			{
				printf("��");
				flag = 1;
			}
			break;
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0) && (n3 != 0 || n4 != 0))
			{
				printf("��");
				flag = 1;
			}
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0 || n1 != 0 || n2 != 0) && n4!=0) || (flag && n2 != 0 && n4 != 0))
			{
				printf("��");
				flag = 1;
			}
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		}
		switch (n4)
		{
		case 0:
			printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("����");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("����");
			break;
		case 8:
			printf("����");
			break;
		case 9:
			printf("����");
			break;
		}
		flag = 0;
		if (a3 == 0 && a4 == 0)
		{
			printf("Բ��\n");
			return 0;
		}
	}
	if (a3 != 0)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		switch (n1)
		{
		case 0:
			if ((n2 != 0 || n3 != 0 || n4 != 0) && (a1 != 0 || a2 != 0))
			{
				printf("��");
				flag = 1;
			}
			break;
		case 1:
			printf("ҼǪ");
			break;
		case 2:
			printf("��Ǫ");
			break;
		case 3:
			printf("��Ǫ");
			break;
		case 4:
			printf("��Ǫ");
			break;
		case 5:
			printf("��Ǫ");
			break;
		case 6:
			printf("½Ǫ");
			break;
		case 7:
			printf("��Ǫ");
			break;
		case 8:
			printf("��Ǫ");
			break;
		case 9:
			printf("��Ǫ");
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0 || a2 != 0) && (n3 != 0 || n4 != 0))
			{
				printf("��");
				flag = 1;
			}
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ư�");
			break;
		case 9:
			printf("����");
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0 || a2 != 0 || n1 != 0 || n2 != 0) && n4) || (flag && n2 != 0 && n4 != 0))
			{
				printf("��");
				flag = 1;
			}
			break;
		case 1:
			printf("Ҽʰ");
			break;
		case 2:
			printf("��ʰ");
			break;
		case 3:
			printf("��ʰ");
			break;
		case 4:
			printf("��ʰ");
			break;
		case 5:
			printf("��ʰ");
			break;
		case 6:
			printf("½ʰ");
			break;
		case 7:
			printf("��ʰ");
			break;
		case 8:
			printf("��ʰ");
			break;
		case 9:
			printf("��ʰ");
			break;
		}
		switch (n4)
		{
		case 0:
			break;
		case 1:
			printf("Ҽ");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("½");
			break;
		case 7:
			printf("��");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
			break;
		}
		flag = 0;
	}
	if (a1 != 0 || a2 != 0 || a3 != 0)
	{
		printf("Բ");
		if (a4 == 0)
		{
			printf("��\n");
			return 0;
		}
	}
	if (a4 != 0)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		switch (n1)
		{
		case 0:
			if (n2 != 0 && (a1 != 0 || a2 != 0 || a3 != 0))
				printf("��");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�ƽ�");
			break;
		case 9:
			printf("����");
			break;
		}
		switch (n2)
		{
		case 0:
			printf("��\n");
			break;
		case 1:
			printf("Ҽ��");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("����");
			break;
		case 4:
			printf("����");
			break;
		case 5:
			printf("���");
			break;
		case 6:
			printf("½��");
			break;
		case 7:
			printf("���");
			break;
		case 8:
			printf("�Ʒ�");
			break;
		case 9:
			printf("����");
			break;
		}
	}
	if (a == 0)
		printf("��Բ��");
	return 0;
}