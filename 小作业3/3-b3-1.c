/*2253744 �־��� ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	printf("������һ��[0..100��]֮�������:\n");
	double a;
	scanf("%lf", &a);
	int i, f, f1, f2;
	double n;
	f = (int)rint(modf(a, &n) * 100);
	f1 = f / 10;
	f1 = (int)fmin(9.0, (double)f1);
	f2 = f - f1 * 10;
	f2 = (int)fmin(9.0, (double)f2);
	i = (int)fmod(a, 1000000000.0);
	printf("%-10s%s%d\n", "ʮ��λ"," : ",(int)(a / 1000000000));
	printf("%-10s%s%d\n", "��λ", " : ", i / 100000000 % 10);
	printf("%-10s%s%d\n", "ǧ��λ", " : ",i / 10000000 % 10);
	printf("%-10s%s%d\n", "����λ", " : ", i/ 1000000 % 10);
	printf("%-10s%s%d\n", "ʮ��λ", " : ", i / 100000 % 10);
	printf("%-10s%s%d\n", "��λ", " : ", i / 10000 % 10);
	printf("%-10s%s%d\n", "ǧλ", " : ", i / 1000 % 10);
	printf("%-10s%s%d\n", "��λ", " : ",i / 100 % 10);
	printf("%-10s%s%d\n", "ʮλ", " : ",i / 10 % 10);
	printf("%-10s%s%d\n", "Բ", " : ", i / 1 % 10);
	printf("%-10s%s%d\n", "��", " : ", f1);
	printf("%-10s%s%d\n", "��", " : ", f2);
	return 0;
}