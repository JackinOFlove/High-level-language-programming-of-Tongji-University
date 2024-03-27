/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "5-b7.h"
#define Time 200
using namespace std;
int A_stack[10] = { 0,0,0,0,0,0,0,0,0,0 };
int B_stack[10] = { 0,0,0,0,0,0,0,0,0,0 };
int C_stack[10] = { 0,0,0,0,0,0,0,0,0,0 };
int A_top = 0;
int B_top = 0;
int C_top = 0;
static int num = 1;
void Init(int n, char src)
{
    if (src == 'A')
    {
        while (A_top < n)
        {
            A_stack[A_top++] = n - A_top;
        }
    }
    else if (src == 'B')
    {
        while (B_top < n)
        {
            B_stack[B_top++] = n - B_top;
        }
    }
    else if (src == 'C')
    {
        while (C_top < n)
        {
            C_stack[C_top++] = n - C_top;
        }
    }
}
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
    {
        A_stack[A_top++] = element;
    }
    else if (dst == 'B' && B_top < 10)
    {
        B_stack[B_top++] = element;
    }
    else if (dst == 'C' && C_top < 10)
    {
        C_stack[C_top++] = element;
    }
}
void Print_Bottom()
{
    cct_gotoxy(0, 20);
    cout << "         =========================" << endl;
    cout << "           A         B         C";
}
void Print_Crosswise()
{
    cout<<" A:";
    for (int i = 0; i < 10; i++)
    {
        if (A_stack[i])
        {
            cout << setw(2) << A_stack[i];
        }
        else
        {
            cout << "  ";
        }
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if (B_stack[i])
        {
            cout << setw(2) << B_stack[i];
        }
        else
        {
            cout << "  ";
        }
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if (C_stack[i])
        {
            cout << setw(2) << C_stack[i];
        }
        else
        {
            cout << "  ";
        }
    }
    printf("\n");
}
void Print_Vertical(char src, char dst, int speed,int init)
{
    Print_Bottom();
    if (init)
    {
        for (int i = 0; i < A_top; i++)
        {
            cct_gotoxy(10, 19 - i);
            if (A_stack[i])
            {
                cout << setw(2) << A_stack[i];
            }
        }
        for (int i = 0; i < B_top; i++)
        {
            cct_gotoxy(20, 19 - i);
            if (B_stack[i])
            {
                cout << setw(2) << B_stack[i];
            }          
        }
        for (int i = 0; i < C_top; i++)
        {
            cct_gotoxy(30, 19 - i);
            if (C_stack[i])
            {
                cout << setw(2) << C_stack[i];
            } 
        }
    }
    else
    {
        if (src == 'A')
        {
            cct_gotoxy(10, 19 - A_top);
            cout << "  ";
        }
        else if (src == 'B')
        {
            cct_gotoxy(20, 19 - B_top);
            cout << "  ";
        }
        else if (src == 'C')
        {
            cct_gotoxy(30, 19 - C_top);
            cout << "  ";
        }
        if (dst == 'A')
        {
            cct_gotoxy(10, 20 - A_top);
            cout << setw(2) << A_stack[A_top - 1];
        }
        else if (dst == 'B')
        {
            cct_gotoxy(20, 20 - B_top);
            cout << setw(2) << B_stack[B_top - 1];
        }
        else if (dst == 'C')
        {
            cct_gotoxy(30, 20 - C_top);
            cout << setw(2) << C_stack[C_top - 1];
        }
    }
    if (speed)
    {
        Sleep(Time * (5-speed));
    }    
    else
    {
        while (getchar() != '\n');
    }
}
void hanoi(int n, char src, char tmp, char dst, int speed, int show)
{
    if (n > 1)
    {
        hanoi(n - 1, src, dst, tmp,speed,show);
        cct_gotoxy(20, 25);
        cout << "第" << setw(4) << num++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        Hanoi_Stack(src, dst);
        if (show)
        {
            cct_gotoxy(40, 25);
            Print_Crosswise();
        }
        Print_Vertical(src, dst, speed,0);
       
        hanoi(n - 1, tmp, src, dst,speed,show);
    }
    if (n == 1)
    {
        cct_gotoxy(20, 25);
        cout << "第" << setw(4) << num++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        Hanoi_Stack(src, dst);
        if (show)
        {
            cct_gotoxy(40, 25);
            Print_Crosswise();
        }
        Print_Vertical(src, dst,speed,0);
        
    }
}
int main()
{
    int n,speed,show;
    char src, tmp, dst;
    tmp = ' ';
    //输入层数
    while (1)
    {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (n < 1 || n > 10)
        {
            continue;
        }
        break;
    }
    //输入起始柱
    while (1)
    {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> src;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (src >= 'a' && src <= 'c')
        {
            src -= 32;
        }
        if (src > 'C' || src < 'A')
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    //输入目标柱
    while (1)
    {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (dst >= 'a' && dst <= 'c')
        {
            dst -= 32;
        }
        if (dst > 'C' || dst < 'A')
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (dst == src)
        {
            cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    //确认三个柱
    if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
    {
        tmp = 'C';
    }
    else if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
    {
        tmp = 'B';
    }
    else
    {
        tmp = 'A';
    }
    //输入移动速度
    while (1)
    {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> speed;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (speed > 6 || speed < 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    //是否显示内部数组
    while (1)
    {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> show;
        if (cin.good() == 0)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (show != 0 && show != 1)
        {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
    Init(n, src);
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed << "，" << (show ? "" : "不") << "显示内部数组值" << endl;
    if (show)
    {
        cct_gotoxy(20, 25);
        cout << "初始:                ";
        Print_Crosswise();
        if (speed)
        {
            Sleep(Time* (5-speed));
        }
        else
        {
            while (getchar() != '\n');
        }
        Print_Vertical(src, dst, speed,1);
    }
    else
    {
        Print_Vertical(src, dst, speed, 1);
    }
    //汉诺塔递归
    hanoi(n, src, tmp, dst, speed, show);
    cct_gotoxy(20, 35);
    system("pause");//最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
    return 0;
}