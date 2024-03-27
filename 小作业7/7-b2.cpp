/*2253744 �־��� ��*/
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;
/*��Ʒ�ṹ��*/
struct KFC
{
	char label;
	char name[50];
	double price;
};
/*�ײͽṹ��*/
struct SPECIAL
{
	char Label[30];
	char Name[50];
	double Price;
};
/*��Ʒ�˵�*/
const struct KFC list[] = {
	{'A', "�������ȱ�",			19.5},
	{'B', "���༦�ȱ�",			19.5},
	{'C', "�°¶��������ȱ�",		20.0},
	{'D', "�ϱ��������",			18.5},
	{'E', "�ƽ�SPA���ű�(�ٽ���ζ)",	18.0},
	{'F', "������ʽ��ζ��ţ��(����)",	18.0},
	{'G', "˱ָԭζ��(1��)",		12.5},
	{'H', "�ƽ��Ƥ��",			13.5},
	{'I', "�°¶�������(2��)",		13.5},
	{'J', "�������׻�",			12.0},
	{'K', "��������(2��)",			12.5},
	{'L', "������Ǽ�(3��)",		12.5},
	{'M', "֭֭������������ţ��",	55.0},
	{'N', "����(С)",				9.0},
	{'O', "����(��)",				12.5},
	{'P', "����(��)",				14.5},
	{'Q', "ܽ��������",			9.0},
	{'R', "ԭζ��Ͳ������",			6.0},
	{'S', "����������",			7.5},
	{'T', "�ƽ𼦿�",				12.5},
	{'U', "��ʽ��̢",				8.0},
	{'V', "���¿���(С)",			8.5},
	{'W', "���¿���(��)",			10.0},
	{'X', "���¿���(��)",			12.0},
	{'Y', "�����֭",				13.0},
	{'Z', "ѩ������",				14.5},
	{'\0', NULL,				0}
};
/*�ײͲ˵�*/
const struct SPECIAL special[] = {
	//{"AOW", "OK������(�������ȱ�)",		31}, //�������Ҫ���ſ����ע�͵���һ�еġ�COW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"COW", "OK������(�°¶��������ȱ�)",	33.5}, //�������Ҫ���ſ����ע�͵���һ�еġ�AOW���Żݣ��۲��Żݲ˵��Ƿ����˱仯
		{"HHHHHKKKSUWWW", "����ȫ��Ͱ(��Ƥ��)",	101},
		{"APUY", "�����������ļ���(8��)",		44},
		{"GG","˱ָԭζ��(2��)",			21},
		{NULL, NULL, 0}
};
/*��ʼ�����溯��*/
void Init()
{
	system("cls");
	system("mode con cols=130 lines=45");
	/*��ӡ��ͷ*/
	for (int i = 0; i < 75; i++)
		cout << "=";
	cout << endl;
	for (int i = 0; i < 30; i++)
		cout << " ";
	cout << "KFC 2023�����˵�" << endl;
	for (int i = 0; i < 75; i++)
		cout << "=";
	cout << endl;
	/*��ӡ�˵�*/
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
	/*��ӡ�Ż���Ϣ*/
	cout << endl << "���Ż���Ϣ����" << endl;
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
	/*��ӡ�������˵��*/
	cout << endl;
	cout << "���������˵������" << endl;
	cout << "ANV=�������ȱ�+����(С)+���¿���(С) / akaak=�������ȱ�*3+��������*2" << endl;
	cout << "��ĸ���ִ�Сд������˳�򣬵�������0���˳�����" << endl;
	cout << endl;
	cout << "��㵥: ";
}
/*������*/
int main()
{
	/*Discount_map[5][26]����¼ÿһ���ײ���ÿһ�ֵ�Ʒ���ֵĴ���*/
	int Discount_map[5][26] = { 0 };
	for (int i = 0; special[i].Price != 0; i++)
		for (unsigned int j = 0; j < strlen(special[i].Label); j++)
			if (special[i].Label[j] - 'A' >= 0)
				Discount_map[i][special[i].Label[j] - 'A']++;
	/*whileѭ��*/
	while (1)
	{
		Init();
		/*Order[100]����¼�����Ϣ*/
		/*Count_each_item[27]����¼�����Ϣ��ÿһ�ֵ�Ʒ������*/
		/*Total_price�����ƽ��*/
		/*tag����¼��������������*/
		/*Location���жϽ�����������ǡ�+�����ǡ�=��*/
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
				cout << "������󣬰����������." << endl;
				tag = 2;
				break;
			}
		}
		/*tag==1���˳�����*/
		if (tag == 1)
			break;
		/*tag=2���������*/
		else if (tag == 2)
		{
			while (getchar() != '\n');
			char wait = _getch();
			system("cls");
			continue;
		}
		/*��һ������Ϊ�س�������*/
		if (Order[0] == '\n')
			continue;
		cout << "���ĵ��=";
		/*��¼�����Ϣ�еĵ�Ʒ����*/
		for (unsigned int i = 0; i < strlen(Order); i++)
		{
			if (Order[i] - 'A' >= 0 && Order[i] - 'A' <= 26)
				Count_each_item[Order[i] - 'A']++;
		}
		/*��¼���һ����Ʒ��λ��*/
		for (int i = 26; i >= 0; i--)
		{
			if (Count_each_item[i] != 0)
			{
				Location = i;
				break;
			}
		}
		/*��������Ϣ*/
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
		/*������ȼ����ײ�*/
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
						/*ͨ�����ϵ�����������ײ͵��������*/
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
			/*���������ײ͵Ľ��*/
			if (Count_of_special != 999 && Exist)
			{
				Total_price += Count_of_special * special[i].Price;
				for (int j = 0; j < 26; j++)
					if (Discount_map[i][j] != 0)
						Count_each_item[j] -= Count_of_special * Discount_map[i][j];
			}
		}
		/*������ټ���ʣ�൥Ʒ�ļ۸�*/
		for (int i = 0; i < Location + 1; i++)
		{
			if (Count_each_item[i] != 0)
				Total_price += Count_each_item[i] * list[i].price;
		}
		cout << "���ƣ�" << Total_price << "Ԫ" << endl << "�㵥��ɣ������������." << endl;
		char wait = _getch();
		continue;
	}
	return 0;
}