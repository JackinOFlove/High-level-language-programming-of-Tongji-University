/*2253744 �־��� �� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (array[j] > array[k])
				k = j;
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
}
int main()
{
	int number[1001] = { 0 };
	int i = 0;
	printf("������ɼ������1000������������������\n");
	for (; i < 1000; i++)
	{
		int tempnumber;
		scanf("%d",&tempnumber);
		number[i] = tempnumber;
		if (tempnumber < 0)
			break;
	}
	i--;
	if (i < 0)
	{
		printf("����Ч����\n");
		return 0;
	}
	else
		printf("���������Ϊ:\n");
	int flag = 0;
	for (int j = 0; j < i + 1; j++)
	{
		printf("%d ",number[j]);
		flag++;
		if (flag == 10)
		{
			printf("\n");
			flag = 0;
		}
	}
	printf("\n");
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	sort(number, i + 1);
	for (int j = 0; j < i + 1;)
	{
		int value = number[j];
		int count = 0;
		for (int k = j; k < i + 1; k++)
			if (number[k] == value)
				count++;
			else
				break;
		printf("%d %d\n", value, count);
		j += count;
	}
	return 0;
}