/*2253744 �־��� �� */
#include <iostream>
#include <cmath>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
	case 0:
		if (flag_of_zero)	//�˱��ʲô��˼������˼��
			cout << "��";
		break;
	case 1:
		cout << "Ҽ";
		break;
	case 2:
		cout << "��";
		break;
	case 3:
		cout << "��";
		break;
	case 4:
		cout << "��";
		break;
	case 5:
		cout << "��";
		break;
	case 6:
		cout << "½";
		break;
	case 7:
		cout << "��";
		break;
	case 8:
		cout << "��";
		break;
	case 9:
		cout << "��";
		break;
	default:
		cout << "error";
		break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	cout << "������[0-100��)֮�������:" << endl;
	double a;
	cin >> a;
	int a1, a2, a3, a4;
	a1 = (int)(a / 100000000);//ʮ�ڡ���λ
	a2 = (int)(a / 10000 - a1 * 10000);//ǧ��~��λ
	a3 = (int)((a / 10000 - a1 * 10000 - a2) * 10000 + 0.001);//ǧ~��λ
	a4 = (int)((a - floor(a)) * 100 + 0.001);//�ǡ���λ
	int n1, n2, n3, n4;
	int flag = 0;
	cout << "��д�����:" << endl;
	if (a1 != 0)
	{
		n1 = a1 / 10;
		n2 = a1 % 10;
		daxie(n1, 0);
		if (n1 != 0)
		{
			cout << "ʰ";
		}
		daxie(n2, 0);
		cout << "��";
		if (a2 == 0 && a3 == 0 && a4 == 0)
		{
			cout << "Բ��" << endl;
			return 0;
		}
	}
	if (a2 != 0)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		if (n1==0 && (n2!=0 || n3!=0 || n4!=0) && a1!=0)
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1 != 0)
		{
			cout << "Ǫ";
		}
		if (n2 == 0 && (n3 != 0 || n4 != 0) && (a1 != 0 || n1 != 0) && flag == 0)
		{
			flag = 1;
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}
		if (n2 != 0)
		{
			cout << "��";
		}
		if (n3 == 0 && (flag == 0 && (a1 != 0 || n1 != 0 || n2 != 0) && n4 != 0) || (flag != 0 && n2 != 0 && n4 != 0))
		{
			flag = 1;
			daxie(n3, 1);
		}
		else
		{
			daxie(n3, 0);
		}
		if(n3 != 0)
		{
			cout << "ʰ";
		}
		daxie(n4, 0);
		cout << "��";
		flag = 0;
		if (a3==0 && a4==0)
		{
			cout << "Բ��" << endl;
			return 0;
		}
	}
	if (a3 != 0)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		if (n1==0 && (n2!=0 || n3!=0 || n4!=0) && (a1!=0 || a2!=0))
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1 != 0)
		{
			cout << "Ǫ";
		}
		if (n2==0 && (n3!=0 || n4!=0) && (a1!=0 || a2!=0 || n1!=0) && flag==0)
		{
			flag = 1;
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}
		if(n2 != 0)
		{
			cout << "��";
		}
		if (n3 == 0 && (flag == 0 && (a1 != 0 || a2 != 0 || n1 != 0 || n2 != 0) && n4 != 0) || (flag != 0 && n2 != 0 && n4 != 0))
		{
			daxie(n3, 1);
		}
		else
		{
			daxie(n3, 0);
		}
		if (n3 != 0)
		{
			cout << "ʰ";
		}
		daxie(n4, 0);
		flag = 0;
	}
	if (a1!=0 || a2!=0 || a3!=0)
	{
		cout << "Բ";
		if (a4==0)
		{
			cout << "��" << endl;
			return 0;
		}
	}
	if (a4!=0)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		if (n1==0 && n2!=0 && (a1!=0 || a2!=0 || a3!=0))
		{
			daxie(n1, 1);
			flag = 1;
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1 != 0)
		{
			cout << "��";
		}
		if (n2!=0)
		{
			daxie(n2, 0);
			cout << "��" << endl;
		}
		else
		{
			cout << "��" << endl;
		}	
	}
	if (a == 0)
	{
		cout << "��Բ��" << endl;
	}
	/* ������� */
	return 0;
}