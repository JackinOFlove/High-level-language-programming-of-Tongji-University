/*2253744 �־��� ��*/
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	p = str;
	pa = a;
	pnum = a;
	for (; *p != '\0'; p++)
	{
		if (*p >= '0' && *p <= '9')
			is_num = true;
		else
			is_num = false;
		if (is_num)
		{
			*pa = *pa * 10 + *p - '0';
			if (!(*(p + 1) >= '0' && *(p + 1) <= '9'))
				pa++;
			if (pa == a + 10)
				break;
		}
	}
	cout << "����" << pa - a << "������" << endl;
	for (; pnum < a + 10; pnum++)
	{
		if (*pnum != '\0')
			cout << *pnum << ' ';
	}
	cout << endl;
	return 0;
}