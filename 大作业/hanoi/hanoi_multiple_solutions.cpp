/*2253744 �־��� ��*/
#include "hanoi.h"
using namespace std;
static int speed;
static int movecount;
static int A_stack[10], B_stack[10], C_stack[10];
static int A_top, B_top, C_top;
/* ----------------------------------------------------------------------------------

     ���ļ����ܣ�
    1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

     ���ļ�Ҫ��
    1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
    2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
    3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
    4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
   /***************************************************************************
     �������ƣ�Reset()
     ��    �ܣ���ʼ����̬ȫ�ֱ���
     �����������
     �� �� ֵ����
     ˵    ������ÿһ������ǰ�����ƶ�����Movement��ʼ��Ϊ1������ջ��������ջ�����ݳ�ʼ��Ϊ0
   ***************************************************************************/
void Reset()
{
    movecount = 1;
    A_top = B_top = C_top = 0;
    for (int i = 0; i < 10; i++)
        A_stack[i] = B_stack[i] = C_stack[i] = 0;
}
/***************************************************************************
     �������ƣ�Time_Sleep(int speed)
     ��    �ܣ�������ʱ����
     �����������ʱ����ѡ��speed
     �� �� ֵ����
     ˵    ������speedΪ0ʱ���س�������ʾ��1��ʱ���5��ʱ���
   ***************************************************************************/
void Time_Sleep(int speed)
{
    if (speed)
        Sleep(Time / speed);
    else
        while (getchar() != '\n');
}
/***************************************************************************
     �������ƣ�Input(char* src, char* tmp, char* dst, int* n, int speed_flag)
     ��    �ܣ�ȷ����ŵ������������������ȷ���Ƿ�ʹ����ʱ������������
     �����������ŵ����������ʼ����Ŀ��������ʱ��־
     �� �� ֵ����
     ˵    ������speed_flagΪ-1ʱ��ʾ��ʹ����ʱ����
   ***************************************************************************/
void Input(char* src, char* tmp, char* dst, int* n, int speed_flag)
{
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
        cin >> *n;
        if (cin.good() == 0 || *n < 1 || *n > 10)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        break;
    }
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> *src;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (*src >= 'a' && *src <= 'c')
            *src -= 32;
        if (*src > 'C' || *src < 'A')
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> *dst;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (*dst >= 'a' && *dst <= 'c')
            *dst -= 32;
        if (*dst > 'C' || *dst < 'A')
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (*dst == *src)
        {
            cout << "Ŀ����(" << *dst << ")��������ʼ��(" << *src << ")��ͬ" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    *tmp = 'B' * 3 - *src - *dst;
    if (speed_flag)
    {
        while (1)
        {
            cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���) ";
            cin >> speed;
            if (cin.good() == 0 || speed > 5 || speed < 0)
            {
                cin.clear();
                cin.ignore(1024, '\n');
                continue;
            }
            cin.clear();
            cin.ignore(1024, '\n');
            break;
        }
    }
}
/***************************************************************************
     �������ƣ�Init(int n, char src)
     ��    �ܣ���ʼ����ʼ��
     �����������ŵ����������ʼ��
     �� �� ֵ����
     ˵    ��������ʼ���Ķ�Ӧջ��Ԫ�س�ʼΪ��Ӧ��
   ***************************************************************************/
void Init(int n, char src)
{
    if (src == 'A')
    {
        while (A_top < n)
            A_stack[A_top++] = n - A_top;
    }
    else if (src == 'B')
    {
        while (B_top < n)
            B_stack[B_top++] = n - B_top;
    }
    else if (src == 'C')
    {
        while (C_top < n)
            C_stack[C_top++] = n - C_top;
    }
}
/***************************************************************************
     �������ƣ�Hanoi_Stack(char src, char dst)
     ��    �ܣ�ʵ��Ԫ���ں�ŵ����ջ����ƶ�
     ����������˲��ƶ�����ʼ����Ŀ����
     �� �� ֵ����
     ˵    ����ͨ��ջ�ĳ�ջ��ջ����ʵ�ֺ�ŵ������ջ��Ԫ�صĻ����ƶ�
   ***************************************************************************/
