/*2253744 �־��� ��*/
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
	if (num == 0 && flag_of_zero)
	{
		result = result + chnstr[0] + chnstr[1];
	}
	if (num != 0)
	{
		result = result + chnstr[num * 2] + chnstr[num * 2 + 1];
	}
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
		cout << "������[0-100��)֮�������:" << endl;
		cin >> a;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (a < 0 || a >= 10000000000)
		{
			continue;
		}	
		break;
	}
	//�ֽ�����
	int a1, a2, a3, a4;
	a1 = (int)(a / 100000000);//ʮ�ڡ���
	a2 = (int)(a / 10000 - a1 * 10000);//ǧ��~��
	a3 = (int)((a / 10000 - a1 * 10000 - a2) * 10000 + 0.001);//ǧ~��
	a4 = (int)((a - floor(a)) * 100 + 0.001);//�ǡ���
	//�����д����
	printf("��д�����:\n");
	int n1, n2, n3, n4;
	int flag, index, yuanzheng;
	flag = index = yuanzheng = 0;
	//ʮ�ڡ���
	if (a1 != 0)
	{
		n1 = a1 / 10;
		n2 = a1 % 10;
		daxie(n1, 0);
		if (n1 != 0)
		{
			result = result + Add[4 * 2] + Add[4 * 2 + 1];//ʰ
		}	
		daxie(n2, 0);
		result = result + Add[0] + Add[1];//��
		if (!a2 && !a3 && !a4)
		{
			result = result + Add[5 * 2] + Add[5 * 2 + 1];//Բ
			result = result + Add[6 * 2] + Add[6 * 2 + 1];//��
			yuanzheng = 1;
		}
	}
	//ǧ��~��
	if (a2 != 0)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		if (!n1 && (n2 || n3 || n4) && a1)
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1)
		{
			result = result + Add[2 * 2] + Add[2 * 2 + 1];//Ǫ
		}	
		if (!n2 && (n3 || n4) && (a1 || n1) && !flag)
		{
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}
		if (n2)
		{
			result = result + Add[3 * 2] + Add[3 * 2 + 1];//��
		}
		if (!n3 && (!flag && (a1 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			daxie(n3, 1);
		}
		else 
		{
			daxie(n3, 0);
		}	
		if (n3)
		{
			result = result + Add[4 * 2] + Add[4 * 2 + 1];//ʰ
		}		
		daxie(n4, 0);
		result = result + Add[1 * 2] + Add[1 * 2 + 1];//��
		flag = 0;
		if (!a3 && !a4)
		{
			result = result + Add[5 * 2] + Add[5 * 2 + 1];//Բ
			result = result + Add[6 * 2] + Add[6 * 2 + 1];//��
			yuanzheng = 1;
		}
	}
	//ǧ~��
	if (a3 != 0)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		if (!n1 && (n2 || n3 || n4) && (a1 || a2))
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1)
			result = result + Add[2 * 2] + Add[2 * 2 + 1];//Ǫ
		if (!n2 && (n3 || n4) && (a1 || a2 || n1) && !flag)
		{
			flag = 1;
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}			
		if (n2)
		{
			result = result + Add[3 * 2] + Add[3 * 2 + 1];//��
		}
		if (!n3 && (!flag && (a1 || a2 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			daxie(n3, 1);
		}	
		else
		{
			daxie(n3, 0);
		}
		if (n3)
		{
			result = result + Add[4 * 2] + Add[4 * 2 + 1];//ʰ
		}
		daxie(n4, 0);
		flag = 0;
	}
	if (a1 || a2 || a3)
	{
		if (!yuanzheng)
		{
			result = result + Add[5 * 2] + Add[5 * 2 + 1];//Բ
			if (!a4)
			{
				result = result + Add[6 * 2] + Add[6 * 2 + 1];//��
			}	
		}
	}
	//�ǡ���
	if (a4 != 0)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		if (!n1 && n2 && (a1 || a2 || a3))
		{
			daxie(n1, 1);
			flag = 1;
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1)
		{
			result = result + Add[7 * 2] + Add[7 * 2 + 1];//��
		}
		if (n2)
		{
			daxie(n2, 0);
			result = result + Add[8 * 2] + Add[8 * 2 + 1];//��
		}
		else
		{
			result = result + Add[6 * 2] + Add[6 * 2 + 1];//��
		}
	}
	if (a == 0)
	{
		result = result + chnstr[0] + chnstr[1] + Add[5 * 2] + Add[5 * 2 + 1] + Add[6 * 2] + Add[6 * 2 + 1];
	}
	cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}
