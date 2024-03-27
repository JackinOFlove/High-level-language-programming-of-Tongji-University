/*2253744 林觉凯 软件*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	printf("请输入一个[0..100亿]之间的数字:\n");
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
	printf("%-10s%s%d\n", "十亿位"," : ",(int)(a / 1000000000));
	printf("%-10s%s%d\n", "亿位", " : ", i / 100000000 % 10);
	printf("%-10s%s%d\n", "千万位", " : ",i / 10000000 % 10);
	printf("%-10s%s%d\n", "百万位", " : ", i/ 1000000 % 10);
	printf("%-10s%s%d\n", "十万位", " : ", i / 100000 % 10);
	printf("%-10s%s%d\n", "万位", " : ", i / 10000 % 10);
	printf("%-10s%s%d\n", "千位", " : ", i / 1000 % 10);
	printf("%-10s%s%d\n", "百位", " : ",i / 100 % 10);
	printf("%-10s%s%d\n", "十位", " : ",i / 10 % 10);
	printf("%-10s%s%d\n", "圆", " : ", i / 1 % 10);
	printf("%-10s%s%d\n", "角", " : ", f1);
	printf("%-10s%s%d\n", "分", " : ", f2);
	return 0;
}