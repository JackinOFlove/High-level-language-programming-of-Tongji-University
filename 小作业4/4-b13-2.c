/*2253744 �־��� ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 1;
/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n > 1)
	{
		hanoi(n - 1, src, dst, tmp);
		printf("%5d:%3d# %c-->%c\n", num++, n, src, dst);
		hanoi(n - 1, tmp, src, dst);
	}
	if (n == 1)
	{
		printf("%5d:%3d# %c-->%c\n", num++, n, src, dst);
	}		
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
	int n, ch;
	char src, tmp, dst;
	tmp = ' ';
	while (1)
	{
		printf("�����뺺ŵ���Ĳ���(1-16)\n");
		int ret = scanf("%d", &n);
		while ((ch = getchar()) != EOF && ch != '\n');
		if (ret == 1 && n > 0 && n <= 16)
		{
			break;
		}		
	}
	while (1)
	{
		printf("��������ʼ��(A-C)\n");
		int ret = scanf("%c", &src);
		while ((ch = getchar()) != EOF && ch != '\n');
		if (ret == 1 && ((src >= 'A' && src <= 'C') || src >= 'a' && src <= 'c'))
		{
			if (src >= 'a' && src <= 'c')
			{
				src -= 32;
			}	
			break;
		}
	}
	while (1)
	{
		printf("������Ŀ����(A-C)\n");
		int ret = scanf("%c", &dst);
		while ((ch = getchar()) != EOF && ch != '\n');
		if (ret == 1 && ((dst >= 'A' && dst <= 'C') || dst >= 'a' && dst <= 'c'))
		{
			if (dst >= 'a' && dst <= 'c')
			{
				dst -= 32;
			}
			if (dst == src)
			{
				printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
				continue;
			}
			break;
		}
	}
	if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
	{
		tmp = 'C';
	}
	else if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
	{
		tmp = 'B';
	}
	else if ((src == 'B' && dst == 'C') || (src == 'C' && dst == 'B'))
	{
		tmp = 'A';
	}
	printf("�ƶ�����Ϊ:\n");
	hanoi(n, src, tmp, dst);
	return 0;
}