/*2253744 林觉凯 软件*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	printf("请输入一个[1..30000]间的整数:\n");
	int a;
	scanf("%d", &a);
	printf("%s : %d\n", "万位", a / 10000 % 10);
	printf("%s : %d\n", "千位", a / 1000 % 10);
	printf("%s : %d\n", "百位", a / 100 % 10);
	printf("%s : %d\n", "十位", a / 10 % 10);
	printf("%s : %d\n", "个位", a / 1 % 10);
	return 0;
}