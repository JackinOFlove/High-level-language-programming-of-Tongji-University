/*2253744 �־��� �� */
#include <iostream>
using namespace std;
void sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (array[j] > array[k])
			{
				k = j;
			}
		}
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
}
int main()
{
	int number[1001] = { 0 };
	int i = 0;
	cout << "������ɼ������1000������������������" << endl;
	for (; i < 1000; i++)
	{
		int tempnumber;
		cin >> tempnumber;
		number[i] = tempnumber;
		if (tempnumber < 0)
		{
			break;
		}
	}
	i--;
	if (i < 0)
	{
		cout << "����Ч����" << endl;
		return 0;
	}
	else
	{
		cout << "���������Ϊ:" << endl;
	}
	int flag = 0;
	for (int j = 0; j < i + 1; j++)
	{
		cout << number[j] << ' ';
		flag++;
		if (flag == 10)
		{
			cout << endl;
			flag = 0;
		}
	}
	cout << endl;
	cout << "�����������Ķ�Ӧ��ϵΪ:" << endl;
	sort(number, i + 1);
	for (int j = 0; j < i + 1;)
	{
		int value = number[j];
		int count = 0;
		for (int k = j; k < i + 1; k++)
		{
			if (number[k] == value)
			{
				cout << value << ' ' << j + 1 << endl;
				count++;
			}
			else
			{
				break;
			}
		}
		j += count;
	}
	return 0;
}
/*
�������ݣ��ɸ��ƺ�ճ�������д�����
87 86 56 76 87 92 76 0 96 98 0 23 -1

87 86 56 76 87 92 76 96 98 23 55 56 34 23 -1
*/
