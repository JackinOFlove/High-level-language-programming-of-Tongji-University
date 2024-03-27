/*2253744 林觉凯 软工*/
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
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

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
char menu(const HANDLE hout);
char move_by_ijkl(const HANDLE hout, int key, int x, int y);
char move_by_arrow(const HANDLE hout, int key, int x, int y);
char move_by_ijkl_plus(const HANDLE hout, int key, int x, int y);
/***************************************************************************
  函数名称：menu函数
  功    能：打印选择菜单并且读取键盘输入的选择键并返回
  输入参数：const HANDLE hout
  返 回 值：键盘选择返回值
  说    明：无
***************************************************************************/
char menu(const HANDLE hout)
{
	char keydown;
	while (1)
	{
		cls(hout);
		cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
		cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
		cout << "3.用箭头键控制上下左右，边界停止" << endl;
		cout << "4.用箭头键控制上下左右，边界回绕" << endl;
		cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止),按左箭头时不准向下移动" << endl;
		cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕),按左箭头时不准向下移动" << endl;
		cout << "[请选择0-6] ";
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
  函数名称：main函数
  功    能：程序的主体逻辑框架
  输入参数：无
  返 回 值：0
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const int init_x = 35;
	const int init_y = 9;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	/*开始进入程序*/
	while (1)
	{
		char keydown;/*keydown储存菜单的返回值*/
		int key;/*key为1时表示边界停止，key为0时表示边界环绕*/
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
  函数名称：move_by_ijkl函数
  功    能：实现1.2选项的功能
  输入参数：const HANDLE hout, int key, int x, int y
  返 回 值：一个字符
  说    明：无
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
			printf("游戏结束，按回车键返回菜单.");
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
  函数名称：move_by_arrow函数
  功    能：实现3.4选项的功能
  输入参数：const HANDLE hout, int key, int x, int y
  返 回 值：一个字符
  说    明：无
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
			cout << "游戏结束，按回车键返回菜单.";
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
  函数名称：move_by_ijkl_plus函数
  功    能：实现5.6选项的功能
  输入参数：const HANDLE hout, int key, int x, int y
  返 回 值：一个字符
  说    明：无
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
			cout << "游戏结束，按回车键返回菜单.";
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
* 思考1：按左键向下是因为按左键实际上在输入缓冲区内放入2个输入，第一个的得到的是224或0，此时在循环内不做任何操作，此时输入缓冲区的还剩下
* 左键输入留下的75，第二次得到的便是75，这正好对应着ASCII码中的'K'，所以在选择判断中'K'对应的是向下移动，因此错误执行了向下移动。
* 思考2：init_border产生随机显示字符的原理是生成20个整数x，y，并且通过gotoxy定位，但当有随机生成的字符位置重复时，第二次putchar的结果
* 会将第一次putchar的结果覆盖，字符数就会少于20
*/