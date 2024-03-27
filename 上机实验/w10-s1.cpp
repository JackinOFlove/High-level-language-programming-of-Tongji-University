/*2253744 �־��� ��*/
#include <iostream>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3�������������������
   4������������������κ���ʽ��ѭ��
   ---------------------------------------------------------------------
*/
/***************************************************************************
  �������ƣ�
  ��    �ܣ��ݹ鷽ʽ���ʮ���Ƶ��������Ƶ�ת������ӡ
  ���������int num ��ʮ������
			int base��Ҫת���Ľ���
  �� �� ֵ��
  ˵    ����1�����������βΡ��������;���׼��
			2������������κ���ʽ��ѭ��
			3��������ʹ��cmath�еĺ���
			4��������ʹ��64λ����
***************************************************************************/
void dec_to_base_n(int num, int base)
{
	if (num >= 0)
	{
		if (num >= base)
		{
			int number = num / base;
			dec_to_base_n(number, base);
		}
		int After_divide = num % base;
		if (After_divide < 10)
		{
			cout << After_divide;
		}
		else
		{
			cout << (char)('A' + After_divide - 10);
		}
	}
	if (num < 0) 
	{
		unsigned int temp = (unsigned int)num;
		if (temp >= base) 
		{
			int number = temp / base;
			dec_to_base_n((int)(number), base);
		}
		int After_divide = temp % base;
		if (After_divide < 10)
		{
			cout << After_divide;
		}
		else 
		{
			cout << (char)('A' + After_divide - 10);
		}
	}
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	int num, base;
	cout << "������ʮ��������(int��)��Ҫת���Ľ���[2..16]" << endl;
	cin >> num >> base;		//�������������numΪint�ͷ�Χ�κ�ֵ���ɣ�baseΪ2~16��������10����

	if (base == 10) //����Ϊ10ֱ���˳�
		return -1;

	/* ��ɽ���ת������ӡ */
	dec_to_base_n(num, base);
	
	cout << endl;

	return 0;
}