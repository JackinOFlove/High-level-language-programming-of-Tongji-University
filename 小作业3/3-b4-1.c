/*2253744 �־��� ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define Pi 3.14159
int main()
{
	printf("�����������ε����߼���н�(�Ƕ�)\n");
	int a,b,angel;
	scanf("%d %d %d", &a,&b,&angel);
	double area = 0.5 * sin(angel * Pi / 180) * a * b;
	area = (float)area;
	printf("�����ε����Ϊ : %.3f\n", area);
	return 0;
}