void Hanoi_Stack(char src, char dst)
{
    int element = 0;
    if (src == 'A' && A_top > 0)
    {
        element = A_stack[--A_top];
        A_stack[A_top] = 0;
    }
    else if (src == 'B' && B_top > 0)
    {
        element = B_stack[--B_top];
        B_stack[B_top] = 0;
    }
    else if (src == 'C' && C_top > 0)
    {
        element = C_stack[--C_top];
        C_stack[C_top] = 0;
    }
    if (dst == 'A' && A_top < 10)
        A_stack[A_top++] = element;
    else if (dst == 'B' && B_top < 10)
        B_stack[B_top++] = element;
    else if (dst == 'C' && C_top < 10)
        C_stack[C_top++] = element;
}
/***************************************************************************
     �������ƣ�Print_Bottom(int x,int y)
     ��    �ܣ���ӡѡ��4�еĵ���
     �����������������������x,y
     �� �� ֵ����
     ˵    �����������ϴ���ҵ�Ĵ�ӡ���̣�����ʼλ�øı伴��
   ***************************************************************************/
void Print_Bottom(int x, int y)
{
    cct_gotoxy(x, y);
    cout << "         =========================" << endl;
    cout << "           A         B         C";
}
/***************************************************************************
     �������ƣ�Print_Crosswise(int x, int y)
     ��    �ܣ������ӡ��ŵ�������Ԫ��
     �����������ŵ�������ӡ�����λ������
     �� �� ֵ����
     ˵    �����������ϴ���ҵ�ĺ����ӡ���飬����ʼλ�øı伴��
   ***************************************************************************/
