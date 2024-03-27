/*2253744 �־��� ��*/
#include "mine_sweeper.h"
/***************************************************************************
  �������ƣ�Print_specification()
  ��    �ܣ���ӡ4ѡ���еĸ�����������˵��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_specification()
{
	cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
	cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
	cout << "              # - ȡ�����      (����#E3)" << endl;
	cout << "�����루����������к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
}
/***************************************************************************
  �������ƣ�Print_InitArray_1()
  ��    �ܣ���ӡ3.4ѡ����Ϸ�տ�ʼ������
  �����������
  �� �� ֵ����
  ˵    ����һ��ʼ�����̶��ǡ�X��
***************************************************************************/
void Print_InitArray_1()
{
	for (int i = 1; i < 10; i++)
	{
		char alph = 64;
		cout << char(alph + i) << " |";
		cout << "X X X X X X X X X" << endl;
	}
	cout << endl << endl;
}
/***************************************************************************
  �������ƣ�Print_InitArray_2()
  ��    �ܣ���ӡ3.4ѡ����Ϸ�տ�ʼ������
  �����������
  �� �� ֵ����
  ˵    ����һ��ʼ�����̶��ǡ�X��
***************************************************************************/
void Print_InitArray_2()
{
	for (int i = 1; i < 17; i++)
	{
		char alph = 64;
		cout << (char)(alph + i) << " |";
		cout << "X X X X X X X X X X X X X X X X" << endl;
	}
	cout << endl << endl;
}
/***************************************************************************
  �������ƣ�Print_InitArray_3()
  ��    �ܣ���ӡ3.4ѡ����Ϸ�տ�ʼ������
  �����������
  �� �� ֵ����
  ˵    ����һ��ʼ�����̶��ǡ�X��
***************************************************************************/
void Print_InitArray_3()
{
	for (int i = 1; i < 17; i++)
	{
		char alph = 64;
		cout << (char)(alph + i) << " |";
		cout << "X X X X X X X X X X X X X X X X X X X X X X X X X X X X X X" << endl;
	}
	cout << endl << endl;
}
/***************************************************************************
  �������ƣ�Color_of_Inner(char ch)
  ��    �ܣ���ӡ�򿪺�ÿ�����Ӧ�������͸����ֵ���ɫ
  ���������char ch
  �� �� ֵ����
  ˵    ����������ͬ��������ɫҲ�ǲ�һ����
***************************************************************************/
void Color_of_Inner(char ch)
{
	switch (ch)
	{
	case '0':
		cct_setcolor(14, 0);
		break;
	case '1':
		cct_setcolor(14, 1);
		break;
	case '2':
		cct_setcolor(14, 2);
		break;
	case '3':
		cct_setcolor(14, 3);
		break;
	case '4':
		cct_setcolor(14, 4);
		break;
	case '5':
		cct_setcolor(14, 5);
		break;
	case '6':
		cct_setcolor(14, 6);
		break;
	case '7':
		cct_setcolor(14, 7);
		break;
	case '8':
		cct_setcolor(14, 8);
		break;
	case 'X':
		cct_setcolor(0, 7);
		break;
	case '*':
		cct_setcolor(0, 7);
		break;
	}
	cout << ch;
	cct_setcolor(0, 7);
	cout << " ";
}
/***************************************************************************
  �������ƣ�Inner_difficulty_1(int choice)
  ��    �ܣ�����ڲ������Ѷ�1���֣�ѡ��1-4�����ܵ���Ҫ����
  ���������ѡ��choice
  �� �� ֵ����
  ˵    ���������ڲ������е����������������Ҫ����
***************************************************************************/
void Inner_difficulty_1(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	char boomarr_1[11][11] = { 0 };		//��ʵ��������
	char cover_1[11][11] = { 0 };		//��������ĸ�������
	char flag_1[11][11] = { 0 };		//�ж�ĳ�����Ƿ񡰴򿪡�������
	char mark_1[11][11] = { 0 };		//���Ϊ�׵�����
	int keydown1 = 0;
	int keydown2 = 0;
	cout << "�ڲ����飺" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9" << endl;
	cout << "--+--------------------" << endl;
	if (choice == 2 || choice == 3)
	{
		Print_InitArray_1();
		cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (choice == 4)
	{
		Print_InitArray_1();
		Print_specification();
		Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			Print_specification();
			Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (mark_1[keydown1][keydown2] != 0)
		{
			cout << "��ǰ���飺" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9" << endl;
			cout << "--+--------------------" << endl;
			for (int i = 1; i < 10; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j < 10; j++)
				{
					if (mark_1[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << " ";
					}
					else
						cout << 'X' << " ";
				}
				cout << endl;
			}
			cout << endl << endl;
			Print_specification();
			Input_1(choice, keydown1, keydown2, flag_1, mark_1);
			while (keydown1 == '&')
			{
				Endpoint = clock();
				cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
				Print_specification();
				Input_1(choice, keydown1, keydown2, flag_1, mark_1);
			}
			if (keydown1 == 'q' || keydown1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
		}
	}
	Reset_markarr_1(mark_1);
	Initarr_1(boomarr_1, keydown1, keydown2, choice);
	if (choice == 1)
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
	if (choice == 2)
	{
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
	}
	if (choice == 3 || choice == 4)
	{
		Expand_map_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
		Inner_game_1(choice, boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2, Startpoint, Endpoint);
	}
}
/***************************************************************************
  �������ƣ�Inner_difficulty_2(int choice)
  ��    �ܣ�����ڲ������Ѷ�2���֣�ѡ��1-4�����ܵ���Ҫ����
  ���������ѡ��choice
  �� �� ֵ����
  ˵    ���������ڲ������е����������������Ҫ����
***************************************************************************/
void Inner_difficulty_2(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	char boomarr_2[18][18] = { 0 };			//��ʵ��������
	char cover_2[18][18] = { 0 };			//��������ĸ�������
	char flag_2[18][18] = { 0 };			//�ж�ĳ�����Ƿ񡰴򿪡�������
	char mark_2[18][18] = { 0 };			//���Ϊ�׵�����
	int keydown1 = 0;
	int keydown2 = 0;
	cout << "�ڲ����飺" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl;
	cout << "--+----------------------------------" << endl;
	if (choice == 2 || choice == 3)
	{
		Print_InitArray_2();
		cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (choice == 4)
	{
		Print_InitArray_2();
		Print_specification();
		Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			Print_specification();
			Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (mark_2[keydown1][keydown2] != 0)
		{
			cout << "��ǰ���飺" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl;
			cout << "--+----------------------------------" << endl;
			for (int i = 1; i < 17; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j < 17; j++)
				{
					if (mark_2[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << ' ';
					}
					else
						cout << 'X' << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
			Print_specification();
			Input_2(choice, keydown1, keydown2, flag_2, mark_2);
			while (keydown1 == '&')
			{
				Endpoint = clock();
				cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
				Print_specification();
				Input_2(choice, keydown1, keydown2, flag_2, mark_2);
			}
			if (keydown1 == 'q' || keydown1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
		}
	}
	Reset_markarr_2(mark_2);
	Initarr_2(boomarr_2, keydown1, keydown2, choice);
	if (choice == 1)
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
	if (choice == 2)
	{
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
	}
	if (choice == 3 || choice == 4)
	{
		Expand_map_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
		Inner_game_2(choice, boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2, Startpoint, Endpoint);
	}
}
/***************************************************************************
  �������ƣ�Inner_difficulty_3(int choice)
  ��    �ܣ�����ڲ������Ѷ�3���֣�ѡ��1-4�����ܵ���Ҫ����
  ���������ѡ��choice
  �� �� ֵ����
  ˵    ���������ڲ������е����������������Ҫ����
***************************************************************************/
void Inner_difficulty_3(int choice)
{
	clock_t Startpoint, Endpoint;
	Startpoint = Endpoint = clock();
	char boomarr_3[18][32] = { 0 };			//��ʵ��������
	char cover_3[18][32] = { 0 };			//��������ĸ�������	
	char flag_3[18][32] = { 0 };			//�ж�ĳ�����Ƿ񡰴򿪡�������
	char mark_3[18][32] = { 0 };			//���Ϊ�׵�����
	int keydown1 = 0;
	int keydown2 = 0;
	cout << "�ڲ����飺" << endl;
	cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl;
	cout << "--+--------------------------------------------------------------" << endl;
	if (choice == 2 || choice == 3)
	{
		Print_InitArray_3();
		cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
	}
	if (choice == 4)
	{
		Print_InitArray_3();
		Print_specification();
		Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			Print_specification();
			Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		while (mark_3[keydown1][keydown2] != 0)
		{
			cout << "��ǰ���飺" << endl;
			cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl;
			cout << "--+--------------------------------------------------------------" << endl;
			for (int i = 1; i < 17; i++)
			{
				char alph = 64;
				cout << (char)(alph + i) << " |";
				for (int j = 1; j < 31; j++)
				{
					if (mark_3[i][j] == 1)
					{
						cct_setcolor(4, 7);
						cout << 'X';
						cct_setcolor(0, 7);
						cout << ' ';
					}
					else
						cout << 'X' << ' ';
				}
				cout << endl;
			}
			cout << endl << endl;
			Print_specification();
			Input_3(choice, keydown1, keydown2, flag_3, mark_3);
			while (keydown1 == '&')
			{
				Endpoint = clock();
				cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
				Print_specification();
				Input_3(choice, keydown1, keydown2, flag_3, mark_3);
			}
			if (keydown1 == 'q' || keydown1 == 'Q')
			{
				cout << endl;
				return;
			}
			cout << endl << endl;
		}
	}
	Reset_markarr_3(mark_3);
	Initarr_3(boomarr_3, keydown1, keydown2, choice);
	if (choice == 1)
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
	if (choice == 2)
	{
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
	}
	if (choice == 3 || choice == 4)
	{
		Expand_map_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
		Inner_game_3(choice, boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2, Startpoint, Endpoint);
	}
}
/***************************************************************************
  �������ƣ�Input_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11])
  ��    �ܣ�����ڲ������Ѷ�1�������빦�ܵ���Ҫ����
  ���������int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11]
  �� �� ֵ����
  ˵    ����choice����ͬѡ�����Ų�ͬ���������4��������ࣩ���������ܸı�flag_1��mark_1������Ǻ󲻻��ٱ����򿪡����ʸ�λ�õ�flag_1��mark_1��仯��
***************************************************************************/
void Input_1(int choice, int& keydown1, int& keydown2, char flag_1[11][11], char mark_1[11][11])
{
	while (1)
	{
		keydown1 = _getch();
		if (choice == 4)
		{
			if (keydown1 == '&')
			{
				putchar('&');
				return;
			}
			if (keydown1 == '!')
			{
				putchar('!');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'I')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
				}
				if (flag_1[keydown1][keydown2] == 0)
					mark_1[keydown1][keydown2] = 1;
				return;
			}
			if (keydown1 == '#')
			{
				putchar('#');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'I')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
				}
				if (flag_1[keydown1][keydown2] == 0 || flag_1[keydown1][keydown2] == 1 && mark_1[keydown1][keydown2] == 1)
					mark_1[keydown1][keydown2] = 2;
				return;
			}
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << (char)(keydown1);
			return;
		}
		if (keydown1 >= 'A' && keydown1 <= 'I')
		{
			cout << (char)(keydown1);
			keydown1 = keydown1 - 64;
			break;
		}
	}
	while (1)
	{
		keydown2 = _getch();
		if (keydown2 >= '1' && keydown2 <= '9')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 48;
			break;
		}
	}
	if (mark_1[keydown1][keydown2] == 2)
		mark_1[keydown1][keydown2] = 0;
}
/***************************************************************************
  �������ƣ�Input_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18])
  ��    �ܣ�����ڲ������Ѷ�2�������빦�ܵ���Ҫ����
  ���������int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18]
  �� �� ֵ����
  ˵    ����choice����ͬѡ�����Ų�ͬ���������4��������ࣩ���������ܸı�flag_1��mark_1������Ǻ󲻻��ٱ����򿪡����ʸ�λ�õ�flag_1��mark_1��仯��
***************************************************************************/
void Input_2(int choice, int& keydown1, int& keydown2, char flag_2[18][18], char mark_2[18][18])
{
	while (1)
	{
		keydown1 = _getch();
		if (choice == 4)
		{
			if (keydown1 == '&')
			{
				putchar('&');
				return;
			}
			if (keydown1 == '!')
			{
				putchar('!');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'g')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_2[keydown1][keydown2] == 0)
					mark_2[keydown1][keydown2] = 1;
				return;
			}
			if (keydown1 == '#')
			{
				putchar('#');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'g')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_2[keydown1][keydown2] == 0 || flag_2[keydown1][keydown2] == 1 && mark_2[keydown1][keydown2] == 1)
					mark_2[keydown1][keydown2] = 2;
				return;
			}
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << (char)(keydown1);
			return;
		}
		if (keydown1 >= 'A' && keydown1 <= 'P')
		{
			cout << (char)(keydown1);
			keydown1 = keydown1 - 64;
			break;
		}
	}
	while (1)
	{
		keydown2 = _getch();
		if (keydown2 >= '1' && keydown2 <= '9')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 48;
			break;
		}
		if (keydown2 >= 'a' && keydown2 <= 'g')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 87;
			break;
		}
	}
	if (mark_2[keydown1][keydown2] == 2)
		mark_2[keydown1][keydown2] = 0;
}
/***************************************************************************
  �������ƣ�Input_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32])
  ��    �ܣ�����ڲ������Ѷ�3�������빦�ܵ���Ҫ����
  ���������int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32]
  �� �� ֵ����
  ˵    ����choice����ͬѡ�����Ų�ͬ���������4��������ࣩ���������ܸı�flag_1��mark_1������Ǻ󲻻��ٱ����򿪡����ʸ�λ�õ�flag_1��mark_1��仯��
***************************************************************************/
void Input_3(int choice, int& keydown1, int& keydown2, char flag_3[18][32], char mark_3[18][32])
{
	while (1)
	{
		keydown1 = _getch();
		if (choice == 4)
		{
			if (keydown1 == '&')
			{
				putchar('&');
				return;
			}
			if (keydown1 == '!')
			{
				putchar('!');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'u')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_3[keydown1][keydown2] == 0)
					mark_3[keydown1][keydown2] = 1;
				return;
			}
			if (keydown1 == '#')
			{
				putchar('#');
				while (1)
				{
					keydown1 = _getch();
					if (keydown1 >= 'A' && keydown1 <= 'P')
					{
						cout << (char)(keydown1);
						keydown1 = keydown1 - 64;
						break;
					}
				}
				while (1)
				{
					keydown2 = _getch();
					if (keydown2 >= '1' && keydown2 <= '9')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 48;
						break;
					}
					if (keydown2 >= 'a' && keydown2 <= 'u')
					{
						cout << (char)(keydown2);
						keydown2 = keydown2 - 87;
						break;
					}
				}
				if (flag_3[keydown1][keydown2] == 0 || flag_3[keydown1][keydown2] == 1 && mark_3[keydown1][keydown2] == 1)
					mark_3[keydown1][keydown2] = 2;
				return;
			}
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << (char)(keydown1);
			return;
		}
		if (keydown1 >= 'A' && keydown1 <= 'P')
		{
			cout << (char)(keydown1);
			keydown1 = keydown1 - 64;
			break;
		}
	}
	while (1)
	{
		keydown2 = _getch();
		if (keydown2 >= '1' && keydown2 <= '9')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 48;
			break;
		}
		if (keydown2 >= 'a' && keydown2 <= 'u')
		{
			cout << (char)(keydown2);
			keydown2 = keydown2 - 87;
			break;
		}
	}
	if (mark_3[keydown1][keydown2] == 2)
		mark_3[keydown1][keydown2] = 0;
}
/***************************************************************************
  �������ƣ�Inner_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11])
  ��    �ܣ�����ڲ������Ѷ�1����������ܵ���Ҫ����
  ���������int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11]
  �� �� ֵ����
  ˵    ���������Ҫע�⵽������Ƿ񱻱�ǡ����׻��Ƿ���
***************************************************************************/
void Inner_Output_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char mark_1[11][11])
{
	if (choice == 1)
	{
		for (int i = 1; i < 10; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 10; j++)
				cout << boomarr_1[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;
	}
	if (choice == 2 || choice == 3 || choice == 4)
	{
		if (choice == 2)
			cout << "�㿪������飺" << endl;
		if (choice == 3 || choice == 4)
			cout << "��ǰ���飺" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9" << endl << "--+--------------------" << endl;
		for (int i = 1; i < 10; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 10; j++)
			{
				if (mark_1[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << cover_1[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
				else
					Color_of_Inner(cover_1[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
/***************************************************************************
  �������ƣ�Inner_Output_2(int choice, char boomarr_2[18][18],char cover_2[18][18], char mark_2[18][18])
  ��    �ܣ�����ڲ������Ѷ�2����������ܵ���Ҫ����
  ���������int choice, char boomarr_2[18][18],char cover_2[18][18], char mark_2[18][18]
  �� �� ֵ����
  ˵    ���������Ҫע�⵽������Ƿ񱻱�ǡ����׻��Ƿ���
***************************************************************************/
void Inner_Output_2(int choice, char boomarr_2[18][18],char cover_2[18][18], char mark_2[18][18])
{
	if (choice == 1)
	{
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 17; j++)
				cout << boomarr_2[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;
	}
	if (choice == 2 || choice == 3 || choice == 4)
	{
		if (choice == 2)
			cout << "�㿪������飺" << endl;
		if (choice == 3 || choice == 4)
			cout << "��ǰ���飺" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g" << endl << "--+---------------------------------" << endl;
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 17; j++)
			{
				if (mark_2[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << cover_2[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
				else
					Color_of_Inner(cover_2[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
/***************************************************************************
  �������ƣ�Inner_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32])
  ��    �ܣ�����ڲ������Ѷ�3����������ܵ���Ҫ����
  ���������int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32]
  �� �� ֵ����
  ˵    ���������Ҫע�⵽������Ƿ񱻱�ǡ����׻��Ƿ���
***************************************************************************/
void Inner_Output_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char mark_3[18][32])
{
	if (choice == 1)
	{
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 31; j++)
				cout << boomarr_3[i][j] << " ";
			cout << endl;
		}
		cout << endl << endl;
	}
	if (choice == 2 || choice == 3 || choice == 4)
	{
		if (choice == 2)
			cout << "�㿪������飺" << endl;
		if (choice == 3 || choice == 4)
			cout << "��ǰ���飺" << endl;
		cout << "  |1 2 3 4 5 6 7 8 9 a b c d e f g h i j k l m n o p q r s t u" << endl << "--+--------------------------------------------------------------" << endl;
		for (int i = 1; i < 17; i++)
		{
			int alph = 64;
			cout << (char)(alph + i) << " |";
			for (int j = 1; j < 31; j++)
			{
				if (mark_3[i][j] == 1)
				{
					cct_setcolor(4, 7);
					cout << cover_3[i][j];
					cct_setcolor(0, 7);
					cout << " ";
				}
				else
					Color_of_Inner(cover_3[i][j]);
			}
			cout << endl;
		}
		cout << endl << endl;
	}
}
/***************************************************************************
  �������ƣ�Inner_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
  ��    �ܣ�����ڲ������Ѷ�1����3.4ѡ��ѭ��ɨ����Ϸ���ܵ���Ҫ����
  ���������int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Inner_game_1(int choice, char boomarr_1[11][11], char cover_1[11][11], char flag_1[11][11], char mark_1[11][11], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
{
	while (boomarr_1[keydown1][keydown2] != '*' || mark_1[keydown1][keydown2] != 0)
	{
		if (choice == 3)
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		if (choice == 4)
			Print_specification();
		Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			Print_specification();
			Input_1(choice, keydown1, keydown2, flag_1, mark_1);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		Point_Operation_1(boomarr_1, cover_1, flag_1, mark_1, keydown1, keydown2);
		Inner_Output_1(choice, boomarr_1, cover_1, mark_1);
		bool Judge = Judge_win_1(boomarr_1, cover_1);
		if(Judge)
		{
			cout << "��ϲʤ������Ϸ����" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			}
			break;
		}
		if (cover_1[keydown1][keydown2] == '*')
		{
			cout << "�����ˣ���Ϸ����" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			}
		}	
	}
}
/***************************************************************************
  �������ƣ�Inner_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
  ��    �ܣ�����ڲ������Ѷ�2����3.4ѡ��ѭ��ɨ����Ϸ���ܵ���Ҫ����
  ���������int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Inner_game_2(int choice, char boomarr_2[18][18], char cover_2[18][18], char flag_2[18][18], char mark_2[18][18], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
{
	while (boomarr_2[keydown1][keydown2] != '*' || mark_2[keydown1][keydown2] != 0)
	{
		if (choice == 3)
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		if (choice == 4)
			Print_specification();
		Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			Print_specification();
			Input_2(choice, keydown1, keydown2, flag_2, mark_2);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		Point_Operation_2(boomarr_2, cover_2, flag_2, mark_2, keydown1, keydown2);
		Inner_Output_2(choice, boomarr_2, cover_2, mark_2);
		bool Judge = Judge_win_2(boomarr_2, cover_2);
		if (Judge)
		{
			cout << "��ϲʤ������Ϸ����" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			}
			break;
		}
		if (cover_2[keydown1][keydown2] == '*')
		{
			cout << "�����ˣ���Ϸ����" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			}
		}	
	}
}
/***************************************************************************
  �������ƣ�Inner_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
  ��    �ܣ�����ڲ������Ѷ�3����3.4ѡ��ѭ��ɨ����Ϸ���ܵ���Ҫ����
  ���������int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Inner_game_3(int choice, char boomarr_3[18][32], char cover_3[18][32], char flag_3[18][32], char mark_3[18][32], int keydown1, int keydown2, clock_t Startpoint, clock_t Endpoint)
{
	while (boomarr_3[keydown1][keydown2] != '*' || mark_3[keydown1][keydown2] != 0)
	{
		if (choice == 3)
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1/Af����Q/q�˳�����";
		if (choice == 4)
			Print_specification();
		Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		while (keydown1 == '&')
		{
			Endpoint = clock();
			cout << endl << "������ʱ�䣺" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			Print_specification();
			Input_3(choice, keydown1, keydown2, flag_3, mark_3);
		}
		if (keydown1 == 'q' || keydown1 == 'Q')
		{
			cout << endl;
			return;
		}
		cout << endl << endl;
		Point_Operation_3(boomarr_3, cover_3, flag_3, mark_3, keydown1, keydown2);
		Inner_Output_3(choice, boomarr_3, cover_3, mark_3);
		bool Judge = Judge_win_3(boomarr_3, cover_3);
		if (Judge)
		{
			cout << "��ϲʤ������Ϸ����" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			}
			break;
		}
		if (cover_3[keydown1][keydown2] == '*') 
		{
			cout << "�����ˣ���Ϸ����" << endl;
			if (choice == 4)
			{
				Endpoint = clock();
				cout << "����ʱ:" << (double)(Endpoint - Startpoint) / CLOCKS_PER_SEC << "��" << endl;
			}
		}	
	}
}