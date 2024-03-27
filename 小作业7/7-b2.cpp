/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;
/*单品结构体*/
struct KFC
{
	char label;
	char name[50];
	double price;
};
/*套餐结构体*/
struct SPECIAL
{
	char Label[30];
	char Name[50];
	double Price;
};
/*单品菜单*/
const struct KFC list[] = {
	{'A', "香辣鸡腿堡",			19.5},
	{'B', "劲脆鸡腿堡",			19.5},
	{'C', "新奥尔良烤鸡腿堡",		20.0},
	{'D', "老北京鸡肉卷",			18.5},
	{'E', "黄金SPA鸡排堡(藤椒风味)",	18.0},
	{'F', "经典美式风味嫩牛堡(单层)",	18.0},
	{'G', "吮指原味鸡(1块)",		12.5},
	{'H', "黄金脆皮鸡",			13.5},
	{'I', "新奥尔良烤翅(2块)",		13.5},
	{'J', "劲爆鸡米花",			12.0},
	{'K', "香辣鸡翅(2块)",			12.5},
	{'L', "热辣香骨鸡(3块)",		12.5},
	{'M', "汁汁厚做培根三层和牛堡",	55.0},
	{'N', "薯条(小)",				9.0},
	{'O', "薯条(中)",				12.5},
	{'P', "薯条(大)",				14.5},
	{'Q', "芙蓉蔬荟汤",			9.0},
	{'R', "原味花筒冰激凌",			6.0},
	{'S', "醇香土豆泥",			7.5},
	{'T', "黄金鸡块",				12.5},
	{'U', "葡式蛋挞",				8.0},
	{'V', "百事可乐(小)",			8.5},
	{'W', "百事可乐(中)",			10.0},
	{'X', "百事可乐(大)",			12.0},
	{'Y', "九珍果汁",				13.0},
	{'Z', "雪顶咖啡",				14.5},
	{'\0', NULL,				0}
};
/*套餐菜单*/
const struct SPECIAL special[] = {
	//{"AOW", "OK三件套(香辣鸡腿堡)",		31}, //如果有需要，放开此项，注释掉下一行的“COW”优惠，观察优惠菜单是否发生了变化
		{"COW", "OK三件套(新奥尔良烤鸡腿堡)",	33.5}, //如果有需要，放开此项，注释掉上一行的“AOW”优惠，观察优惠菜单是否发生了变化
		{"HHHHHKKKSUWWW", "超爆全家桶(脆皮鸡)",	101},
		{"APUY", "人气明星配四件套(8折)",		44},
		{"GG","吮指原味鸡(2块)",			21},
		{NULL, NULL, 0}
};
/*初始化界面函数*/
void Init()
{
	system("cls");
	system("mode con cols=130 lines=45");
	/*打印标头*/
	for (int i = 0; i < 75; i++)
		cout << "=";
	cout << endl;
	for (int i = 0; i < 30; i++)
		cout << " ";
	cout << "KFC 2023春季菜单" << endl;
	for (int i = 0; i < 75; i++)
		cout << "=";
	cout << endl;
	/*打印菜单*/
	int flag = 0;
	for (int i = 0; i < 26; i++)
	{
		cout << setiosflags(ios::left);
		cout << " " << list[i].label << " " << setw(26) << list[i].name << setw(5) << list[i].price << "   ";
		flag++;
		if (flag == 1)
			cout << "|   ";
		if (flag == 2)
		{
			cout << endl;
			flag = 0;
		}
	}
	/*打印优惠信息*/
	cout << endl << "【优惠信息】：" << endl;
	for (int i = 0; special[i].Price != 0; i++)
	{
		cout << special[i].Name << "=";
		for (unsigned int j = 0; j < strlen(special[i].Label); j++)
		{
			unsigned int k = j;
			for (; k < strlen(special[i].Label) - 1; k++)
			{
				if (special[i].Label[k] != special[i].Label[k + 1])
					break;
			}
			unsigned int number = k - j + 1;
			cout << list[special[i].Label[j] - 'A'].name;
			if (number > 1)
				cout << "*" << number;
			j = k;
			if (j != strlen(special[i].Label) - 1)
				cout << "+";
			else
				cout << "=";
		}
		cout << special[i].Price << endl;
	}
	/*打印输入规则说明*/
	cout << endl;
	cout << "【输入规则说明】：" << endl;
	cout << "ANV=香辣鸡腿堡+薯条(小)+百事可乐(小) / akaak=香辣鸡腿堡*3+香辣鸡翅*2" << endl;
	cout << "字母不分大小写，不限顺序，单独输入0则退出程序" << endl;
	cout << endl;
	cout << "请点单: ";
}
/*主函数*/
int main()
{
	/*Discount_map[5][26]：记录每一种套餐中每一种单品出现的次数*/
	int Discount_map[5][26] = { 0 };
	for (int i = 0; special[i].Price != 0; i++)
		for (unsigned int j = 0; j < strlen(special[i].Label); j++)
			if (special[i].Label[j] - 'A' >= 0)
				Discount_map[i][special[i].Label[j] - 'A']++;
	/*while循环*/
	while (1)
	{
		Init();
		/*Order[100]：记录点餐信息*/
		/*Count_each_item[27]：记录点餐信息中每一种单品的数量*/
		/*Total_price：共计金额*/
		/*tag：记录输入的若干种情况*/
		/*Location：判断紧接着输出的是“+”还是“=”*/
		char Order[100] = { 0 };
		int Count_each_item[27] = { 0 };
		double Total_price = 0;
		int tag = 0;
		int Location = 0;
		for (int i = 0;; i++)
		{
			Order[i] = getchar();
			if (Order[i] == '\n')
				break;
			if (Order[0] == '0' && getchar() == '\n')
			{
				tag = 1;
				break;
			}
			if (Order[i] >= 'a' && Order[i] <= 'z')
				Order[i] -= 'a' - 'A';
			if (Order[i] < 'A' || Order[i] > 'Z' || cin.good() == 0)
			{
				cout << "输入错误，按任意键继续." << endl;
				tag = 2;
				break;
			}
		}
		/*tag==1，退出程序*/
		if (tag == 1)
			break;
		/*tag=2，输入错误*/
		else if (tag == 2)
		{
			while (getchar() != '\n');
			char wait = _getch();
			system("cls");
			continue;
		}
		/*第一个输入为回车的特判*/
		if (Order[0] == '\n')
			continue;
		cout << "您的点餐=";
		/*记录点餐信息中的单品数量*/
		for (unsigned int i = 0; i < strlen(Order); i++)
		{
			if (Order[i] - 'A' >= 0 && Order[i] - 'A' <= 26)
				Count_each_item[Order[i] - 'A']++;
		}
		/*记录最后一个单品的位置*/
		for (int i = 26; i >= 0; i--)
		{
			if (Count_each_item[i] != 0)
			{
				Location = i;
				break;
			}
		}
		/*输出点餐信息*/
		for (int i = 0; list[i].price != 0; i++)
		{
			if (Count_each_item[i] != 0)
			{
				cout << list[i].name;
				if (Count_each_item[i] > 1)
					cout << "*" << Count_each_item[i];
				if (i != Location)
					cout << "+";
				else
					cout << endl;
			}
		}
		/*计算金额：先计算套餐*/
		for (int i = 0; special[i].Price != 0; i++)
		{
			bool Exist = true;
			int Count_of_special = 999;
			for (int j = 0; j < 26; j++)
			{
				if (Discount_map[i][j] != 0)
				{
					if (Count_each_item[j] >= Discount_map[i][j] && Count_each_item[j] != 0)
					{
						/*通过不断迭代算出这种套餐的最大数量*/
						if (Count_each_item[j] / Discount_map[i][j] < Count_of_special)
							Count_of_special = Count_each_item[j] / Discount_map[i][j];
					}
					else
					{
						Exist = false;
						break;
					}
				}
			}
			/*计算这种套餐的金额*/
			if (Count_of_special != 999 && Exist)
			{
				Total_price += Count_of_special * special[i].Price;
				for (int j = 0; j < 26; j++)
					if (Discount_map[i][j] != 0)
						Count_each_item[j] -= Count_of_special * Discount_map[i][j];
			}
		}
		/*计算金额：再加上剩余单品的价格*/
		for (int i = 0; i < Location + 1; i++)
		{
			if (Count_each_item[i] != 0)
				Total_price += Count_each_item[i] * list[i].price;
		}
		cout << "共计：" << Total_price << "元" << endl << "点单完成，按任意键继续." << endl;
		char wait = _getch();
		continue;
	}
	return 0;
}