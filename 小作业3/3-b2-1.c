/*2253744 �־��� ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("������һ��[1..30000]�������:\n");
	int a;
	scanf("%d", &a);
	printf("%s : %d\n", "��λ", a / 10000 % 10);
	printf("%s : %d\n", "ǧλ", a / 1000 % 10);
	printf("%s : %d\n", "��λ", a / 100 % 10);
	printf("%s : %d\n", "ʮλ", a / 10 % 10);
	printf("%s : %d\n", "��λ", a / 1 % 10);
	return 0;
}