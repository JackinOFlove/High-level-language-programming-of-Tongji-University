/*2253744 �־��� ��*/
#include "hanoi.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

     ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  �������ƣ�main()
  ��    �ܣ����������ò˵������Ӧ��ִ�к���
  �����������
  �� �� ֵ��0
  ˵    ����������������̿��
***************************************************************************/
int main()
{
	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
	cct_setconsoleborder(120, 40, 120, 9000);
	char choice;
	while (1)
	{
		choice = Hanoi_Menu();
		if (choice == '0')
		{
			cct_gotoxy(0, 37);
			return 0;
		}		
		cout << endl << endl;
		switch (choice)
		{
		case '1':
			Choice_1();
			cout << endl;
			break;
		case '2':
			Choice_2();
			cout << endl;
			break;
		case '3':
			Choice_3();
			cout << endl;
			break;
		case '4':
			Choice_4();
			cout << endl;
			break;
		case '5':
			Choice_5();
			break;
		case '6':
			Choice_6();
			break;
		case '7':
			Choice_7();
			break;
		case '8':
			Choice_8();
			break;
		case '9':
			Choice_9();
			break;
		}
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		while (1)
		{
			if (choice >= '1' && choice <= '3')
			{
				int x, y;
				cct_getxy(x, y);
				cct_gotoxy(0, y);
				cct_showstr(0, y, "���س�������", COLOR_BLACK, COLOR_WHITE, 1);
			}
			else
				cct_showstr(0, 38, "���س�������", COLOR_BLACK, COLOR_WHITE, 1);
			char ret = _getch();
			if (ret == '\r')
			{
				cct_cls();
				break;
			}
		}
	}
	return 0;
}