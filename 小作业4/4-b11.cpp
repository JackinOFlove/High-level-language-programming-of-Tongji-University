/*2253744 �־��� ��*/
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
   ----------------------------------------------------------------------------------- */
char print_denghao(char end_ch)
{
	char denghao = '=';
	int number = end_ch - 'A';
	if (number > 0)
		cout << print_denghao(end_ch - 1) << "=";
	return denghao;
}
void print_kongge(int number)
{
	if (number > 0)
	{
		cout << " ";
		print_kongge(number - 1);
	}
}
void print_fronthalf(char end_ch)
{
	if (end_ch >= 'A')
	{
		print_fronthalf(end_ch - 1);
		cout << end_ch;
	}
}
void print_backhalf(char end_ch)
{
	if (end_ch >= 'A')
	{
		cout << end_ch;
		print_backhalf(end_ch - 1);
	}
}
   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/
void print_tower(char end_ch,int order,int number)
{
	if (order == 1)
	{
		if (end_ch - 'A' > 0)
			print_tower(end_ch - 1, order, number + 1);
		print_kongge(number);
		print_fronthalf(end_ch);
		print_backhalf(end_ch - 1);
		cout << endl;
	}
	else
	{
		print_kongge(number);
		print_fronthalf(end_ch);
		print_backhalf(end_ch - 1);
		cout << endl;
		if (end_ch - 'A' > 0)
			print_tower(end_ch - 1, order, number + 1);
	}
	/* �����趨�����һ����̬�ֲ�������Ҳ���Բ����壩 */

	/* ����ʵ�֣������в������κ���ʽ��ѭ����������������������� */
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;
	
	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}

	/* ��������ĸ��(����ΪA) */
	cout << print_denghao(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << print_denghao(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch,1,0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << print_denghao(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(A->" << end_ch << ")" << endl;
	cout << print_denghao(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch,0,0); //�����ӡ A~�����ַ� 
	cout << endl;

	/* ����������Ư�������Σ����ΪA�� */
	cout << print_denghao(end_ch) << endl;/* ����ĸ����������= */
	cout << "����(A->" << end_ch << ")" << endl;
	cout << print_denghao(end_ch) << endl;/* ����ĸ����������= */
	print_tower(end_ch,1,0);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch-1,0,1);   //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}
