/*2253744 林觉凯 软件*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define Pi 3.14159
int main()
{
	printf("请输入三角形的两边及其夹角(角度)\n");
	int a,b,angel;
	scanf("%d %d %d", &a,&b,&angel);
	double area = 0.5 * sin(angel * Pi / 180) * a * b;
	area = (float)area;
	printf("三角形的面积为 : %.3f\n", area);
	return 0;
}

