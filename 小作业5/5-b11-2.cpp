/*2253744 林觉凯 软工*/
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/
void daxie(int num, int flag_of_zero)
{
	if (num == 0 && flag_of_zero)
	{
		result = result + chnstr[0] + chnstr[1];
	}
	if (num != 0)
	{
		result = result + chnstr[num * 2] + chnstr[num * 2 + 1];
	}
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
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> a;
		if (cin.good() == 0)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (a < 0 || a >= 10000000000)
		{
			continue;
		}	
		break;
	}
	//分解数字
	int a1, a2, a3, a4;
	a1 = (int)(a / 100000000);//十亿、亿
	a2 = (int)(a / 10000 - a1 * 10000);//千万~万
	a3 = (int)((a / 10000 - a1 * 10000 - a2) * 10000 + 0.001);//千~个
	a4 = (int)((a - floor(a)) * 100 + 0.001);//角、分
	//进入大写环节
	printf("大写结果是:\n");
	int n1, n2, n3, n4;
	int flag, index, yuanzheng;
	flag = index = yuanzheng = 0;
	//十亿、亿
	if (a1 != 0)
	{
		n1 = a1 / 10;
		n2 = a1 % 10;
		daxie(n1, 0);
		if (n1 != 0)
		{
			result = result + Add[4 * 2] + Add[4 * 2 + 1];//拾
		}	
		daxie(n2, 0);
		result = result + Add[0] + Add[1];//亿
		if (!a2 && !a3 && !a4)
		{
			result = result + Add[5 * 2] + Add[5 * 2 + 1];//圆
			result = result + Add[6 * 2] + Add[6 * 2 + 1];//整
			yuanzheng = 1;
		}
	}
	//千万~万
	if (a2 != 0)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		if (!n1 && (n2 || n3 || n4) && a1)
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1)
		{
			result = result + Add[2 * 2] + Add[2 * 2 + 1];//仟
		}	
		if (!n2 && (n3 || n4) && (a1 || n1) && !flag)
		{
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}
		if (n2)
		{
			result = result + Add[3 * 2] + Add[3 * 2 + 1];//佰
		}
		if (!n3 && (!flag && (a1 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			daxie(n3, 1);
		}
		else 
		{
			daxie(n3, 0);
		}	
		if (n3)
		{
			result = result + Add[4 * 2] + Add[4 * 2 + 1];//拾
		}		
		daxie(n4, 0);
		result = result + Add[1 * 2] + Add[1 * 2 + 1];//万
		flag = 0;
		if (!a3 && !a4)
		{
			result = result + Add[5 * 2] + Add[5 * 2 + 1];//圆
			result = result + Add[6 * 2] + Add[6 * 2 + 1];//整
			yuanzheng = 1;
		}
	}
	//千~个
	if (a3 != 0)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		if (!n1 && (n2 || n3 || n4) && (a1 || a2))
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1)
			result = result + Add[2 * 2] + Add[2 * 2 + 1];//仟
		if (!n2 && (n3 || n4) && (a1 || a2 || n1) && !flag)
		{
			flag = 1;
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}			
		if (n2)
		{
			result = result + Add[3 * 2] + Add[3 * 2 + 1];//佰
		}
		if (!n3 && (!flag && (a1 || a2 || n1 || n2) && n4) || (flag && n2 && n4))
		{
			daxie(n3, 1);
		}	
		else
		{
			daxie(n3, 0);
		}
		if (n3)
		{
			result = result + Add[4 * 2] + Add[4 * 2 + 1];//拾
		}
		daxie(n4, 0);
		flag = 0;
	}
	if (a1 || a2 || a3)
	{
		if (!yuanzheng)
		{
			result = result + Add[5 * 2] + Add[5 * 2 + 1];//圆
			if (!a4)
			{
				result = result + Add[6 * 2] + Add[6 * 2 + 1];//整
			}	
		}
	}
	//角、分
	if (a4 != 0)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		if (!n1 && n2 && (a1 || a2 || a3))
		{
			daxie(n1, 1);
			flag = 1;
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1)
		{
			result = result + Add[7 * 2] + Add[7 * 2 + 1];//角
		}
		if (n2)
		{
			daxie(n2, 0);
			result = result + Add[8 * 2] + Add[8 * 2 + 1];//分
		}
		else
		{
			result = result + Add[6 * 2] + Add[6 * 2 + 1];//整
		}
	}
	if (a == 0)
	{
		result = result + chnstr[0] + chnstr[1] + Add[5 * 2] + Add[5 * 2 + 1] + Add[6 * 2] + Add[6 * 2 + 1];
	}
	cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}
