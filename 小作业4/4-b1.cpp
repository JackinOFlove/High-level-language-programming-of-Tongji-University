/*2253744 林觉凯 软工 */
#include <iostream>
#include <cmath>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	cout << "请输入[0-100亿)之间的数字:" << endl;
	double a;
	cin >> a;
	int a1, a2, a3, a4;
	a1 = (int)(a / 100000000);//十亿、亿位
	a2 = (int)(a / 10000 - a1 * 10000);//千万~万位
	a3 = (int)((a / 10000 - a1 * 10000 - a2) * 10000 + 0.001);//千~个位
	a4 = (int)((a - floor(a)) * 100 + 0.001);//角、分位
	int n1, n2, n3, n4;
	int flag = 0;
	cout << "大写结果是:" << endl;
	if (a1 != 0)
	{
		n1 = a1 / 10;
		n2 = a1 % 10;
		daxie(n1, 0);
		if (n1 != 0)
		{
			cout << "拾";
		}
		daxie(n2, 0);
		cout << "亿";
		if (a2 == 0 && a3 == 0 && a4 == 0)
		{
			cout << "圆整" << endl;
			return 0;
		}
	}
	if (a2 != 0)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		if (n1==0 && (n2!=0 || n3!=0 || n4!=0) && a1!=0)
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1 != 0)
		{
			cout << "仟";
		}
		if (n2 == 0 && (n3 != 0 || n4 != 0) && (a1 != 0 || n1 != 0) && flag == 0)
		{
			flag = 1;
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}
		if (n2 != 0)
		{
			cout << "佰";
		}
		if (n3 == 0 && (flag == 0 && (a1 != 0 || n1 != 0 || n2 != 0) && n4 != 0) || (flag != 0 && n2 != 0 && n4 != 0))
		{
			flag = 1;
			daxie(n3, 1);
		}
		else
		{
			daxie(n3, 0);
		}
		if(n3 != 0)
		{
			cout << "拾";
		}
		daxie(n4, 0);
		cout << "万";
		flag = 0;
		if (a3==0 && a4==0)
		{
			cout << "圆整" << endl;
			return 0;
		}
	}
	if (a3 != 0)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		if (n1==0 && (n2!=0 || n3!=0 || n4!=0) && (a1!=0 || a2!=0))
		{
			flag = 1;
			daxie(n1, 1);
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1 != 0)
		{
			cout << "仟";
		}
		if (n2==0 && (n3!=0 || n4!=0) && (a1!=0 || a2!=0 || n1!=0) && flag==0)
		{
			flag = 1;
			daxie(n2, 1);
		}
		else
		{
			daxie(n2, 0);
		}
		if(n2 != 0)
		{
			cout << "佰";
		}
		if (n3 == 0 && (flag == 0 && (a1 != 0 || a2 != 0 || n1 != 0 || n2 != 0) && n4 != 0) || (flag != 0 && n2 != 0 && n4 != 0))
		{
			daxie(n3, 1);
		}
		else
		{
			daxie(n3, 0);
		}
		if (n3 != 0)
		{
			cout << "拾";
		}
		daxie(n4, 0);
		flag = 0;
	}
	if (a1!=0 || a2!=0 || a3!=0)
	{
		cout << "圆";
		if (a4==0)
		{
			cout << "整" << endl;
			return 0;
		}
	}
	if (a4!=0)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		if (n1==0 && n2!=0 && (a1!=0 || a2!=0 || a3!=0))
		{
			daxie(n1, 1);
			flag = 1;
		}
		else
		{
			daxie(n1, 0);
		}
		if (n1 != 0)
		{
			cout << "角";
		}
		if (n2!=0)
		{
			daxie(n2, 0);
			cout << "分" << endl;
		}
		else
		{
			cout << "整" << endl;
		}	
	}
	if (a == 0)
	{
		cout << "零圆整" << endl;
	}
	/* 按需完成 */
	return 0;
}