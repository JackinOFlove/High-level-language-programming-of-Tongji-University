/*2253744 �־��� ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
int daxie(int num, int flag_of_zero, int i)
{
	int ret = 0;
	if (num)
	{
		result[i] = chnstr[num * 2];
		result[i + 1] = chnstr[num * 2 + 1];
		ret = 2;
	}
	else
	{
		if (flag_of_zero)
		{
			result[i] = chnstr[num * 2];
			result[i + 1] = chnstr[num * 2 + 1];
			ret = 2;
		}
	}
	return ret;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
	double a;
	char Add[] = "����Ǫ��ʰԲ���Ƿ�";
	/*�������ּ�������*/
	while (1)
	{
		printf("������[0-100��)֮�������:\n");
		int ret = scanf("%lf", &a);
		while (getchar() != '\n');
		{
			if (!ret)
			{
				continue;
			}
			if (a < 0 || a >= 10000000000)
			{
				continue;
			}
			break;
		}
	}
	int a1, a2, a3, a4;
	a1 = (int)(a / 100000000);//ʮ�ڡ���
	a2 = (int)(a / 10000 - a1 * 10000);//ǧ��~��
	a3 = (int)((a / 10000 - a1 * 10000 - a2) * 10000 + 0.001);//ǧ~��
	a4 = (int)((a - floor(a)) * 100 + 0.001);//�ǡ���
	printf("��д�����:\n");
	int n1, n2, n3, n4;
	int flag, index, ret, yuanzheng;
	flag = index = yuanzheng = 0;
	//ʮ��λ����λ
	if (a1 != 0)
	{
		n1 = a1 / 10;
		n2 = a1 % 10;
		ret = daxie(n1, 0, index);
		index += ret;
		if (n1 != 0)
		{
			//ʰ
			result[index] = Add[4 * 2];
			result[index + 1] = Add[4 * 2 + 1];
			index += 2;
		}
		ret = daxie(n2, 0, index);
		index += ret;
		//��
		result[index] = Add[0];
		result[index + 1] = Add[1];
		index += 2;
		if (!a2 && !a3 && !a4)
		{
			//Բ
			result[index] = Add[5 * 2];
			result[index + 1] = Add[5 * 2 + 1];
			index += 2;
			//��
			result[index] = Add[6 * 2];
			result[index + 1] = Add[6 * 2 + 1];
			index += 2;
			yuanzheng = 1;
		}
	}
	//ǧ��~��
	if (a2)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		if (!n1 && (n2 || n3 || n4) && a1)
		{
			flag = 1;
			ret = daxie(n1, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n1, 0, index);
			index += ret;
		}
		if (n1)
		{
			//Ǫ
			result[index] = Add[2 * 2];
			result[index + 1] = Add[2 * 2 + 1];
			index += 2;
		}
		if (!n2 && (n3 || n4) && (a1 || n1) && !flag)
		{
			ret = daxie(n2, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n2, 0, index);
			index += ret;
		}
		if (n2)
		{
			//��
			result[index] = Add[3 * 2];
			result[index + 1] = Add[3 * 2 + 1];
			index += 2;
		}
		if (!n3 && (!flag && (a1 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			ret = daxie(n3, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n3, 0, index);
			index += ret;
		}
		if (n3)
		{
			//ʰ
			result[index] = Add[4 * 2];
			result[index + 1] = Add[4 * 2 + 1];
			index += 2;
		}
		ret = daxie(n4, 0, index);
		index += ret;
		//��
		result[index] = Add[1 * 2];
		result[index + 1] = Add[1 * 2 + 1];
		index += 2;
		flag = 0;
		if (!a3 && !a4)
		{
			//Բ
			result[index] = Add[5 * 2];
			result[index + 1] = Add[5 * 2 + 1];
			index += 2;
			//��
			result[index] = Add[6 * 2];
			result[index + 1] = Add[6 * 2 + 1];
			index += 2;
			yuanzheng = 1;
		}
	}
	//ǧ~��
	if (a3)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		if (!n1 && (n2 || n3 || n4) && (a1 || a2))
		{
			flag = 1;
			ret = daxie(n1, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n1, 0, index);
			index += ret;
		}
		if (n1)
		{
			//Ǫ
			result[index] = Add[2 * 2];
			result[index + 1] = Add[2 * 2 + 1];
			index += 2;
		}
		if (!n2 && (n3 || n4) && (a1 || a2 || n1) && !flag)
		{
			flag = 1;
			ret = daxie(n2, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n2, 0, index);
			index += ret;
		}
		if (n2)
		{
			//��
			result[index] = Add[3 * 2];
			result[index + 1] = Add[3 * 2 + 1];
			index += 2;
		}
		if (!n3 && (!flag && (a1 || a2 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			ret = daxie(n3, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n3, 0, index);
			index += ret;
		}
		if (n3)
		{
			//ʰ
			result[index] = Add[4 * 2];
			result[index + 1] = Add[4 * 2 + 1];
			index += 2;
		}
		ret = daxie(n4, 0, index);
		index += ret;
		flag = 0;
	}
	if (a1 || a2 || a3)
	{
		if (!yuanzheng)
		{
			//Բ
			result[index] = Add[5 * 2];
			result[index + 1] = Add[5 * 2 + 1];
			index += 2;
			if (!a4)
			{
				//��
				result[index] = Add[6 * 2];
				result[index + 1] = Add[6 * 2 + 1];
				index += 2;
			}
		}
	}
	//�ǡ���
	if (a4)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		if (!n1 && n2 && (a1 || a2 || a3))
		{
			ret = daxie(n1, 1, index);
			index += ret;
			flag = 1;
		}
		else
		{
			ret = daxie(n1, 0, index);
			index += ret;
		}
		if (n1)
		{
			//��
			result[index] = Add[7 * 2];
			result[index + 1] = Add[7 * 2 + 1];
			index += 2;
		}
		if (n2)
		{
			ret = daxie(n2, 0, index);
			index += ret;
			//��
			result[index] = Add[8 * 2];
			result[index + 1] = Add[8 * 2 + 1];
			index += 2;
		}
		else
		{
			//��
			result[index] = Add[6 * 2];
			result[index + 1] = Add[6 * 2 + 1];
			index += 2;
			index += 2;
		}
	}
	if (a == 0)
	{
		result[0] = chnstr[0];
		result[1] = chnstr[1];
		result[2] = Add[5 * 2];
		result[3] = Add[5 * 2 + 1];
		result[4] = Add[6 * 2];
		result[5] = Add[6 * 2 + 1];
	}
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}
