/*2253744 �־��� ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Pi 3.14159
int main()
{
	printf("������뾶�͸߶�\n");
	double r, h;
	scanf("%lf%lf", &r, &h);
	printf("%-11s: %.2lf\n", "Բ�ܳ�", Pi * 2 * r);
	printf("%-11s: %.2lf\n", "Բ���", Pi * r * r);
	printf("%-11s: %.2lf\n", "Բ������", Pi * 4 * r * r);
	printf("%-11s: %.2lf\n", "Բ�����", Pi * 4 * r * r * r / 3);
	printf("%-11s: %.2lf\n", "Բ�����", Pi * r * r * h);
	return 0;
}