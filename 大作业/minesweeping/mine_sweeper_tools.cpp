/*2253744 �־��� ��*/
#include "mine_sweeper.h"
/***************************************************************************
  �������ƣ�Reset_markarr_1(char mark_1[11][11])
  ��    �ܣ���mark_1�������ã�������κ�Ϊ�ޱ�ǣ�
  ���������char mark_1[11][11]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Reset_markarr_1(char mark_1[11][11])
{
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (mark_1[i][j] == 2)
				mark_1[i][j] = 0;
}
/***************************************************************************
  �������ƣ�Reset_markarr_2(char mark_2[18][18])
  ��    �ܣ���mark_2�������ã�������κ�Ϊ�ޱ�ǣ�
  ���������char mark_2[18][18]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Reset_markarr_2(char mark_2[18][18])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 17; j++)
			if (mark_2[i][j] == 2)
				mark_2[i][j] = 0;
}
/***************************************************************************
  �������ƣ�Reset_markarr_3(char mark_3[18][32])
  ��    �ܣ���mark_3�������ã�������κ�Ϊ�ޱ�ǣ�
  ���������char mark_3[18][32]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Reset_markarr_3(char mark_3[18][32])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 31; j++)
			if (mark_3[i][j] == 2)
				mark_3[i][j] = 0;
}
/***************************************************************************
  �������ƣ�Initarr_1(char boomarr_1[11][11], int keydown1, int keydown2, int choice)
  ��    �ܣ���ʼ���Ѷ�1�׺�ÿ������Χ������
  ���������char boomarr_1[11][11], int keydown1, int keydown2, int choice
  �� �� ֵ����
  ˵    ����ע������Ҫ���һ�������λ����0�������������Χ�˸�λ�����ף������Դ��������Ҫ�е�һ�����������
***************************************************************************/
void Initarr_1(char boomarr_1[11][11], int keydown1, int keydown2, int choice)
{
	srand((unsigned int)(time(0)));
	for (int boom_num = 0; boom_num < Boom_num_1;)
	{
		boom_num = 0;
		boomarr_1[rand() % 9 + 1][rand() % 9 + 1] = '*';
		if (choice == 2 || choice == 3 || choice == 4 || choice == 7 || choice == 8 || choice == 9)
		{
			for (int crosswise = keydown1 - 1; crosswise <= keydown1 + 1; crosswise++)
				for (int vertical = keydown2 - 1; vertical <= keydown2 + 1; vertical++)
					if (boomarr_1[crosswise][vertical] == '*')
						boomarr_1[crosswise][vertical] = 0;
		}
		for (int i = 1; i < 10; i++)
			for (int j = 1; j < 10; j++)
				if (boomarr_1[i][j] == '*')
					boom_num++;
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			int count_boom = 0;
			if (boomarr_1[i][j] != '*')
			{
				for (int crosswise = i - 1; crosswise <= i + 1; crosswise++)
					for (int vertical = j - 1; vertical <= j + 1; vertical++)
						if (boomarr_1[crosswise][vertical] == '*')
							count_boom++;
				boomarr_1[i][j] = count_boom + '0';
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Initarr_2(char boomarr_2[18][18], int keydown1, int keydown2, int choice)
  ��    �ܣ���ʼ���Ѷ�2�׺�ÿ������Χ������
  ���������char boomarr_2[18][18], int keydown1, int keydown2, int choice
  �� �� ֵ����
  ˵    ����ע������Ҫ���һ�������λ����0�������������Χ�˸�λ�����ף������Դ��������Ҫ�е�һ�����������
***************************************************************************/
void Initarr_2(char boomarr_2[18][18], int keydown1, int keydown2, int choice)
{
	srand((unsigned int)(time(0)));
	for (int boom_num = 0; boom_num < Boom_num_2;)
	{
		boom_num = 0;
		boomarr_2[rand() % 16 + 1][rand() % 16 + 1] = '*';
		if (choice == 2 || choice == 3 || choice == 4 || choice == 7 || choice == 8 || choice == 9)
		{
			for (int crosswise = keydown1 - 1; crosswise <= keydown1 + 1; crosswise++)
				for (int vertical = keydown2 - 1; vertical <= keydown2 + 1; vertical++)
					if (boomarr_2[crosswise][vertical] == '*')
						boomarr_2[crosswise][vertical] = 0;
		}
		for (int i = 1; i < 17; i++)
			for (int j = 1; j < 17; j++)
				if (boomarr_2[i][j] == '*')
					boom_num++;
	}
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			int count_boom = 0;
			if (boomarr_2[i][j] != '*')
			{
				for (int crosswise = i - 1; crosswise <= i + 1; crosswise++)
					for (int vertical = j - 1; vertical <= j + 1; vertical++)
						if (boomarr_2[crosswise][vertical] == '*')
							count_boom++;
				boomarr_2[i][j] = count_boom + '0';
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Initarr_3(char boomarr_3[18][32], int keydown1, int keydown2, int choice)
  ��    �ܣ���ʼ���Ѷ�3�׺�ÿ������Χ������
  ���������char boomarr_3[18][32], int keydown1, int keydown2, int choice
  �� �� ֵ����
  ˵    ����ע������Ҫ���һ�������λ����0�������������Χ�˸�λ�����ף������Դ��������Ҫ�е�һ�����������
***************************************************************************/
void Initarr_3(char boomarr_3[18][32], int keydown1, int keydown2, int choice)
{
	srand((unsigned int)(time(0)));
	for (int boom_num = 0; boom_num < Boom_num_3;)
	{
		boom_num = 0;
		boomarr_3[rand() % 16 + 1][rand() % 30 + 1] = '*';
		if (choice == 2 || choice == 3 || choice == 4 || choice == 7 || choice == 8 || choice == 9)
		{
			for (int crosswise = keydown1 - 1; crosswise <= keydown1 + 1; crosswise++)
				for (int vertical = keydown2 - 1; vertical <= keydown2 + 1; vertical++)
					if (boomarr_3[crosswise][vertical] == '*')
						boomarr_3[crosswise][vertical] = 0;
		}
		for (int i = 1; i < 17; i++)
			for (int j = 1; j < 31; j++)
				if (boomarr_3[i][j] == '*')
					boom_num++;
	}
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 31; j++)
		{
			int count_boom = 0;
			if (boomarr_3[i][j] != '*')
			{
				for (int crosswise = i - 1; crosswise <= i + 1; crosswise++)
					for (int vertical = j - 1; vertical <= j + 1; vertical++)
						if (boomarr_3[crosswise][vertical] == '*')
							count_boom++;
				boomarr_3[i][j] = count_boom + '0';
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Judge_win_1(char boomarr_1[11][11], char cover_1[11][11])
  ��    �ܣ��ж���Ϸ�Ѷ�1�Ƿ�ʤ��
  ���������char boomarr_1[11][11], char cover_1[11][11]
  �� �� ֵ����
  ˵    ����������е��׶���ʾ���������ʾʤ��
***************************************************************************/
bool Judge_win_1(char boomarr_1[11][11], char cover_1[11][11])
{
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (cover_1[i][j] == 'X')
				if (boomarr_1[i][j] != '*')
					return false;
	return true;
}
/***************************************************************************
  �������ƣ�Judge_win_2(char boomarr_2[18][18], char cover_2[18][18])
  ��    �ܣ��ж���Ϸ�Ѷ�2�Ƿ�ʤ��
  ���������char boomarr_2[18][18], char cover_2[18][18]
  �� �� ֵ����
  ˵    ����������е��׶���ʾ���������ʾʤ��
***************************************************************************/
bool Judge_win_2(char boomarr_2[18][18], char cover_2[18][18])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 17; j++)
			if (cover_2[i][j] == 'X')
				if (boomarr_2[i][j] != '*')
					return false;
	return true;
}
/***************************************************************************
  �������ƣ�Judge_win_3(char boomarr_3[18][32], char cover_3[18][32])
  ��    �ܣ��ж���Ϸ�Ѷ�3�Ƿ�ʤ��
  ���������char boomarr_3[18][32], char cover_3[18][32]
  �� �� ֵ����
  ˵    ����������е��׶���ʾ���������ʾʤ��
***************************************************************************/
bool Judge_win_3(char boomarr_3[18][32], char cover_3[18][32])
{
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 31; j++)
			if (cover_3[i][j] == 'X')
				if (boomarr_3[i][j] != '*')
					return false;
	return true;
}
/***************************************************************************
  �������ƣ�Expand_map_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2)
  ��    �ܣ�����Ѷ�1���򿪡������ĺ���
  ���������char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2
  �� �� ֵ����
  ˵    �������õݹ�ķ������򱻡��򿪡�����Χ�˸������ʹ�øú�����ֱ�������ݹ����ֹ����
***************************************************************************/
void Expand_map_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2)
{
	for (int i = keydown1 - 1; i <= keydown1 + 1; i++)
	{
		for (int j = keydown2 - 1; j <= keydown2 + 1; j++)
		{
			if (flag_1[i][j] == 1)
			{
				if (mark_1[i][j] == 1)
					cover_1[i][j] = 'X';
				else
					cover_1[i][j] = boomarr_1[i][j];
				continue;
			}
			if (flag_1[i][j] == 0)
			{
				if (mark_1[i][j] == 1)
					cover_1[i][j] = 'X';
				else
					cover_1[i][j] = boomarr_1[i][j];
				flag_1[i][j] = 1;
			}
			if (boomarr_1[i][j] == '0')
				Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, i, j);
		}
	}
	for (int i = 1; i < 10; i++)
		for (int j = 1; j < 10; j++)
			if (cover_1[i][j] == 0)
				cover_1[i][j] = 'X';
}
/***************************************************************************
  �������ƣ�Expand_map_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2)
  ��    �ܣ�����Ѷ�2���򿪡������ĺ���
  ���������char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2
  �� �� ֵ����
  ˵    �������õݹ�ķ������򱻡��򿪡�����Χ�˸������ʹ�øú�����ֱ�������ݹ����ֹ����
***************************************************************************/
void Expand_map_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2)
{
	for (int i = keydown1 - 1; i <= keydown1 + 1; i++)
	{
		for (int j = keydown2 - 1; j <= keydown2 + 1; j++)
		{
			if (flag_2[i][j] == 1)
			{
				if (mark_2[i][j] == 1)
					cover_2[i][j] = 'X';
				else
					cover_2[i][j] = boomarr_2[i][j];
				continue;
			}
			if (flag_2[i][j] == 0)
			{
				if (mark_2[i][j] == 1)
					cover_2[i][j] = 'X';
				else
					cover_2[i][j] = boomarr_2[i][j];
				flag_2[i][j] = 1;
			}
			if (boomarr_2[i][j] == '0')
				Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, i, j);
		}
	}
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 17; j++)
			if (cover_2[i][j] == 0)
				cover_2[i][j] = 'X';
}
/***************************************************************************
  �������ƣ�Expand_map_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2)
  ��    �ܣ�����Ѷ�3���򿪡������ĺ���
  ���������char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2
  �� �� ֵ����
  ˵    �������õݹ�ķ������򱻡��򿪡�����Χ�˸������ʹ�øú�����ֱ�������ݹ����ֹ����
***************************************************************************/
void Expand_map_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2)
{
	for (int i = keydown1 - 1; i <= keydown1 + 1; i++)
	{
		for (int j = keydown2 - 1; j <= keydown2 + 1; j++)
		{
			if (flag_3[i][j] == 1)
			{
				if (mark_3[i][j] == 1)
					cover_3[i][j] = 'X';
				else
					cover_3[i][j] = boomarr_3[i][j];
				continue;
			}
			if (flag_3[i][j] == 0)
			{
				if (mark_3[i][j] == 1)
					cover_3[i][j] = 'X';
				else
					cover_3[i][j] = boomarr_3[i][j];
				flag_3[i][j] = 1;
			}
			if (boomarr_3[i][j] == '0')
				Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, i, j);
		}
	}
	for (int i = 1; i < 17; i++)
		for (int j = 1; j < 31; j++)
			if (cover_3[i][j] == 0)
				cover_3[i][j] = 'X';
}
/***************************************************************************
  �������ƣ�Point_Operation_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int& keydown1, int& keydown2)
  ��    �ܣ�����Ѷ�1�԰���ĳ���ı仯����
  ���������char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int& keydown1, int& keydown2
  �� �� ֵ����
  ˵    ������Ϊ�ü���������Ƿ�����򿪣�mark��flag��cover�ı仯
***************************************************************************/
void Point_Operation_1(char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int& keydown1, int& keydown2)
{
	if (boomarr_1[keydown1][keydown2] == '0' && mark_1[keydown1][keydown2] == 0)
	{
		Reset_markarr_1(mark_1);
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
	}
	else
	{
		if (mark_1[keydown1][keydown2] == 1)
		{
			cover_1[keydown1][keydown2] = 'X';
			flag_1[keydown1][keydown2] = 1;
		}
		else if (mark_1[keydown1][keydown2] == 2)
			cover_1[keydown1][keydown2] = cover_1[keydown1][keydown2];
		else
		{
			cover_1[keydown1][keydown2] = boomarr_1[keydown1][keydown2];
			flag_1[keydown1][keydown2] = 1;
		}
	}
}
/***************************************************************************
  �������ƣ�Point_Operation_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int& keydown1, int& keydown2)
  ��    �ܣ�����Ѷ�2�԰���ĳ���ı仯����
  ���������char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int& keydown1, int& keydown2
  �� �� ֵ����
  ˵    ������Ϊ�ü���������Ƿ�����򿪣�mark��flag��cover�ı仯
***************************************************************************/
void Point_Operation_2(char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int& keydown1, int& keydown2)
{
	if (boomarr_2[keydown1][keydown2] == '0' && mark_2[keydown1][keydown2] == 0)
	{
		Reset_markarr_2(mark_2);
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
	}
	else
	{
		if (mark_2[keydown1][keydown2] == 1)
		{
			cover_2[keydown1][keydown2] = 'X';
			flag_2[keydown1][keydown2] = 1;
		}
		else if (mark_2[keydown1][keydown2] == 2)
			cover_2[keydown1][keydown2] = cover_2[keydown1][keydown2];
		else
		{
			cover_2[keydown1][keydown2] = boomarr_2[keydown1][keydown2];
			flag_2[keydown1][keydown2] = 1;
		}
	}
}
/***************************************************************************
  �������ƣ�Point_Operation_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int& keydown1, int& keydown2)
  ��    �ܣ�����Ѷ�2�԰���ĳ���ı仯����
  ���������char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int& keydown1, int& keydown2
  �� �� ֵ����
  ˵    ������Ϊ�ü���������Ƿ�����򿪣�mark��flag��cover�ı仯
***************************************************************************/
void Point_Operation_3(char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int& keydown1, int& keydown2)
{
	if (boomarr_3[keydown1][keydown2] == '0' && mark_3[keydown1][keydown2] == 0)
	{
		Reset_markarr_3(mark_3);
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
	}
	else
	{
		if (mark_3[keydown1][keydown2] == 1)
		{
			cover_3[keydown1][keydown2] = 'X';
			flag_3[keydown1][keydown2] = 1;
		}
		else if (mark_3[keydown1][keydown2] == 2)
			cover_3[keydown1][keydown2] = cover_3[keydown1][keydown2];
		else
		{
			cover_3[keydown1][keydown2] = boomarr_3[keydown1][keydown2];
			flag_3[keydown1][keydown2] = 1;
		}
	}
}