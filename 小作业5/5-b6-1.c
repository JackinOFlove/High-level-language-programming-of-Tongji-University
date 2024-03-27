/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 1;
int a_stack[10] = { 0,0,0,0,0,0,0,0,0,0 };
int b_stack[10] = { 0,0,0,0,0,0,0,0,0,0 };
int c_stack[10] = { 0,0,0,0,0,0,0,0,0,0 };
int a_top = 0;
int b_top = 0;
int c_top = 0;
void init(int n, char src)
{
	if (src == 'A')
	{
		while (a_top < n)
			a_stack[a_top++] = n - a_top;
	}
	else if (src == 'B')
	{
		while (b_top < n)
			b_stack[b_top++] = n - b_top;
	}
	else if (src == 'C')
	{
		while (c_top < n)
			c_stack[c_top++] = n - c_top;
	}
}
void print()
{
	printf(" A:");
	for (int i = 0; i < 10; i++)
	{
		if (a_stack[i])
			printf("%2d", a_stack[i]);
		else
			printf("  ");
	}
	printf(" B:");
	for (int i = 0; i < 10; i++)
	{
		if (b_stack[i])
			printf("%2d", b_stack[i]);
		else
			printf("  ");
	}
	printf(" C:");
	for (int i = 0; i < 10; i++)
	{
		if (c_stack[i])
			printf("%2d", c_stack[i]);
		else
			printf("  ");
	}
	printf("\n");
}
void hanoi_stack(char src, char dst)
{
	int element = 0;
	if (src == 'A' && a_top > 0)
	{
		element = a_stack[--a_top];
		a_stack[a_top] = 0;
	}
	else if (src == 'B' && b_top > 0)
	{
		element = b_stack[--b_top];
		b_stack[b_top] = 0;
	}
	else if (src == 'C' && c_top > 0)
	{
		element = c_stack[--c_top];
		c_stack[c_top] = 0;
	}
	if (dst == 'A' && a_top < 10)
		a_stack[a_top++] = element;
	else if (dst == 'B' && b_top < 10)
		b_stack[b_top++] = element;
	else if (dst == 'C' && c_top < 10)
		c_stack[c_top++] = element;
}
void hanoi(int n, char src, char tmp, char dst)
{
	if (n > 1)
	{
		hanoi(n - 1, src, dst, tmp);
		printf("第%4d 步(%2d): %c-->%c", num++, n, src, dst);
		hanoi_stack(src, dst);
		print();
		hanoi(n - 1, tmp, src, dst);
	}
	if (n == 1)
	{
		printf("第%4d 步(%2d): %c-->%c", num++, n, src, dst);
		hanoi_stack(src, dst);
		print();
	}
}
int main()
{
	int n, ch;
	char src, tmp, dst;
	while (1)
	{
		printf("请输入汉诺塔的层数(1-10)\n");
		int ret = scanf("%d", &n);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (ret == 1 && n > 0 && n <= 10)
			break;
	}
	while (1)
	{
		printf("请输入起始柱(A-C)\n");
		int ret = scanf("%c", &src);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (ret == 1 && ((src >= 'A' && src <= 'C') || src >= 'a' && src <= 'c'))
		{
			if (src >= 'a' && src <= 'c')
				src -= 32;
			break;
		}
	}
	while (1)
	{
		printf("请输入目标柱(A-C)\n");
		int ret = scanf("%c", &dst);
		while ((ch = getchar()) != EOF && ch != '\n')
			;
		if (ret == 1 && ((dst >= 'A' && dst <= 'C') || dst >= 'a' && dst <= 'c'))
		{
			if (dst >= 'a' && dst <= 'c')
				dst -= 32;
			if (dst == src)
			{
				printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
				continue;
			}
			break;
		}
	}
	if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
		tmp = 'C';
	else if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
		tmp = 'B';
	else if ((src == 'B' && dst == 'C') || (src == 'C' && dst == 'B'))
		tmp = 'A';
	init(n, src);
	printf("初始:               ");
	print();
	hanoi(n, src, tmp, dst);
	return 0;
}