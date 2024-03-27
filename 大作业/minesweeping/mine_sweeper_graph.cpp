/*2253744 �־��� ��*/
#include "mine_sweeper.h"
/***************************************************************************
  �������ƣ�Color_of_Graph(char ch)
  ��    �ܣ���ӡ�򿪺�ÿ�����Ӧ�������͸����ֵ���ɫ
  ���������char ch
  �� �� ֵ����
  ˵    ����������ͬ��������ɫҲ�ǲ�һ����
***************************************************************************/
void Color_of_Graph(char ch)
{
	switch (ch)
	{
	case '0':
		cct_setcolor(7, 7);
		break;
	case '1':
		cct_setcolor(7, 1);
		break;
	case '2':
		cct_setcolor(7, 2);
		break;
	case '3':
		cct_setcolor(7, 3);
		break;
	case '4':
		cct_setcolor(7, 4);
		break;
	case '5':
		cct_setcolor(7, 5);
		break;
	case '6':
		cct_setcolor(7, 6);
		break;
	case '7':
		cct_setcolor(7, 7);
		break;
	case '8':
		cct_setcolor(7, 8);
		break;
	case 'X':
		cct_setcolor(6, 6);
		break;
	case '*':
		cct_setcolor(7, 0);
		break;
	}
	if (ch == '0' || ch == 'X')
		cout << ' ';
	else
		cout << ch;
	cct_setcolor(0, 7);
}
/***************************************************************************
  �������ƣ�Print_framework_1()
  ��    �ܣ���ӡ�Ѷ�1�Ŀ��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_framework_1()
{
	cout << endl;
	for (int i = 0; i < 9; i++)
		cout << setw(6) << i;
	cout << endl << "  ";
	cct_setcolor(15, 0);
	cout << "�X";
	for (int i = 0; i < 8; i++)
		cout << "�T�T�j";
	cout << "�T�T�[" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�U";
	for (int i = 0; i < 9; i++)
		cout << "    �U";
	cout << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�U";
	for (int i = 0; i < 9; i++)
		cout << "    �U";
	cout << endl;
	for (int i = 0; i < 8; i++)
	{
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�d";
		for (int j = 0; j < 8; j++)
			cout << "�T�T�p";
		cout << "�T�T�g" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�U";
		for (int j = 0; j < 9; j++)
			cout << "    �U";
		cout << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�U";
		for (int i = 0; i < 9; i++)
			cout << "    �U";
		cout << endl;
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�^";
	for (int i = 0; i < 8; i++)
		cout << "�T�T�m";
	cout << "�T�T�a" << endl;
	cct_setcolor(0, 7);
	for (int i = 0; i < 9; i++)
	{
		char ch = 'A';
		cct_gotoxy(0, 3 * (i + 1) + 1);
		putchar(ch + i);
	}
}
/***************************************************************************
  �������ƣ�Print_framework_2()
  ��    �ܣ���ӡ�Ѷ�2�Ŀ��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_framework_2()
{
	cout << endl;
	for (int i = 0; i < 16; i++)
	{
		if (i == 10)
			cout << setw(7) << i;
		else
			cout << setw(6) << i;
	}
	cout << endl << "  ";
	cct_setcolor(15, 0);
	cout << "�X";
	for (int i = 0; i < 15; i++)
		cout << "�T�T�j";
	cout << "�T�T�[" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�U" ;
	for (int i = 0; i < 16; i++)
		cout << "    �U";
	cout << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�U";
	for (int i = 0; i < 16; i++)
		cout << "    �U";
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�d";
		for (int j = 0; j < 15; j++)
			cout << "�T�T�p";
		cout << "�T�T�g" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�U";
		for (int j = 0; j < 16; j++)
			cout << "    �U";
		cout << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�U";
		for (int j = 0; j < 16; j++)
			cout << "    �U";
		cout << endl;
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�^";
	for (int i = 0; i < 15; i++)
		cout << "�T�T�m";
	cout << "�T�T�a" << endl;
	cct_setcolor(0, 7);
	for (int i = 0; i < 16; i++)
	{
		char ch = 'A';
		cct_gotoxy(0, 3 * (i + 1) + 1);
		putchar(ch + i);
	}
}
/***************************************************************************
  �������ƣ�Print_framework_3()
  ��    �ܣ���ӡ�Ѷ�3�Ŀ��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_framework_3()
{
	cout << endl;
	for (int i = 0; i < 30; i++)
	{
		if (i == 10)
			cout << setw(7) << i;
		else
			cout << setw(6) << i;
	}
	cout << endl << "  ";
	cct_setcolor(15, 0);
	cout << "�X";
	for (int i = 0; i < 29; i++)
		cout << "�T�T�j";
	cout << "�T�T�[" << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�U";
	for (int i = 0; i < 30; i++)
		cout << "    �U";
	cout << endl;
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�U";
	for (int i = 0; i < 30; i++)
		cout << "    �U";
	cout << endl;
	for (int i = 0; i < 15; i++)
	{
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�d";
		for (int j = 0; j < 29; j++)
			cout << "�T�T�p";
		cout << "�T�T�g" << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�U";
		for (int j = 0; j < 30; j++)
			cout << "    �U";
		cout << endl;
		cct_setcolor(0, 7);
		cout << "  ";
		cct_setcolor(15, 0);
		cout << "�U";
		for (int j = 0; j < 30; j++)
			cout << "    �U";
		cout << endl;
	}
	cct_setcolor(0, 7);
	cout << "  ";
	cct_setcolor(15, 0);
	cout << "�^";
	for (int i = 0; i < 29; i++)
		cout << "�T�T�m";
	cout << "�T�T�a" << endl;
	cct_setcolor(0, 7);
	for (int i = 0; i < 16; i++)
	{
		char ch = 'A';
		cct_gotoxy(0, 3 * (i + 1) + 1);
		putchar(ch + i);
	}
}
/***************************************************************************
  �������ƣ�Print_InitGraph_1()
  ��    �ܣ���ӡ�Ѷ�1�ĳ�ʼ��ͼ
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_InitGraph_1()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cct_gotoxy(6 * j - 2, 3 * i);
			cct_setcolor(6, 6);
			cout << "    ";
			cct_gotoxy(6 * j - 2, 3 * i + 1);
			cout << "    ";
			cct_setcolor(0, 7);
		}
	}
}
/***************************************************************************
  �������ƣ�Print_InitGraph_2()
  ��    �ܣ���ӡ�Ѷ�2�ĳ�ʼ��ͼ
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_InitGraph_2()
{
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			cct_gotoxy(6 * j - 2, 3 * i);
			cct_setcolor(6, 6);
			cout << "    ";
			cct_gotoxy(6 * j - 2, 3 * i + 1);
			cout << "    ";
			cct_setcolor(0, 7);
		}
	}
}
/***************************************************************************
  �������ƣ�Print_InitGraph_3()
  ��    �ܣ���ӡ�Ѷ�3�ĳ�ʼ��ͼ
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_InitGraph_3()
{
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 31; j++)
		{
			cct_gotoxy(6 * j - 2, 3 * i);
			cct_setcolor(6, 6);
			cout << "    ";
			cct_gotoxy(6 * j - 2, 3 * i + 1);
			cout << "    ";
			cct_setcolor(0, 7);
		}
	}
}
/***************************************************************************
  �������ƣ�Print_Leftboom(int Left_boom,int choice)
  ��    �ܣ���ӡʣ������
  ���������int Left_boom,int choice
  �� �� ֵ����
  ˵    ��������������ɫ����ӡλ�õȵ�
***************************************************************************/
void Print_Leftboom(int Left_boom,int choice)
{
	if (choice == 9)
	{
		cct_gotoxy(35, 0);
		cct_setcolor(0, 14);
		if (Left_boom > 0)
			cout << setw(2) << Left_boom << " ";
		else
			cout << setw(2) << 0 << " ";
		cct_setcolor(0, 7);
	}
}
/***************************************************************************
  �������ƣ�Print_markboom_map_1(char mark_1[11][11])
  ��    �ܣ���ӡ�Ѷ�1����ǵ���ͼ
  ���������char mark_1[11][11]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_markboom_map_1(char mark_1[11][11])
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (mark_1[i][j] == 1)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(12, 4);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				cct_setcolor(12, 7);
				cout << '#';
				cct_setcolor(12, 4);
				cout << "  ";
				cct_setcolor(0, 7);
			}
			else
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(6, 6);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << "    ";
				cct_setcolor(0, 7);
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Print_markboom_map_2(char mark_2[18][18])
  ��    �ܣ���ӡ�Ѷ�2����ǵ���ͼ
  ���������char mark_2[18][18]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_markboom_map_2(char mark_1[18][18])
{
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 17; j++)
		{
			if (mark_1[i][j] == 1)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(12, 4);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				cct_setcolor(12, 7);
				cout << '#';
				cct_setcolor(12, 4);
				cout << "  ";
				cct_setcolor(0, 7);
			}
			else
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(6, 6);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << "    ";
				cct_setcolor(0, 7);
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Print_markboom_map_3(char mark_1[18][32])
  ��    �ܣ���ӡ�Ѷ�3����ǵ���ͼ
  ���������char mark_1[18][32]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_markboom_map_3(char mark_1[18][32])
{
	for (int i = 1; i < 17; i++)
	{
		for (int j = 1; j < 31; j++)
		{
			if (mark_1[i][j] == 1)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(12, 4);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				cct_setcolor(12, 7);
				cout << '#';
				cct_setcolor(12, 4);
				cout << "  ";
				cct_setcolor(0, 7);
			}
			else
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(6, 6);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << "    ";
				cct_setcolor(0, 7);
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Pseudographics_dfficulty_1(int choice)
  ��    �ܣ����αͼ���Ѷ�1���֣�ѡ��5-9�����ܵ���Ҫ����
  ���������int choice
  �� �� ֵ����
  ˵    ��������αͼ���е����������������Ҫ����
***************************************************************************/
void Pseudographics_dfficulty_1(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	cct_setfontsize("��������", 16, 8);
	cct_setconsoleborder(59, 35, 59, 35);
	char boomarr_1[11][11] = { 0 };
	char cover_1[11][11] = { 0 };
	char flag_1[11][11] = { 0 };
	char mark_1[11][11] = { 0 };
	int keydown1 = 0;
	int keydown2 = 0;
	int Keydown_ret = 0;
	int Left_boom = Boom_num_1;
	Print_framework_1();
	if (choice == 7 || choice == 8 || choice == 9)
	{
		if (choice == 8)
		{
			cct_gotoxy(0, 0);
			cout << "��Esc�˳�";
		}
		if (choice == 9)
		{
			cct_gotoxy(0, 0);
			cout << "��Esc�˳����ո���ʾʱ��  ";
			cct_setcolor(0, 14);
			cout << "ʣ��������" << setw(2) << Left_boom;
		}
		Print_InitGraph_1();
		Mouse_Operation_1(choice, keydown1, keydown2, flag_1, mark_1, Keydown_ret, Left_boom);
		Print_Leftboom(Left_boom, choice);
		while (Keydown_ret == 2)
		{
			cct_gotoxy(39, 0);
			Endpoint = clock();
			cct_setcolor(0, 14);
			cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
			cct_setcolor(0, 7);
			Keydown_ret = 0;
			Mouse_Operation_1(choice, keydown1, keydown2, flag_1, mark_1, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
		}
		if (Keydown_ret == 1)
		{
			cct_gotoxy(0, 31);
			return;
		}
		cct_gotoxy(39, 0);
		cout << "                   ";
		cct_setcolor(0, 7);
		while (mark_1[keydown1][keydown2] != 0)
		{
			Print_markboom_map_1(mark_1);
			Mouse_Operation_1(choice, keydown1, keydown2, flag_1, mark_1, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
			while (Keydown_ret == 2)
			{
				cct_gotoxy(39, 0);
				Endpoint = clock();
				cct_setcolor(0, 14);
				cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_setcolor(0, 7);
				Keydown_ret = 0;
				Mouse_Operation_1(choice, keydown1, keydown2, flag_1, mark_1, Keydown_ret, Left_boom);
				Print_Leftboom(Left_boom, choice);
			}
			if (Keydown_ret == 1)
			{
				cct_gotoxy(0, 31);
				return;
			}
			cct_gotoxy(39, 0);
			cout << "                   ";
		}
	}
	Reset_markarr_1(mark_1);
	Initarr_1(boomarr_1, keydown1, keydown2, choice);
	if (choice == 5)
		Graph_Output_1(choice, boomarr_1, cover_1, mark_1);
	if (choice == 6)
	{
		Graph_Output_1(choice, boomarr_1, cover_1, mark_1);
		Mouse_Operation_1(choice, keydown1, keydown2, flag_1, mark_1, Keydown_ret, Left_boom);
	}
	if (choice == 7)
	{
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Graph_Output_1(choice, boomarr_1, cover_1, mark_1);
		cct_gotoxy(0, 32);
	}
	if (choice == 8 || choice == 9)
	{
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Graph_Output_1(choice, boomarr_1, cover_1, mark_1);
		Graph_game_1(choice, boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2, Startpoint, Endpoint, Left_boom);
	}
}
/***************************************************************************
  �������ƣ�Pseudographics_dfficulty_2(int choice)
  ��    �ܣ����αͼ���Ѷ�2���֣�ѡ��5-9�����ܵ���Ҫ����
  ���������int choice
  �� �� ֵ����
  ˵    ��������αͼ���е����������������Ҫ����
***************************************************************************/
void Pseudographics_dfficulty_2(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	cct_setfontsize("��������", 16, 8);
	cct_setconsoleborder(101, 56, 101, 56);
	char boomarr_2[18][18] = { 0 };
	char cover_2[18][18] = { 0 };
	char flag_2[18][18] = { 0 };
	char mark_2[18][18] = { 0 };
	int keydown1 = 0;
	int keydown2 = 0;
	int Keydown_ret = 0;
	int Left_boom = Boom_num_2;
	Print_framework_2();
	if (choice == 7 || choice == 8 || choice == 9)
	{
		if (choice == 8)
		{
			cct_gotoxy(0, 0);
			cout << "��Esc�˳�";
		}
		if (choice == 9)
		{
			cct_gotoxy(0, 0);
			cout << "��Esc�˳����ո���ʾʱ��  ";
			cct_setcolor(0, 14);
			cout << "ʣ��������" << setw(2) << Left_boom;
		}
		Print_InitGraph_2();
		Mouse_Operation_2(choice, keydown1, keydown2, flag_2, mark_2, Keydown_ret, Left_boom);
		Print_Leftboom(Left_boom, choice);
		while (Keydown_ret == 2)
		{
			cct_gotoxy(39, 0);
			Endpoint = clock();
			cct_setcolor(0, 14);
			cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
			cct_setcolor(0, 7);
			Keydown_ret = 0;
			Mouse_Operation_2(choice, keydown1, keydown2, flag_2, mark_2, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
		}
		if (Keydown_ret == 1)
		{
			cct_gotoxy(0, 52);
			return;
		}
		cct_gotoxy(39, 0);
		cout << "                   ";
		cct_setcolor(0, 7);
		while (mark_2[keydown1][keydown2] != 0)
		{
			Print_markboom_map_2(mark_2);
			Mouse_Operation_2(choice, keydown1, keydown2, flag_2, mark_2, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
			while (Keydown_ret == 2)
			{
				cct_gotoxy(39, 0);
				Endpoint = clock();
				cct_setcolor(0, 14);
				cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_setcolor(0, 7);
				Keydown_ret = 0;
				Mouse_Operation_2(choice, keydown1, keydown2, flag_2, mark_2, Keydown_ret, Left_boom);
				Print_Leftboom(Left_boom, choice);
			}
			if (Keydown_ret == 1)
			{
				cct_gotoxy(0, 52);
				return;
			}
			cct_gotoxy(39, 0);
			cout << "                   ";
		}
	}
	Reset_markarr_2(mark_2);
	Initarr_2(boomarr_2, keydown1, keydown2, choice);
	if (choice == 5)
		Graph_Output_2(choice, boomarr_2, cover_2, mark_2);
	if (choice == 6)
	{
		Graph_Output_2(choice, boomarr_2, cover_2, mark_2);
		Mouse_Operation_2(choice, keydown1, keydown2, flag_2, mark_2, Keydown_ret, Left_boom);
	}
	if (choice == 7)
	{
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Graph_Output_2(choice, boomarr_2, cover_2, mark_2);
		cct_gotoxy(0, 53);
	}
	if (choice == 8 || choice == 9)
	{
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Graph_Output_2(choice, boomarr_2, cover_2, mark_2);
		Graph_game_2(choice, boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2, Startpoint, Endpoint, Left_boom);
	}
}
/***************************************************************************
  �������ƣ�Pseudographics_dfficulty_3(int choice)
  ��    �ܣ����αͼ���Ѷ�3���֣�ѡ��5-9�����ܵ���Ҫ����
  ���������int choice
  �� �� ֵ����
  ˵    ��������αͼ���е����������������Ҫ����
***************************************************************************/
void Pseudographics_dfficulty_3(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	cct_setfontsize("��������", 16, 8);
	cct_setconsoleborder(185, 56, 185, 56);
	char boomarr_3[18][32] = { 0 };
	char cover_3[18][32] = { 0 };
	char flag_3[18][32] = { 0 };
	char mark_3[18][32] = { 0 };
	int keydown1 = 0;
	int keydown2 = 0;
	int Keydown_ret = 0;
	int Left_boom = Boom_num_3;
	Print_framework_3();
	if (choice == 7 || choice == 8 || choice == 9)
	{
		if (choice == 8)
		{
			cct_gotoxy(0, 0);
			cout << "��Esc�˳�";
		}
		if (choice == 9)
		{
			cct_gotoxy(0, 0);
			cout << "��Esc�˳����ո���ʾʱ��  ";
			cct_setcolor(0, 14);
			cout << "ʣ��������" << setw(2) << Left_boom;
		}
		Print_InitGraph_3();
		Mouse_Operation_3(choice, keydown1, keydown2, flag_3, mark_3, Keydown_ret, Left_boom);
		Print_Leftboom(Left_boom, choice);
		while (Keydown_ret == 2)
		{
			cct_gotoxy(39, 0);
			Endpoint = clock();
			cct_setcolor(0, 14);
			cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
			cct_setcolor(0, 7);
			Keydown_ret = 0;
			Mouse_Operation_3(choice, keydown1, keydown2, flag_3, mark_3, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
		}
		if (Keydown_ret == 1)
		{
			cct_gotoxy(0, 52);
			return;
		}
		cct_gotoxy(39, 0);
		cout << "                   ";
		cct_setcolor(0, 7);
		while (mark_3[keydown1][keydown2] != 0)
		{
			Print_markboom_map_3(mark_3);
			Mouse_Operation_3(choice, keydown1, keydown2, flag_3, mark_3, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
			while (Keydown_ret == 2)
			{
				cct_gotoxy(39, 0);
				Endpoint = clock();
				cct_setcolor(0, 14);
				cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_setcolor(0, 7);
				Keydown_ret = 0;
				Mouse_Operation_3(choice, keydown1, keydown2, flag_3, mark_3, Keydown_ret, Left_boom);
				Print_Leftboom(Left_boom, choice);
			}
			if (Keydown_ret == 1)
			{
				cct_gotoxy(0, 52);
				return;
			}
			cct_gotoxy(39, 0);
			cout << "                   ";
		}
	}
	Reset_markarr_3(mark_3);
	Initarr_3(boomarr_3, keydown1, keydown2, choice);
	if (choice == 5)
		Graph_Output_3(choice, boomarr_3, cover_3, mark_3);
	if (choice == 6)
	{
		Graph_Output_3(choice, boomarr_3, cover_3, mark_3);
		Mouse_Operation_3(choice, keydown1, keydown2, flag_3, mark_3, Keydown_ret, Left_boom);
	}
	if (choice == 7)
	{
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Graph_Output_3(choice, boomarr_3, cover_3, mark_3);
		cct_gotoxy(0, 53);
	}
	if (choice == 8 || choice == 9)
	{
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Graph_Output_3(choice, boomarr_3, cover_3, mark_3);
		Graph_game_3(choice, boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2, Startpoint, Endpoint, Left_boom);
	}
}
/***************************************************************************
  �������ƣ�Graph_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11])
  ��    �ܣ����αͼ���Ѷ�1�Ĵ�ӡ���ܺ���
  ���������int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Graph_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11])
{
	if (choice == 5 || choice == 6)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(7, 7);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				Color_of_Graph(boomarr_1[i][j]);
				cct_setcolor(7, 7);
				cout << "  ";
			}
		}
		cct_gotoxy(0, 31);
	}
	if (choice == 7 || choice == 8 || choice == 9)
	{
		for (int i = 1; i < 10; i++)
		{
			for (int j = 1; j < 10; j++)
			{
				if (cover_1[i][j] == 'X' && mark_1[i][j] != 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(6, 6);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << "    ";
					cct_setcolor(0, 7);
				}
				else if (cover_1[i][j] == 'X' && mark_1[i][j] == 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(12, 4);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					cct_setcolor(12, 7);
					cout << '#';
					cct_setcolor(12, 4);
					cout << "  ";
				}
				else
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(7, 7);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					Color_of_Graph(cover_1[i][j]);
					cct_setcolor(7, 7);
					cout << "  ";
				}
			}
		}
	}
	cct_setcolor(0,7);
}
/***************************************************************************
  �������ƣ�Graph_Output_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char mark_2[18][18])
  ��    �ܣ����αͼ���Ѷ�2�Ĵ�ӡ���ܺ���
  ���������int choice, char boomarr_2[18][18], char cover_2[18][18], char mark_2[18][18]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Graph_Output_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char mark_2[18][18])
{
	if (choice == 5 || choice == 6)
	{
		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 17; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(7, 7);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				Color_of_Graph(boomarr_2[i][j]);
				cct_setcolor(7, 7);
				cout << "  ";
			}
		}
		cct_gotoxy(0, 31);
	}
	if (choice == 7 || choice == 8 || choice == 9)
	{
		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 17; j++)
			{
				if (cover_2[i][j] == 'X' && mark_2[i][j] != 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(6, 6);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << "    ";
					cct_setcolor(0, 7);
				}
				else if (cover_2[i][j] == 'X' && mark_2[i][j] == 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(12, 4);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					cct_setcolor(12, 7);
					cout << '#';
					cct_setcolor(12, 4);
					cout << "  ";
				}
				else
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(7, 7);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					Color_of_Graph(cover_2[i][j]);
					cct_setcolor(7, 7);
					cout << "  ";
				}
			}
		}
	}
	cct_setcolor(0, 7);
}
/***************************************************************************
  �������ƣ�Graph_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32])
  ��    �ܣ����αͼ���Ѷ�3�Ĵ�ӡ���ܺ���
  ���������int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32]
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Graph_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32])
{
	if (choice == 5 || choice == 6)
	{
		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 31; j++)
			{
				cct_gotoxy(6 * j - 2, 3 * i);
				cct_setcolor(7, 7);
				cout << "    ";
				cct_gotoxy(6 * j - 2, 3 * i + 1);
				cout << " ";
				Color_of_Graph(boomarr_3[i][j]);
				cct_setcolor(7, 7);
				cout << "  ";
			}
		}
		cct_gotoxy(0, 31);
	}
	if (choice == 7 || choice == 8 || choice == 9)
	{
		for (int i = 1; i < 17; i++)
		{
			for (int j = 1; j < 31; j++)
			{
				if (cover_3[i][j] == 'X' && mark_3[i][j] != 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(6, 6);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << "    ";
					cct_setcolor(0, 7);
				}
				else if (cover_3[i][j] == 'X' && mark_3[i][j] == 1)
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(12, 4);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					cct_setcolor(12, 7);
					cout << '#';
					cct_setcolor(12, 4);
					cout << "  ";
				}
				else
				{
					cct_gotoxy(6 * j - 2, 3 * i);
					cct_setcolor(7, 7);
					cout << "    ";
					cct_gotoxy(6 * j - 2, 3 * i + 1);
					cout << " ";
					Color_of_Graph(cover_3[i][j]);
					cct_setcolor(7, 7);
					cout << "  ";
				}
			}
		}
	}
	cct_setcolor(0, 7);
}
/***************************************************************************
  �������ƣ�Mouse_Operation_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11], int& Keydown_ret, int& Left_boom)
  ��    �ܣ����αͼ���Ѷ�1����깦�ܺ���
  ���������int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11], int& Keydown_ret, int& Left_boom
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Mouse_Operation_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11], int& Keydown_ret, int& Left_boom)
{
	bool loop = 1;
	int X = 0, Y = 0;
	int Event, Maction;
	int keycode1, keycode2;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		Event = cct_read_keyboard_and_mouse(X, Y, Maction, keycode1, keycode2);
		if (Event == CCT_MOUSE_EVENT)
		{
			cct_gotoxy(0, 30);
			bool Legical = false;
			cout << "[��ǰ���]";
			switch (Maction)
			{
			case MOUSE_ONLY_MOVED:
				for (int i = 1; i < 10; i++)
				{
					for (int j = 1; j < 10; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							Legical = true;
							char ch = 'A';
							cout << " " << (char)(ch + i - 1) << "��" << j - 1 << "�� ";
							break;
						}
					}
				}
				if (!Legical)
					cout << " λ�÷Ƿ�";
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				for (int i = 1; i < 10; i++)
				{
					for (int j = 1; j < 10; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							if (choice == 6)
							{
								loop = false;
								cct_gotoxy(0, 31);
								break;
							}
							keydown1 = i;
							keydown2 = j;
							if (mark_1[keydown1][keydown2] != 1)
								Legical = true;
							if (mark_1[keydown1][keydown2] == 2)
								mark_1[keydown1][keydown2] = 0;
						}
					}
				}
				if (Legical)
					loop = 0;
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (choice == 8 || choice == 9)
				{
					for (int i = 1; i < 10; i++)
					{
						for (int j = 1; j < 10; j++)
						{
							if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
							{
								Legical = true;
								keydown1 = i;
								keydown2 = j;
								if (flag_1[i][j] == 0 && mark_1[i][j] != 1)
								{
									mark_1[i][j] = 1;
									Left_boom--;
								}
								else if (mark_1[i][j] == 1)
								{
									mark_1[i][j] = 2;
									Left_boom++;
								}
							}
						}
					}
				}
				if (Legical)
					loop = 0;
				break;
			default:
				break;
			}
		}
		else if ((choice == 8 || choice == 9) && Event == CCT_KEYBOARD_EVENT)
		{
			if (keycode1 == 27)
			{
				loop = 0;
				Keydown_ret = 1;
				cct_gotoxy(0, 31);
				break;
			}
			if (keycode1 == 32 && choice == 9)
			{
				loop = 0;
				Keydown_ret = 2;
				break;
			}
		}
	}
	cct_disable_mouse();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/***************************************************************************
  �������ƣ�Mouse_Operation_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18], int& Keydown_ret, int& Left_boom)
  ��    �ܣ����αͼ���Ѷ�2����깦�ܺ���
  ���������int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18], int& Keydown_ret, int& Left_boom
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Mouse_Operation_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18], int& Keydown_ret, int& Left_boom)
{
	bool loop = 1;
	int X = 0, Y = 0;
	int Event, Maction;
	int keycode1, keycode2;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		Event = cct_read_keyboard_and_mouse(X, Y, Maction, keycode1, keycode2);
		if (Event == CCT_MOUSE_EVENT)
		{
			cct_gotoxy(0, 51);
			bool Legical = false;
			cout << "[��ǰ���]";
			switch (Maction)
			{
			case MOUSE_ONLY_MOVED:
				for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 17; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							Legical = true;
							char ch = 'A';
							cout << " " << (char)(ch + i - 1) << "��" << j - 1 << "�� ";
							break;
						}
					}
				}
				if (!Legical)
					cout << " λ�÷Ƿ�";
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 17; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							if (choice == 6)
							{
								loop = false;
								break;
							}
							keydown1 = i;
							keydown2 = j;
							if (mark_2[keydown1][keydown2] != 1)
								Legical = true;
							if (mark_2[keydown1][keydown2] == 2)
								mark_2[keydown1][keydown2] = 0;
						}
					}
				}
				if (Legical)
					loop = 0;
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (choice == 8 || choice == 9)
				{
					for (int i = 1; i < 17; i++)
					{
						for (int j = 1; j < 17; j++)
						{
							if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
							{
								Legical = true;
								keydown1 = i;
								keydown2 = j;
								if (flag_2[i][j] == 0 && mark_2[i][j] != 1)
								{
									mark_2[i][j] = 1;
									Left_boom--;
								}
								else if (mark_2[i][j] == 1)
								{
									mark_2[i][j] = 2;
									Left_boom++;
								}
							}
						}
					}
				}
				if (Legical)
					loop = 0;
				break;
			default:
				break;
			}
		}
		else if ((choice == 8 || choice == 9) && Event == CCT_KEYBOARD_EVENT)
		{
			if (keycode1 == 27)
			{
				loop = 0;
				Keydown_ret = 1;
				break;
			}
			if (keycode1 == 32 && choice == 9)
			{
				loop = 0;
				Keydown_ret = 2;
				break;
			}
		}
	}
	cct_disable_mouse();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/***************************************************************************
  �������ƣ�Mouse_Operation_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32], int& Keydown_ret, int& Left_boom)
  ��    �ܣ����αͼ���Ѷ�3����깦�ܺ���
  ���������int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32], int& Keydown_ret, int& Left_boom
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Mouse_Operation_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32], int& Keydown_ret, int& Left_boom)
{
	bool loop = 1;
	int X = 0, Y = 0;
	int Event, Maction;
	int keycode1, keycode2;
	cct_enable_mouse();
	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		Event = cct_read_keyboard_and_mouse(X, Y, Maction, keycode1, keycode2);
		if (Event == CCT_MOUSE_EVENT)
		{
			cct_gotoxy(0, 51);
			bool Legical = false;
			cout << "[��ǰ���]";
			switch (Maction)
			{
			case MOUSE_ONLY_MOVED:
				for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 31; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							Legical = true;
							char ch = 'A';
							cout << " " << (char)(ch + i - 1) << "��" << j - 1 << "�� ";
							break;
						}
					}
				}
				if (!Legical)
					cout << " λ�÷Ƿ�";
				break;
			case MOUSE_LEFT_BUTTON_CLICK:
				for (int i = 1; i < 17; i++)
				{
					for (int j = 1; j < 31; j++)
					{
						if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
						{
							if (choice == 6)
							{
								loop = false;
								break;
							}
							keydown1 = i;
							keydown2 = j;
							if (mark_3[keydown1][keydown2] != 1)
								Legical = true;
							if (mark_3[keydown1][keydown2] == 2)
								mark_3[keydown1][keydown2] = 0;
						}
					}
				}
				if (Legical)
					loop = 0;
				break;
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (choice == 8 || choice == 9)
				{
					for (int i = 1; i < 17; i++)
					{
						for (int j = 1; j < 31; j++)
						{
							if (X >= 6 * j - 2 && X <= 6 * j + 1 && Y >= 3 * i && Y <= 3 * i + 1)
							{
								Legical = true;
								keydown1 = i;
								keydown2 = j;
								if (flag_3[i][j] == 0 && mark_3[i][j] != 1)
								{
									mark_3[i][j] = 1;
									Left_boom--;
								}
								else if (mark_3[i][j] == 1)
								{
									mark_3[i][j] = 2;
									Left_boom++;
								}
							}
						}
					}
				}
				if (Legical)
					loop = 0;
				break;
			default:
				break;
			}
		}
		else if ((choice == 8 || choice == 9) && Event == CCT_KEYBOARD_EVENT)
		{
			if (keycode1 == 27)
			{
				loop = 0;
				Keydown_ret = 1;
				break;
			}
			if (keycode1 == 32 && choice == 9)
			{
				loop = 0;
				Keydown_ret = 2;
				break;
			}
		}
	}
	cct_disable_mouse();
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
}
/***************************************************************************
  �������ƣ�Graph_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom)
  ��    �ܣ����αͼ���Ѷ�1ѡ��8-9��ɨ����Ϸ�Ĺ���
  ���������int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Graph_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom)
{
	int Keydown_ret = 0;
	while (boomarr_1[keydown1][keydown2] != '*' || mark_1[keydown1][keydown2] != 0)
	{
		Mouse_Operation_1(choice, keydown1, keydown2, flag_1, mark_1, Keydown_ret, Left_boom);
		Print_Leftboom(Left_boom, choice);
		while (Keydown_ret == 2)
		{
			cct_gotoxy(39, 0);
			Endpoint = clock();
			cct_setcolor(0, 14);
			cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
			cct_setcolor(0, 7);
			Keydown_ret = 0;
			Mouse_Operation_1(choice, keydown1, keydown2, flag_1, mark_1, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom,choice);
		}
		if (Keydown_ret == 1)
		{
			cct_gotoxy(0, 31);
			return;
		}
		cct_gotoxy(39, 0);
		cout << "                   ";
		Point_Operation_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Graph_Output_1(choice, boomarr_1, cover_1, mark_1);
		bool Judge = Judge_win_1(boomarr_1, cover_1);
		if (Judge)
		{
			cct_setcolor(0, 14);
			cct_gotoxy(0, 30);
			cout << "��ϲʤ������Ϸ����  ";
			cct_setcolor(0, 7);
			if (choice == 9)
			{
				Endpoint = clock();
				cct_setcolor(0, 14);
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_gotoxy(35, 0);
				cout << setw(2) << 0 << " ";
				cct_setcolor(0, 7);
				cct_gotoxy(0, 31);
			}
			break;
		}
		if (cover_1[keydown1][keydown2] == '*')
		{
			cct_gotoxy(0, 30);
			cct_setcolor(0, 14);
			cout << "�����ˣ���Ϸ����  ";
			cct_setcolor(0, 7);
			if (choice == 9)
			{
				cct_setcolor(0, 14);
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_setcolor(0, 7);
				cct_gotoxy(0, 31);
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Graph_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom)
  ��    �ܣ����αͼ���Ѷ�2ѡ��8-9��ɨ����Ϸ�Ĺ���
  ���������int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Graph_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom)
{
	int Keydown_ret = 0;
	while (boomarr_2[keydown1][keydown2] != '*' || mark_2[keydown1][keydown2] != 0)
	{
		Mouse_Operation_2(choice, keydown1, keydown2, flag_2, mark_2, Keydown_ret, Left_boom);
		Print_Leftboom(Left_boom, choice);
		while (Keydown_ret == 2)
		{
			cct_gotoxy(39, 0);
			Endpoint = clock();
			cct_setcolor(0, 14);
			cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
			cct_setcolor(0, 7);
			Keydown_ret = 0;
			Mouse_Operation_2(choice, keydown1, keydown2, flag_2, mark_2, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
		}
		if (Keydown_ret == 1)
		{
			cct_gotoxy(0, 52);
			return;
		}
		cct_gotoxy(39, 0);
		cout << "                   ";
		Point_Operation_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Graph_Output_2(choice, boomarr_2, cover_2, mark_2);
		bool Judge = Judge_win_2(boomarr_2, cover_2);
		if (Judge)
		{
			cct_gotoxy(0, 51);
			cct_setcolor(0, 14);
			cout << "��ϲʤ������Ϸ����  ";
			cct_setcolor(0, 7);
			if (choice == 9)
			{
				Endpoint = clock();
				cct_setcolor(0, 14);
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_gotoxy(35, 0);
				cout << setw(2) << 0 << " ";
				cct_setcolor(0, 7);
				cct_gotoxy(0, 52);
			}
			break;
		}
		if (cover_2[keydown1][keydown2] == '*')
		{
			cct_gotoxy(0, 51);
			cct_setcolor(0, 14);
			cout << "�����ˣ���Ϸ����  ";
			cct_setcolor(0, 7);
			if (choice == 9)
			{
				cct_setcolor(0, 14);
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_setcolor(0, 7);
				cct_gotoxy(0, 52);
			}
		}
	}
}
/***************************************************************************
  �������ƣ�Graph_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom)
  ��    �ܣ����αͼ���Ѷ�3ѡ��8-9��ɨ����Ϸ�Ĺ���
  ���������int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Graph_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint, int& Left_boom)
{
	int Keydown_ret = 0;
	while (boomarr_3[keydown1][keydown2] != '*' || mark_3[keydown1][keydown2] != 0)
	{
		Mouse_Operation_3(choice, keydown1, keydown2, flag_3, mark_3, Keydown_ret, Left_boom);
		Print_Leftboom(Left_boom, choice);
		while (Keydown_ret == 2)
		{
			cct_gotoxy(39, 0);
			Endpoint = clock();
			cct_setcolor(0, 14);
			cout << "��ǰʱ��:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
			cct_setcolor(0, 7);
			Keydown_ret = 0;
			Mouse_Operation_3(choice, keydown1, keydown2, flag_3, mark_3, Keydown_ret, Left_boom);
			Print_Leftboom(Left_boom, choice);
		}
		if (Keydown_ret == 1)
		{
			cct_gotoxy(0, 52);
			return;
		}
		cct_gotoxy(39, 0);
		cout << "                   ";
		Point_Operation_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Graph_Output_3(choice, boomarr_3, cover_3, mark_3);
		bool Judge = Judge_win_3(boomarr_3, cover_3);
		if (Judge)
		{
			cct_gotoxy(0, 51);
			cct_setcolor(0, 14);
			cout << "��ϲʤ������Ϸ����  ";
			cct_setcolor(0, 7);
			if (choice == 9)
			{
				Endpoint = clock();
				cct_setcolor(0, 14);
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_gotoxy(35, 0);
				cout << setw(2) << 0 << " ";
				cct_setcolor(0, 7);
				cct_gotoxy(0, 52);
			}
			break;
		}
		if (cover_3[keydown1][keydown2] == '*')
		{
			cct_gotoxy(0, 51);
			cct_setcolor(0, 14);
			cout << "�����ˣ���Ϸ����  ";
			cct_setcolor(0, 7);
			if (choice == 9)
			{
				Endpoint = clock();
				cct_setcolor(0, 14);
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��";
				cct_setcolor(0, 7);
				cct_gotoxy(0, 52);
			}
		}
	}
}