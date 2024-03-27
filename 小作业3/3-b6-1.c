/*2253744 ÁÖ¾õ¿­ Èí¹¤*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n");
	double a, n;
	scanf("%lf", &a);
	printf("´óĞ´½á¹ûÊÇ:\n");
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
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		}
		switch (n2)
		{
		case 0:
			printf("ÒÚ");
			break;
		case 1:
			printf("Ò¼ÒÚ");
			break;
		case 2:
			printf("·¡ÒÚ");
			break;
		case 3:
			printf("ÈşÒÚ");
			break;
		case 4:
			printf("ËÁÒÚ");
			break;
		case 5:
			printf("ÎéÒÚ");
			break;
		case 6:
			printf("Â½ÒÚ");
			break;
		case 7:
			printf("ÆâÒÚ");
			break;
		case 8:
			printf("°ÆÒÚ");
			break;
		case 9:
			printf("¾ÁÒÚ");
			break;
		}
		if (a2 == 0 && a3 == 0 && a4 == 0)
		{
			printf("Ô²Õû\n");
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
				printf("Áã");
				flag = 1;
			}
			break;
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈşÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0) && (n3 != 0 || n4 != 0))
			{
				printf("Áã");
				flag = 1;
			}
			break;
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0 || n1 != 0 || n2 != 0) && n4!=0) || (flag && n2 != 0 && n4 != 0))
			{
				printf("Áã");
				flag = 1;
			}
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		}
		switch (n4)
		{
		case 0:
			printf("Íò");
			break;
		case 1:
			printf("Ò¼Íò");
			break;
		case 2:
			printf("·¡Íò");
			break;
		case 3:
			printf("ÈşÍò");
			break;
		case 4:
			printf("ËÁÍò");
			break;
		case 5:
			printf("ÎéÍò");
			break;
		case 6:
			printf("Â½Íò");
			break;
		case 7:
			printf("ÆâÍò");
			break;
		case 8:
			printf("°ÆÍò");
			break;
		case 9:
			printf("¾ÁÍò");
			break;
		}
		flag = 0;
		if (a3 == 0 && a4 == 0)
		{
			printf("Ô²Õû\n");
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
				printf("Áã");
				flag = 1;
			}
			break;
		case 1:
			printf("Ò¼Çª");
			break;
		case 2:
			printf("·¡Çª");
			break;
		case 3:
			printf("ÈşÇª");
			break;
		case 4:
			printf("ËÁÇª");
			break;
		case 5:
			printf("ÎéÇª");
			break;
		case 6:
			printf("Â½Çª");
			break;
		case 7:
			printf("ÆâÇª");
			break;
		case 8:
			printf("°ÆÇª");
			break;
		case 9:
			printf("¾ÁÇª");
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0 || a2 != 0) && (n3 != 0 || n4 != 0))
			{
				printf("Áã");
				flag = 1;
			}
			break;
		case 1:
			printf("Ò¼°Û");
			break;
		case 2:
			printf("·¡°Û");
			break;
		case 3:
			printf("Èş°Û");
			break;
		case 4:
			printf("ËÁ°Û");
			break;
		case 5:
			printf("Îé°Û");
			break;
		case 6:
			printf("Â½°Û");
			break;
		case 7:
			printf("Æâ°Û");
			break;
		case 8:
			printf("°Æ°Û");
			break;
		case 9:
			printf("¾Á°Û");
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0 || a2 != 0 || n1 != 0 || n2 != 0) && n4) || (flag && n2 != 0 && n4 != 0))
			{
				printf("Áã");
				flag = 1;
			}
			break;
		case 1:
			printf("Ò¼Ê°");
			break;
		case 2:
			printf("·¡Ê°");
			break;
		case 3:
			printf("ÈşÊ°");
			break;
		case 4:
			printf("ËÁÊ°");
			break;
		case 5:
			printf("ÎéÊ°");
			break;
		case 6:
			printf("Â½Ê°");
			break;
		case 7:
			printf("ÆâÊ°");
			break;
		case 8:
			printf("°ÆÊ°");
			break;
		case 9:
			printf("¾ÁÊ°");
			break;
		}
		switch (n4)
		{
		case 0:
			break;
		case 1:
			printf("Ò¼");
			break;
		case 2:
			printf("·¡");
			break;
		case 3:
			printf("Èş");
			break;
		case 4:
			printf("ËÁ");
			break;
		case 5:
			printf("Îé");
			break;
		case 6:
			printf("Â½");
			break;
		case 7:
			printf("Æâ");
			break;
		case 8:
			printf("°Æ");
			break;
		case 9:
			printf("¾Á");
			break;
		}
		flag = 0;
	}
	if (a1 != 0 || a2 != 0 || a3 != 0)
	{
		printf("Ô²");
		if (a4 == 0)
		{
			printf("Õû\n");
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
				printf("Áã");
			break;
		case 1:
			printf("Ò¼½Ç");
			break;
		case 2:
			printf("·¡½Ç");
			break;
		case 3:
			printf("Èş½Ç");
			break;
		case 4:
			printf("ËÁ½Ç");
			break;
		case 5:
			printf("Îé½Ç");
			break;
		case 6:
			printf("Â½½Ç");
			break;
		case 7:
			printf("Æâ½Ç");
			break;
		case 8:
			printf("°Æ½Ç");
			break;
		case 9:
			printf("¾Á½Ç");
			break;
		}
		switch (n2)
		{
		case 0:
			printf("Õû\n");
			break;
		case 1:
			printf("Ò¼·Ö");
			break;
		case 2:
			printf("·¡·Ö");
			break;
		case 3:
			printf("Èş·Ö");
			break;
		case 4:
			printf("ËÁ·Ö");
			break;
		case 5:
			printf("Îé·Ö");
			break;
		case 6:
			printf("Â½·Ö");
			break;
		case 7:
			printf("Æâ·Ö");
			break;
		case 8:
			printf("°Æ·Ö");
			break;
		case 9:
			printf("¾Á·Ö");
			break;
		}
	}
	if (a == 0)
		printf("ÁãÔ²Õû");
	return 0;
}