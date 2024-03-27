/*2253744 �־��� ��*/
#include <iostream>
#include <iomanip>
using namespace std;
int top[3] = { 0 };
int stack[3][10] = { 0 };
int num = 1;
void init(int n, char src)
{
    if (src == 'A')
    {
        while (top[0] < n)
        {
            stack[0][top[0]++] = n - top[0];
        }
    }
    else if (src == 'B')
    {
        while (top[1] < n)
        {
            stack[1][top[1]++] = n - top[1];
        }
    }
    else if (src == 'C')
    {
        while (top[2] < n)
        {
            stack[2][top[2]++] = n - top[2];
        }
    }
}
void print()
{
    cout << " " << "A:";
    for (int i = 0; i < 10; i++)
    {
        if (stack[0][i])
        {
            cout << setw(2) << stack[0][i];
        }
        else
        {
            cout << "  ";
        }
    }
    cout << " " << "B:";
    for (int i = 0; i < 10; i++)
    {
        if (stack[1][i])
        {
            cout << setw(2) << stack[1][i];
        }
        else
        {
            cout << "  ";
        }
    }
    cout << " " << "C:";
    for (int i = 0; i < 10; i++)
    {
        if (stack[2][i])
        {
            cout << setw(2) << stack[2][i];
        }
        else
        {
            cout << "  ";
        }
    }
    cout<< endl;
}
void hanoi_stack(char src, char dst)
{
    int element = 0;
    if (src == 'A' && top[0] > 0)
    {
        element = stack[0][--top[0]];
        stack[0][top[0]] = 0;
    }
    else if (src == 'B' && top[1] > 0)
    {
        element = stack[1][--top[1]];
        stack[1][top[1]] = 0;
    }
    else if (src == 'C' && top[2] > 0)
    {
        element = stack[2][--top[2]];
        stack[2][top[2]] = 0;
    }
    if (dst == 'A' && top[0] < 10)
    {
        stack[0][top[0]++] = element;
    }
    else if (dst == 'B' && top[1] < 10)
    {
        stack[1][top[1]++] = element;
    }
    else if (dst == 'C' && top[2] < 10)
    {
        stack[2][top[2]++] = element;
    }
}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n > 1)
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
        hanoi_stack(src, dst);
        print();
        hanoi(n - 1, tmp, src, dst);
    }
    if (n == 1)
    {
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
        hanoi_stack(src, dst);
        print();
    }
}
int main()
{
    int n;
    char src, tmp, dst;
    tmp = ' ';
    while (1)
    {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
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
    while (1)
    {
        cout << "��������ʼ��(A-C)" << endl;
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
    while (1)
    {
        cout << "������Ŀ����(A-C)" << endl;
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
            cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        cin.clear();
        cin.ignore(1024, '\n');
        break;
    }
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
    init(n, src);
    printf("��ʼ:               ");
    print();
    hanoi(n, src, tmp, dst);
	return 0;
}