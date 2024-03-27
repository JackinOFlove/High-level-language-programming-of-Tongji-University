/*2253744 林觉凯 软件*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define Pi 3.14159
int main()
{
	printf("请输入半径和高度\n");
	double r, h;
	scanf("%lf%lf", &r, &h);
	printf("%-11s: %.2lf\n", "圆周长", Pi * 2 * r);
	printf("%-11s: %.2lf\n", "圆面积", Pi * r * r);
	printf("%-11s: %.2lf\n", "圆球表面积", Pi * 4 * r * r);
	printf("%-11s: %.2lf\n", "圆球体积", Pi * 4 * r * r * r / 3);
	printf("%-11s: %.2lf\n", "圆柱体积", Pi * r * r * h);
	return 0;
}