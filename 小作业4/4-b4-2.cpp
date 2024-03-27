/*2253744 �־��� ��*/
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
char menu(const HANDLE hout);
char move_by_ijkl(const HANDLE hout, int key, int x, int y);
char move_by_arrow(const HANDLE hout, int key, int x, int y);
char move_by_ijkl_plus(const HANDLE hout, int key, int x, int y);
/***************************************************************************
  �������ƣ�menu����
  ��    �ܣ���ӡѡ��˵����Ҷ�ȡ���������ѡ���������
  ���������const HANDLE hout
  �� �� ֵ������ѡ�񷵻�ֵ
  ˵    ������
***************************************************************************/
char menu(const HANDLE hout)
{
	char keydown;
	while (1)
	{
		cls(hout);
		cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)" << endl;
		cout << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)" << endl;
		cout << "3.�ü�ͷ�������������ң��߽�ֹͣ" << endl;
		cout << "4.�ü�ͷ�������������ң��߽����" << endl;
		cout << "5.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ),�����ͷʱ��׼�����ƶ�" << endl;
		cout << "6.��I��J��K��L��������������(��Сд���ɣ��߽����),�����ͷʱ��׼�����ƶ�" << endl;
		cout << "[��ѡ��0-6] ";
		keydown = _getch();
		if (keydown >= '0' && keydown <= '6')
		{
			if (keydown == '0')
			{
				putchar(keydown);
			}
			break;
		}
	}
	return keydown;
}
/***************************************************************************
  �������ƣ�main����
  ��    �ܣ�����������߼����
  �����������
  �� �� ֵ��0
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const int init_x = 35;
	const int init_y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	/*��ʼ�������*/
	while (1)
	{
		char keydown;/*keydown����˵��ķ���ֵ*/
		int key;/*keyΪ1ʱ��ʾ�߽�ֹͣ��keyΪ0ʱ��ʾ�߽绷��*/
		keydown = menu(hout);
		if (keydown == '0')
		{
			break;
		}
		cls(hout);
		init_border(hout);
		gotoxy(hout, init_x, init_y);
		int x = init_x;
		int y = init_y;
		char back;
		switch (keydown)
		{
		case'1':
			key = 1;
			back = move_by_ijkl(hout, key, x, y);
			if (back == 'Q')
			{
				continue;
			}
			break;
		case'2':
			key = 0;
			back = move_by_ijkl(hout, key, x, y);
			if (back == 'Q')
			{
				continue;
			}
			break;
		case'3':
			key = 1;
			back = move_by_arrow(hout, key, x, y);
			if (back == 'Q')
			{
				continue;
			}
			break;
		case'4':
			key = 0;
			back = move_by_arrow(hout, key, x, y);
			if (back == 'Q')
			{
				continue;
			}
			break;
		case'5':
			key = 1;
			back = move_by_ijkl_plus(hout, key, x, y);
			if (back == 'Q')
			{
				continue;
			}
			break;
		case'6':
			key = 0;
			back = move_by_ijkl_plus(hout, key, x, y);
			if (back == 'Q')
			{
				continue;
			}
			break;
		}
		break;
	}
	return 0;
}
/***************************************************************************
  �������ƣ�move_by_ijkl����
  ��    �ܣ�ʵ��1.2ѡ��Ĺ���
  ���������const HANDLE hout, int key, int x, int y
  �� �� ֵ��һ���ַ�
  ˵    ������
***************************************************************************/
char move_by_ijkl(const HANDLE hout, int key, int x, int y)
{
	while (1)
	{
		char choice = _getch();
		switch (choice)
		{
		case 'I':
		case 'i':
			if (y > 1)
			{
				y--;
			}
			else if (y == 1 && key == 0)
			{
				y = MAX_Y;
			}
			gotoxy(hout, x, y);
			break;
		case 'J':
		case 'j':
			if (x > 1)
			{
				x--;
			}
			else if (x == 1 && key == 0)
			{
				x = MAX_X;
			}
			gotoxy(hout, x, y);
			break;
		case 'K':
		case 'k':
			if (y < MAX_Y)
			{
				y++;
			}
			else if (y == MAX_Y && key == 0)
			{
				y = 1;
			}
			gotoxy(hout, x, y);
			break;
		case 'L':
		case 'l':
			if (x < MAX_X)
			{
				x++;
			}
			else if (x == MAX_X && key == 0)
			{
				x = 1;
			}
			gotoxy(hout, x, y);
			break;
		}
		if (choice == ' ')
		{
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}
		if (choice == 'Q' || choice == 'q')
		{
			gotoxy(hout, 0, 23);
			printf("��Ϸ���������س������ز˵�.");
			while (1)
			{
				int enter = _getch();
				if (enter == 13)
					break;
			}
			return 'Q';
		}
	}
}
/***************************************************************************
  �������ƣ�move_by_arrow����
  ��    �ܣ�ʵ��3.4ѡ��Ĺ���
  ���������const HANDLE hout, int key, int x, int y
  �� �� ֵ��һ���ַ�
  ˵    ������
***************************************************************************/
char move_by_arrow(const HANDLE hout, int key, int x, int y)
{
	while (1)
	{
		int firstbyte = _getch();
		if (firstbyte == 224)
		{
			int choice = _getch();
			switch (choice)
			{
			case 72:
				if (y > 1)
				{
					y--;
				}
				else if (y == 1 && key == 0)
				{
					y = MAX_Y;
				}
				gotoxy(hout, x, y);
				break;
			case 75:
				if (x > 1)
				{
					x--;
				}
				else if (x == 1 && key == 0)
				{
					x = MAX_X;
				}
				gotoxy(hout, x, y);
				break;
			case 80:
				if (y < MAX_Y)
				{
					y++;
				}
				else if (y == MAX_Y && key == 0)
				{
					y = 0;
				}
				gotoxy(hout, x, y);
				break;
			case 77:
				if (x < MAX_X)
				{
					x++;
				}
				else if (x == MAX_X && key == 0)
				{
					x = 0;
				}
				gotoxy(hout, x, y);
				break;
			}
		}
		if (firstbyte == ' ')
		{
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}
		if (firstbyte == 'Q' || firstbyte == 'q')
		{
			gotoxy(hout, 0, 23);
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int enter = _getch();
				if (enter == 13)
					break;
			}
			return 'Q';
		}
	}
}
/***************************************************************************
  �������ƣ�move_by_ijkl_plus����
  ��    �ܣ�ʵ��5.6ѡ��Ĺ���
  ���������const HANDLE hout, int key, int x, int y
  �� �� ֵ��һ���ַ�
  ˵    ������
***************************************************************************/
char move_by_ijkl_plus(const HANDLE hout, int key, int x, int y)
{
	while (1)
	{
		char choice = _getch();
		if (choice == 75)
		{
			int temp = _getch();
			continue;
		}
		switch (choice)
		{
		case 'I':
		case 'i':
			if (y > 1)
			{
				y--;
			}
			else if (y == 1 && key == 0)
			{
				y = MAX_Y;
			}
			gotoxy(hout, x, y);
			break;
		case 'J':
		case 'j':
			if (x > 1)
			{
				x--;
			}
			else if (x == 1 && key == 0)
			{
				x = MAX_X;
			}
			gotoxy(hout, x, y);
			break;
		case 'K':
		case 'k':
			if (y < MAX_Y)
			{
				y++;
			}
			else if (y == MAX_Y && key == 0)
			{
				y = 1;
			}
			gotoxy(hout, x, y);
			break;
		case 'L':
		case 'l':
			if (x < MAX_X)
			{
				x++;
			}
			else if (x == MAX_X && key == 0)
			{
				x = 1;
			}
			gotoxy(hout, x, y);
			break;
		}
		if (choice == ' ')
		{
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}
		if (choice == 'Q' || choice == 'q')
		{
			gotoxy(hout, 0, 23);
			cout << "��Ϸ���������س������ز˵�.";
			while (1)
			{
				int enter = _getch();
				if (enter == 13)
					break;
			}
			return 'Q';
		}
	}
}
/*
* ˼��1���������������Ϊ�����ʵ���������뻺�����ڷ���2�����룬��һ���ĵõ�����224��0����ʱ��ѭ���ڲ����κβ�������ʱ���뻺�����Ļ�ʣ��
* ����������µ�75���ڶ��εõ��ı���75�������ö�Ӧ��ASCII���е�'K'��������ѡ���ж���'K'��Ӧ���������ƶ�����˴���ִ���������ƶ���
* ˼��2��init_border���������ʾ�ַ���ԭ��������20������x��y������ͨ��gotoxy��λ��������������ɵ��ַ�λ���ظ�ʱ���ڶ���putchar�Ľ��
* �Ὣ��һ��putchar�Ľ�����ǣ��ַ����ͻ�����20
*/