void Print_Crosswise(int x, int y)
{
    cct_gotoxy(x, y);
    cout << " A:";
    for (int i = 0; i < 10; i++)
    {
        if (A_stack[i])
            cout << setw(2) << A_stack[i];
        else
            cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if (B_stack[i])
            cout << setw(2) << B_stack[i];
        else
            cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if (C_stack[i])
            cout << setw(2) << C_stack[i];
        else
            cout << "  ";
    }
    cout << endl;
}
/***************************************************************************
  �������ƣ�Print_Vertical(char src, char dst, int init, int bottom_x, int bottom_y, int x, int y)
  ��    �ܣ������ӡ��ŵ�������Ԫ��
  �����������ʼ����Ŀ�������Ƿ��ʼ��״̬�����̵�x��y����ʹ�ӡ���������x��y����
  �� �� ֵ����
  ˵    ����initΪ1�Ǳ�ʾ��ʼ��״̬����ʱ��ӡ��ʼ�����������ݼ���
***************************************************************************/
void Print_Vertical(char src, char dst, int init, int bottom_x, int bottom_y, int x, int y)
{
    Print_Bottom(bottom_x, bottom_y);
    if (init)
    {
        for (int i = 0; i < A_top; i++)
        {
            cct_gotoxy(x, y - i);
            if (A_stack[i])
                cout << setw(2) << A_stack[i];
        }
        for (int i = 0; i < B_top; i++)
        {
            cct_gotoxy(x + 10, y - i);
            if (B_stack[i])
                cout << setw(2) << B_stack[i];
        }
        for (int i = 0; i < C_top; i++)
        {
            cct_gotoxy(x + 20, y - i);
            if (C_stack[i])
                cout << setw(2) << C_stack[i];
        }
    }
    else
    {
        if (src == 'A')
        {
            cct_gotoxy(x, y - A_top);
            cout << "  ";
        }
        else if (src == 'B')
        {
            cct_gotoxy(x + 10, y - B_top);
            cout << "  ";
        }
        else if (src == 'C')
        {
            cct_gotoxy(x + 20, y - C_top);
            cout << "  ";
        }
        if (dst == 'A')
        {
            cct_gotoxy(x, y + 1 - A_top);
            cout << setw(2) << A_stack[A_top - 1];
        }
        else if (dst == 'B')
        {
            cct_gotoxy(x + 10, y + 1 - B_top);
            cout << setw(2) << B_stack[B_top - 1];
        }
        else if (dst == 'C')
        {
            cct_gotoxy(x + 20, y + 1 - C_top);
            cout << setw(2) << C_stack[C_top - 1];
        }
    }
}
/***************************************************************************
  �������ƣ�Print_Column()
  ��    �ܣ����ѡ��5�е�Ԥ��������Բ��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_Column()
{
    cct_setcursor(CURSOR_INVISIBLE);
    const int Column_Color = COLOR_HYELLOW;
    cct_showch(Base_X, Base_Y, ' ', Column_Color, Column_Color, 23);
    cct_showch(Base_X + Base_Distance, Base_Y, ' ', Column_Color, Column_Color, 23);
    cct_showch(Base_X + 2 * Base_Distance, Base_Y, ' ', Column_Color, Column_Color, 23);
    for (int i = 0; i < Column_Height; i++)
    {
        cct_showch(A_Base_Middle, Base_Y - 1 - i, ' ', Column_Color, Column_Color, 1);
        Sleep(50);
        cct_showch(B_Base_Middle, Base_Y - 1 - i, ' ', Column_Color, Column_Color, 1);
        Sleep(50);
        cct_showch(C_Base_Middle, Base_Y - 1 - i, ' ', Column_Color, Column_Color, 1);
        Sleep(50);
    }
}
/***************************************************************************
  �������ƣ�Print_Plate(int n, char src)
  ��    �ܣ����ѡ��6�е�����ʼ���ϻ�n�����ӵ�Ҫ��
  �����������ŵ����������ʼ��
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Print_Plate(int n, char src)
{
    int Plate_Base_x;
    int Plate_Base_y = Base_Y;
    if (src == 'A')
        Plate_Base_x = A_Base_Middle;
    else if (src == 'B')
        Plate_Base_x = B_Base_Middle;
    else
        Plate_Base_x = C_Base_Middle;
    for (int i = n; i > 0; i--)
    {
        cct_showch(Plate_Base_x - i, Plate_Base_y - 1 + i - n, ' ', i, i, 2 * i + 1);
        Sleep(30);
    }
}
/***************************************************************************
  �������ƣ�Move_Vertical_Up(char src, int speed)
  ��    �ܣ�������ӵĴ�ֱ�����ƶ�
  �����������ʼ�����ƶ��ٶ�����
  �� �� ֵ����
  ˵    ����Length_Flag�������̵���ʵ����,����ÿ���̵ĳ��ȱ�־,�����2��1
***************************************************************************/
void Move_Vertical_Up(char src, int speed)
{
    int Origin_X, Start_Location, Length_Flag;
    if (src == 'A')
    {
        Origin_X = A_Base_Middle;
        Start_Location = A_top;
        Length_Flag = A_stack[A_top - 1];
    }
    else if (src == 'B')
    {
        Origin_X = B_Base_Middle;
        Start_Location = B_top;
        Length_Flag = B_stack[B_top - 1];
    }
    else
    {
        Origin_X = C_Base_Middle;
        Start_Location = C_top;
        Length_Flag = C_stack[C_top - 1];
    }
    for (int i = Base_Y - Start_Location; i > 0; i--)
    {
        cct_showch(Origin_X - Length_Flag, i, ' ', Length_Flag, Length_Flag, 2 * Length_Flag + 1);
        Sleep(Time / speed);
        if (i <= Base_Y - Start_Location)
        {
            cct_showch(Origin_X - Length_Flag, i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * Length_Flag + 1);
            if (i > 2)
                cct_showch(Origin_X, i, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        } 
    }
}
/***************************************************************************
  �������ƣ�Move_Crosswise(char src, char dst, int speed)
  ��    �ܣ�������ӵ�ˮƽ������ƶ�
  �����������ʼ����Ŀ�������ƶ��ٶ�����
  �� �� ֵ����
  ˵    ������Ҫ������ʼ����Ŀ���������λ�����������ƺ�����
***************************************************************************/
void Move_Crosswise(char src, char dst, int speed)
{
    int Src_X, Dst_X, Length_Flag;
    if (src == 'A')
    {
        Src_X = A_Base_Middle;
        Length_Flag = A_stack[A_top - 1];
    }
    else if(src == 'B')
    {
        Src_X = B_Base_Middle;
        Length_Flag = B_stack[B_top - 1];
    }
    else
    {
        Src_X = C_Base_Middle;
        Length_Flag = C_stack[C_top - 1];
    }
    if (dst == 'A')
        Dst_X = A_Base_Middle;
    else if (dst == 'B')
        Dst_X = B_Base_Middle;
    else
        Dst_X = C_Base_Middle;
    if (src < dst)
    {
        for (int i = Src_X - Length_Flag; i <= Dst_X - Length_Flag; i++)
        {
            cct_showch(i, 1, ' ', Length_Flag, Length_Flag, 2 * Length_Flag + 1);
            Sleep(Time / speed);
            if (i < Dst_X - Length_Flag)
                cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_WHITE, 2 * Length_Flag + 1);
        }
    }
    else
    {
        for (int i = Src_X - Length_Flag; i >= Dst_X - Length_Flag; i--)
        {
            cct_showch(i, 1, ' ', Length_Flag, Length_Flag, 2 * Length_Flag + 1);
            Sleep(Time / speed);
            if (i > Dst_X - Length_Flag)
                cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_WHITE, 2 * Length_Flag + 1);
        }
    }
}
/***************************************************************************
  �������ƣ�Move_Vertical_Down(char src, char dst, int speed)
  ��    �ܣ�������ӵĴ�ֱ���µ��ƶ�
  �����������ʼ����Ŀ�������ƶ��ٶ�����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Move_Vertical_Down(char src, char dst, int speed)
{
    int Origin_X, End_Location, Length_Flag;
    if (src == 'A')
        Length_Flag = A_stack[A_top - 1];
    else if (src == 'B')
        Length_Flag = B_stack[B_top - 1];
    else
        Length_Flag = C_stack[C_top - 1];
    if (dst == 'A')
    {
        Origin_X = A_Base_Middle;
        End_Location = A_top;
    }
    else if (dst == 'B')
    {
        Origin_X = B_Base_Middle;
        End_Location = B_top;
    }
    else
    {
        Origin_X = C_Base_Middle;
        End_Location = C_top;
    }
    for (int i = 1; i < Base_Y - End_Location; i++)
    {
        cct_showch(Origin_X - Length_Flag, i, ' ', Length_Flag, Length_Flag, 2 * Length_Flag + 1);
        Sleep(Time / speed);
        if (i < Base_Y - End_Location - 1)
        {
            cct_showch(Origin_X - Length_Flag, i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * Length_Flag + 1);
            if (i > 2)
                cct_showch(Origin_X, i, ' ', COLOR_HYELLOW, COLOR_HYELLOW, 1);
        }
    }
}
/***************************************************************************
  �������ƣ�Move_Plate(char src, char dst, int speed)
  ��    �ܣ�������ӵ��ƶ�����
  �����������ʼ����Ŀ�������ƶ��ٶ�����
  �� �� ֵ����
  ˵    �������speedΪ0������Ӧ�Ű��س�������ʾ����ʱ���ǽ�speed��ֵ�ֶ���Ϊ10
***************************************************************************/
void Move_Plate(char src, char dst, int speed)
{
    if (!speed)
        speed = 10;
    Move_Vertical_Up(src, speed);
    Move_Crosswise(src, dst, speed);
    Move_Vertical_Down(src, dst, speed);
}
/***************************************************************************
  �������ƣ�Hanoi_Game(int n, char dst)
  ��    �ܣ���ŵ����Ϸ��ѡ��9����ʵ��
  �����������ŵ��������Ŀ����
  �� �� ֵ����
  ˵    �������ͨ���ж�Ŀ�����Ķ��Ƿ�Ϊ��1���ж���Ϸ�Ƿ����
***************************************************************************/
void Hanoi_Game(int n, char dst)
{
    char Input_src, Input_dst;
    int Get_element, Endbase_element;
    while (1)
    {
        cct_gotoxy(0, 34);
        cout << "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��";
        cct_showch(60, 34, ' ', COLOR_BLACK, COLOR_WHITE, 10);
        cct_gotoxy(60, 34);
        Input_src = getchar();
        if (Input_src == '\n')
            continue;
        if (cin.good() == 0 || (Input_src != 'A' && Input_src != 'B' && Input_src != 'C' && Input_src != 'Q' && Input_src != 'a' && Input_src != 'b' && Input_src != 'c' && Input_src != 'q'))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        Input_dst = getchar();
        if ((Input_src == 'Q' || Input_src == 'q') && Input_dst == '\n')
        {
            cout << "��Ϸ��ֹ!!!!!" << endl << endl;
            break;
        }
        if (cin.good() == 0 || (Input_dst != 'A' && Input_dst != 'B' && Input_dst != 'C' && Input_dst != 'a' && Input_dst != 'b' && Input_dst != 'c'))
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        char Judge = getchar();
        if (Judge != '\n')
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (Input_src >= 'a' && Input_src <= 'z')
            Input_src -= 32;
        if (Input_dst >= 'a' && Input_dst <= 'z')
            Input_dst -= 32;
        if (Input_src == Input_dst)
            continue;
        if (Input_src == 'A' && A_top > 0)
            Get_element = A_stack[A_top - 1];
        else if(Input_src == 'B' && B_top > 0)
            Get_element = B_stack[B_top - 1];
        else if (Input_src == 'C' && C_top > 0)
            Get_element = C_stack[C_top - 1];
        else
        {
            cct_showstr(0, 35, "Դ��Ϊ��!", COLOR_BLACK, COLOR_WHITE, 1);
            Sleep(2 * Time);
            cct_showstr(0, 35, "         ", COLOR_BLACK, COLOR_WHITE, 1);
            continue;
        }
        if (Input_dst == 'A' && A_top > 0)
            Endbase_element = A_stack[A_top - 1];
        else if (Input_dst == 'B' && B_top > 0)
            Endbase_element = B_stack[B_top - 1];
        else if (Input_dst == 'C' && C_top > 0)
            Endbase_element = C_stack[C_top - 1];
        else
            Endbase_element = 11;
        if (Get_element > Endbase_element)
        {
            cct_showstr(0, 35, "����ѹС�̣��Ƿ��ƶ�!", COLOR_BLACK, COLOR_WHITE, 1);
            Sleep(2 * Time);
            cct_showstr(0, 35, "                     ", COLOR_BLACK, COLOR_WHITE, 1);
            continue;
        }
        int x, y;
        cct_gotoxy(0, 32);
        cout << "��" << setw(4) << movecount++ << " ��( " << Get_element << "#: " << Input_src << "-->" << Input_dst << ")  ";
        Hanoi_Stack(Input_src, Input_dst);
        cct_getxy(x, y);
        Print_Crosswise(x, y);
        Print_Vertical(Input_src, Input_dst, 0, 0, 27, 10, 26);
        Hanoi_Stack(Input_dst, Input_src);
        Move_Plate(Input_src, Input_dst, 10);
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        Hanoi_Stack(Input_src, Input_dst);
        int Final_Plate;
        if (dst == 'A')
            Final_Plate = A_stack[n - 1];
        else if(dst =='B')
            Final_Plate = B_stack[n - 1];
        else
            Final_Plate = C_stack[n - 1];
        if (Final_Plate == 1)
        {
            cct_showstr(0, 35, "��Ϸ����!!!!!", COLOR_BLACK, COLOR_WHITE, 1);
            break;
        }
    }
}
/***************************************************************************
  �������ƣ�Operation(char src, char tmp, char dst, int n, int speed, int choice)
  ��    �ܣ����ѡ��1��2��3��4��7��8���ڵݹ�����еĸ����ӡ����
  �����������ʼ�����м�����Ŀ��������ŵ���������ٶ����úͲ˵�ѡ��
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void Operation(char src, char tmp, char dst, int n, int speed, int choice)
{
    if (choice == 1)
        cout << n << "# " << src << "---->" << dst << endl;
    else if (choice == 2)
        cout << "��" << setw(4) << movecount++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")" << endl;
    else if (choice == 3)
    {
        int x, y;
        cout << "��" << setw(4) << movecount++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        Hanoi_Stack(src, dst);
        cct_getxy(x, y);
        Print_Crosswise(x, y);
    }
    else if (choice == 4)
    {
        cct_gotoxy(0, 17);
        cout << "��" << setw(4) << movecount++ << " ��(" << setw(2) << n << "#: " << src << "-->" << dst << ")";
        Hanoi_Stack(src, dst);
        Print_Crosswise(22, 17);
        Print_Vertical(src, dst, 0, 0, 12, 10, 11);
        Time_Sleep(speed);
    }
    else if (choice == 7)
    {
        Move_Plate(src, dst, 10);
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    }
    else if (choice == 8)
    {
        int x, y;
        cct_gotoxy(0, 32);
        cout << "��" << setw(4) << movecount++ << " ��( " << n << "#: " << src << "-->" << dst << ")  ";
        Hanoi_Stack(src, dst);
        cct_getxy(x, y);
        Print_Crosswise(x, y);
        Print_Vertical(src, dst, 0, 0, 27, 10, 26);
        Hanoi_Stack(dst, src);
        Move_Plate(src, dst, speed);
        Hanoi_Stack(src, dst);
        cct_setcolor(COLOR_BLACK, COLOR_WHITE);
        Time_Sleep(speed);
    }
}
/***************************************************************************
  �������ƣ�Hanoi(char src, char tmp, char dst, int n, int speed, int choice)
  ��    �ܣ���ŵ���ݹ�������
  �����������ʼ�����м�����Ŀ��������ŵ���������ٶ����úͲ˵�ѡ��
  �� �� ֵ����
  ˵    ������ѡ��7��ֻ��ʾ��һ���ƶ����裬�ʵ�choice == 7����һ��������ֱ��return
***************************************************************************/
void Hanoi(char src, char tmp, char dst, int n, int speed, int choice)
{
    if (n == 1)
        Operation(src, tmp, dst, n, speed, choice);
    else
    {
        Hanoi(src, dst, tmp, n - 1, speed, choice);
        if (choice == 7)
            return;
        Operation(src, tmp, dst, n, speed, choice);
        Hanoi(tmp, src, dst, n - 1, speed, choice);
    }
}
/***************************************************************************
  �������ƣ�Choice_1()��Choice_2()��Choice_3()��Choice_4()��Choice_5()��Choice_6()��Choice_7()��Choice_8()��Choice_9()
  ��    �ܣ����ÿһ���˵�ѡ��Ĺ���
  �����������
  �� �� ֵ����
  ˵    �������¾Ÿ������ֱ��Ӧ�Ų˵��ľŸ�����ѡ�ÿһ�����������վ���Ҫ������������϶���
***************************************************************************/
void Choice_1()
{
    char src, tmp, dst;
    int n;
    Input(&src, &tmp, &dst, &n, 0);
    Hanoi(src, tmp, dst, n, -1, 1);
}
void Choice_2()
{
    char src, tmp, dst;
    int n;
    Reset();
    Input(&src, &tmp, &dst, &n, 0);
    Hanoi(src, tmp, dst, n, -1, 2);
}
void Choice_3()
{
    char src, tmp, dst;
    int n;
    Reset();
    Input(&src, &tmp, &dst, &n, 0);
    Init(n, src);
    Hanoi(src, tmp, dst, n, -1, 3);
}
void Choice_4()
{
    char src, tmp, dst;
    int n;
    Reset();
    Input(&src, &tmp, &dst, &n, 1);
    Init(n, src);
    cct_setcursor(CURSOR_INVISIBLE);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << endl;
    cct_gotoxy(0, 17);
    cout << "��ʼ:  ";
    int x, y;
    cct_getxy(x, y);
    Print_Crosswise(x, y);
    Print_Vertical(src, dst, 1, 0, 12, 10, 11);
    Time_Sleep(speed);
    Hanoi(src, tmp, dst, n, speed, 4);
}
void Choice_5()
{
    cct_cls();
    Print_Column();
}
void Choice_6()
{
    char src, tmp, dst;
    int n;
    Reset();
    Input(&src, &tmp, &dst, &n, 0);
    Init(n, src);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
    Print_Column();
    Print_Plate(n, src);
}
void Choice_7()
{
    char src, tmp, dst;
    int n;
    Reset();
    Input(&src, &tmp, &dst, &n, 0);
    Init(n, src);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
    Print_Column();
    Print_Plate(n, src);
    Sleep(Time);
    Hanoi(src, tmp, dst, n, -1, 7);
}
void Choice_8()
{
    char src, tmp, dst;
    int n, x, y;
    Reset();
    Input(&src, &tmp, &dst, &n, 1);
    Init(n, src);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << endl;
    cct_gotoxy(0, 32);
    cout << "��ʼ:  ";
    cct_getxy(x, y);
    Print_Crosswise(x, y);
    Print_Vertical(src, dst, 1, 0, 27, 10, 26);
    Print_Column();
    Print_Plate(n, src);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    Time_Sleep(speed);
    Sleep(Time);
    Hanoi(src, tmp, dst, n, speed, 8);
}
void Choice_9()
{
    char src, tmp, dst;
    int n, x, y;
    Reset();
    Input(&src, &tmp, &dst, &n, 0);
    Init(n, src);
    cct_cls();
    cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
    cct_gotoxy(0, 32);
    cout << "��ʼ:  ";
    cct_getxy(x, y);
    Print_Crosswise(x, y);
    Print_Vertical(src, dst, 1, 0, 27, 10, 26);
    Print_Column();
    Print_Plate(n, src);
    cct_setcursor(CURSOR_INVISIBLE);
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    Hanoi_Game(n, dst);
}