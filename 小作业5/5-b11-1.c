/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
int daxie(int num, int flag_of_zero, int i)
{
	int ret = 0;
	if (num)
	{
		result[i] = chnstr[num * 2];
		result[i + 1] = chnstr[num * 2 + 1];
		ret = 2;
	}
	else
	{
		if (flag_of_zero)
		{
			result[i] = chnstr[num * 2];
			result[i + 1] = chnstr[num * 2 + 1];
			ret = 2;
		}
	}
	return ret;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
	double a;
	char Add[] = "亿万仟佰拾圆整角分";
	/*输入数字及错误处理*/
	while (1)
	{
		printf("请输入[0-100亿)之间的数字:\n");
		int ret = scanf("%lf", &a);
		while (getchar() != '\n');
		{
			if (!ret)
			{
				continue;
			}
			if (a < 0 || a >= 10000000000)
			{
				continue;
			}
			break;
		}
	}
	int a1, a2, a3, a4;
	a1 = (int)(a / 100000000);//十亿、亿
	a2 = (int)(a / 10000 - a1 * 10000);//千万~万
	a3 = (int)((a / 10000 - a1 * 10000 - a2) * 10000 + 0.001);//千~个
	a4 = (int)((a - floor(a)) * 100 + 0.001);//角、分
	printf("大写结果是:\n");
	int n1, n2, n3, n4;
	int flag, index, ret, yuanzheng;
	flag = index = yuanzheng = 0;
	//十亿位和亿位
	if (a1 != 0)
	{
		n1 = a1 / 10;
		n2 = a1 % 10;
		ret = daxie(n1, 0, index);
		index += ret;
		if (n1 != 0)
		{
			//拾
			result[index] = Add[4 * 2];
			result[index + 1] = Add[4 * 2 + 1];
			index += 2;
		}
		ret = daxie(n2, 0, index);
		index += ret;
		//亿
		result[index] = Add[0];
		result[index + 1] = Add[1];
		index += 2;
		if (!a2 && !a3 && !a4)
		{
			//圆
			result[index] = Add[5 * 2];
			result[index + 1] = Add[5 * 2 + 1];
			index += 2;
			//整
			result[index] = Add[6 * 2];
			result[index + 1] = Add[6 * 2 + 1];
			index += 2;
			yuanzheng = 1;
		}
	}
	//千万~万
	if (a2)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		if (!n1 && (n2 || n3 || n4) && a1)
		{
			flag = 1;
			ret = daxie(n1, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n1, 0, index);
			index += ret;
		}
		if (n1)
		{
			//仟
			result[index] = Add[2 * 2];
			result[index + 1] = Add[2 * 2 + 1];
			index += 2;
		}
		if (!n2 && (n3 || n4) && (a1 || n1) && !flag)
		{
			ret = daxie(n2, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n2, 0, index);
			index += ret;
		}
		if (n2)
		{
			//佰
			result[index] = Add[3 * 2];
			result[index + 1] = Add[3 * 2 + 1];
			index += 2;
		}
		if (!n3 && (!flag && (a1 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			ret = daxie(n3, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n3, 0, index);
			index += ret;
		}
		if (n3)
		{
			//拾
			result[index] = Add[4 * 2];
			result[index + 1] = Add[4 * 2 + 1];
			index += 2;
		}
		ret = daxie(n4, 0, index);
		index += ret;
		//万
		result[index] = Add[1 * 2];
		result[index + 1] = Add[1 * 2 + 1];
		index += 2;
		flag = 0;
		if (!a3 && !a4)
		{
			//圆
			result[index] = Add[5 * 2];
			result[index + 1] = Add[5 * 2 + 1];
			index += 2;
			//整
			result[index] = Add[6 * 2];
			result[index + 1] = Add[6 * 2 + 1];
			index += 2;
			yuanzheng = 1;
		}
	}
	//千~个
	if (a3)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		if (!n1 && (n2 || n3 || n4) && (a1 || a2))
		{
			flag = 1;
			ret = daxie(n1, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n1, 0, index);
			index += ret;
		}
		if (n1)
		{
			//仟
			result[index] = Add[2 * 2];
			result[index + 1] = Add[2 * 2 + 1];
			index += 2;
		}
		if (!n2 && (n3 || n4) && (a1 || a2 || n1) && !flag)
		{
			flag = 1;
			ret = daxie(n2, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n2, 0, index);
			index += ret;
		}
		if (n2)
		{
			//佰
			result[index] = Add[3 * 2];
			result[index + 1] = Add[3 * 2 + 1];
			index += 2;
		}
		if (!n3 && (!flag && (a1 || a2 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			ret = daxie(n3, 1, index);
			index += ret;
		}
		else
		{
			ret = daxie(n3, 0, index);
			index += ret;
		}
		if (n3)
		{
			//拾
			result[index] = Add[4 * 2];
			result[index + 1] = Add[4 * 2 + 1];
			index += 2;
		}
		ret = daxie(n4, 0, index);
		index += ret;
		flag = 0;
	}
	if (a1 || a2 || a3)
	{
		if (!yuanzheng)
		{
			//圆
			result[index] = Add[5 * 2];
			result[index + 1] = Add[5 * 2 + 1];
			index += 2;
			if (!a4)
			{
				//整
				result[index] = Add[6 * 2];
				result[index + 1] = Add[6 * 2 + 1];
				index += 2;
			}
		}
	}
	//角、分
	if (a4)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		if (!n1 && n2 && (a1 || a2 || a3))
		{
			ret = daxie(n1, 1, index);
			index += ret;
			flag = 1;
		}
		else
		{
			ret = daxie(n1, 0, index);
			index += ret;
		}
		if (n1)
		{
			//角
			result[index] = Add[7 * 2];
			result[index + 1] = Add[7 * 2 + 1];
			index += 2;
		}
		if (n2)
		{
			ret = daxie(n2, 0, index);
			index += ret;
			//分
			result[index] = Add[8 * 2];
			result[index + 1] = Add[8 * 2 + 1];
			index += 2;
		}
		else
		{
			//整
			result[index] = Add[6 * 2];
			result[index + 1] = Add[6 * 2 + 1];
			index += 2;
			index += 2;
		}
	}
	if (a == 0)
	{
		result[0] = chnstr[0];
		result[1] = chnstr[1];
		result[2] = Add[5 * 2];
		result[3] = Add[5 * 2 + 1];
		result[4] = Add[6 * 2];
		result[5] = Add[6 * 2 + 1];
	}
    printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
