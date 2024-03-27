/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num = 1;
/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n > 1)
	{
		hanoi(n - 1, src, dst, tmp);
		printf("%5d:%3d# %c-->%c\n", num++, n, src, dst);
		hanoi(n - 1, tmp, src, dst);
	}
	if (n == 1)
	{
		printf("%5d:%3d# %c-->%c\n", num++, n, src, dst);
	}		
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int n, ch;
	char src, tmp, dst;
	tmp = ' ';
	while (1)
	{
		printf("请输入汉诺塔的层数(1-16)\n");
		int ret = scanf("%d", &n);
		while ((ch = getchar()) != EOF && ch != '\n');
		if (ret == 1 && n > 0 && n <= 16)
		{
			break;
		}		
	}
	while (1)
	{
		printf("请输入起始柱(A-C)\n");
		int ret = scanf("%c", &src);
		while ((ch = getchar()) != EOF && ch != '\n');
		if (ret == 1 && ((src >= 'A' && src <= 'C') || src >= 'a' && src <= 'c'))
		{
			if (src >= 'a' && src <= 'c')
			{
				src -= 32;
			}	
			break;
		}
	}
	while (1)
	{
		printf("请输入目标柱(A-C)\n");
		int ret = scanf("%c", &dst);
		while ((ch = getchar()) != EOF && ch != '\n');
		if (ret == 1 && ((dst >= 'A' && dst <= 'C') || dst >= 'a' && dst <= 'c'))
		{
			if (dst >= 'a' && dst <= 'c')
			{
				dst -= 32;
			}
			if (dst == src)
			{
				printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
				continue;
			}
			break;
		}
	}
	if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
	{
		tmp = 'C';
	}
	else if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
	{
		tmp = 'B';
	}
	else if ((src == 'B' && dst == 'C') || (src == 'C' && dst == 'B'))
	{
		tmp = 'A';
	}
	printf("移动步骤为:\n");
	hanoi(n, src, tmp, dst);
	return 0;
}