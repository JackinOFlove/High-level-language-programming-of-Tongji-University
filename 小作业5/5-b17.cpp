/*2253744 �־��� ��*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#define TIMES 10
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
void Get_Upperkey(char key[], int Length, int Upper_num)
{
	int Random_index;
	for (int i = 0; i < Upper_num; i++)
	{
		Random_index = rand() % Length;
		if (!key[Random_index])
			key[Random_index] = 'A' + rand() % 26;
		else
			i--;
	}
}
void Get_Lowerkey(char key[], int Length, int Lower_num)
{
	int Random_index;
	for (int i = 0; i < Lower_num; i++)                                                                                                          
	{
		Random_index = rand() % Length;
		if (!key[Random_index])
			key[Random_index] = 'a' + rand() % 26;
		else
			i--;
	}
}
void Get_Numberkey(char key[], int Length, int Number_num)
{
	int Random_index;
	for (int i = 0; i < Number_num; i++)
	{
		Random_index = rand() % Length;
		if (!key[Random_index])
			key[Random_index] = '0' + rand() % 9;
		else
			i--;
	}
}
void Get_Otherkey(char key[], int Length, int Other_num)
{
	int Random_index;
	for (int i = 0; i < Other_num; i++)
	{
		Random_index = rand() % Length;
		if (!key[Random_index])
		{
			int Random_char_index = rand() % 15;
			key[Random_index] = other[Random_char_index];
		}
		else
			i--;
	}
}
void Get_Finalkey(char key[], int Length, int Upper_num, int Lower_num, int Number_num, int Other_num)
{
	Get_Upperkey(key, Length, Upper_num);
	Get_Lowerkey(key, Length, Lower_num);
	Get_Numberkey(key, Length, Number_num);
	Get_Otherkey(key, Length, Other_num);
	int Left_num = Length - Upper_num - Lower_num - Number_num - Other_num;
	for (int i = 0; i < Left_num; i++)
	{
		int Rand_choice = rand() % 4;
		switch (Rand_choice)
		{
		case 0:
			Get_Upperkey(key, Length, 1);
			break;
		case 1:
			Get_Lowerkey(key, Length, 1);
			break;
		case 2:
			Get_Numberkey(key, Length, 1);
			break;
		case 3:
			Get_Otherkey(key, Length, 1);
			break;
		}
	}
}
int main()
{
	int Length, Upper_num, Lower_num, Number_num, Other_num;
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> Length >> Upper_num >> Lower_num >> Number_num >> Other_num;
	if (cin.good() == 0)
		cout << "����Ƿ�" << endl;
	else if (Length < 12 || Length > 16)
		cout << "���볤��[" << Length << "]����ȷ" << endl;
	else if (Upper_num < 2 || Upper_num > 16)
		cout << "��д��ĸ����[" << Upper_num << "]����ȷ" << endl;
	else if (Lower_num < 2 || Lower_num > 16)
		cout << "Сд��ĸ����[" << Lower_num << "]����ȷ" << endl;
	else if (Number_num < 2 || Number_num > 16)
		cout << "���ָ���[" << Number_num << "]����ȷ" << endl;
	else if (Other_num < 2 || Other_num > 16)
		cout << "�������Ÿ���[" << Other_num << "]����ȷ" << endl;
	else if (Upper_num + Lower_num + Number_num + Other_num > Length)
		cout << "�����ַ�����֮��[" << Upper_num << "+" << Lower_num << "+" << Number_num << "+" << Other_num << "]���������볤��[" << Length << "]" << endl;
	else
	{
		srand((unsigned int)time(NULL));
		cout << Length << " " << Upper_num << " " << Lower_num << " " << Number_num << " " << Other_num << endl;
		for (int time = 0; time < TIMES; time++)
		{
			char key[17] = { 0 };
			Get_Finalkey(key, Length, Upper_num, Lower_num, Number_num, Other_num);
			cout << key << endl;
		}
	}
	return 0;
}