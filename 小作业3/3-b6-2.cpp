/*2253744 �־��� ��*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "������[0-100��)֮�������:" << endl;
    double a, n;
    cin >> a;
    cout << "��д�����:" << endl;
    int a1, a2, a3, a4;
    a1 = (int)(a / 100000000);
    a2 = (int)(a / 10000 - a1 * 10000);
    a3 = (int)((a / 10000 - a1 * 10000-a2) * 10000+0.001);
	a4 = (int)rint(modf(a, &n) * 100) + 0.001;
    int n1, n2, n3, n4;
	int flag = 0;
    if (a1 != 0)
    {
        n1 = a1 / 10;
        n2 = a1 % 10;
        switch (n1)
        {
        case 0:
            break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
        }
		switch (n2)
		{
		case 0:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
		}
		if (a2==0 && a3==0 && a4==0)
		{
			cout << "Բ��" << endl;
			return 0;
		}
    }
	if (a2 != 0)
	{
		n1 = a2 / 1000;
		n2 = a2 / 100 % 10;
		n3 = a2 / 10 % 10;
		n4 = a2 % 10;
		switch (n1)
		{
		case 0:
			if ((n2 != 0 || n3 != 0 || n4 != 0) && a1 != 0)
			{
				cout << "��";
				flag = 1;
			}
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0) && (n3 != 0 || n4 != 0))
			{
				cout << "��";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0 || n1 != 0||n2!=0)&&n4!=0) || (flag && n2 != 0 && n4 != 0))
			{
				cout << "��";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		}
		switch (n4)
		{
		case 0:
			cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "����";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "����";
			break;
		case 8:
			cout << "����";
			break;
		case 9:
			cout << "����";
			break;
		}
		flag = 0;
		if (a3 == 0 && a4 == 0)
		{
			cout << "Բ��" << endl;
			return 0;
		}
	}
	if (a3 != 0)
	{
		n1 = a3 / 1000;
		n2 = a3 / 100 % 10;
		n3 = a3 / 10 % 10;
		n4 = a3 % 10;
		switch (n1)
		{
		case 0:
			if ((n2 != 0 || n3 != 0 || n4 != 0) && (a1 != 0||a2 != 0))
			{
				cout << "��";
				flag = 1;
			}
			break;
		case 1:
			cout << "ҼǪ";
			break;
		case 2:
			cout << "��Ǫ";
			break;
		case 3:
			cout << "��Ǫ";
			break;
		case 4:
			cout << "��Ǫ";
			break;
		case 5:
			cout << "��Ǫ";
			break;
		case 6:
			cout << "½Ǫ";
			break;
		case 7:
			cout << "��Ǫ";
			break;
		case 8:
			cout << "��Ǫ";
			break;
		case 9:
			cout << "��Ǫ";
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0|| a2 != 0) && (n3 != 0 || n4 != 0))
			{
				cout << "��";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ư�";
			break;
		case 9:
			cout << "����";
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0|| a2!=0 || n1 != 0 || n2 != 0) && n4) || (flag && n2 != 0 && n4 != 0))
			{
				cout << "��";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ҽʰ";
			break;
		case 2:
			cout << "��ʰ";
			break;
		case 3:
			cout << "��ʰ";
			break;
		case 4:
			cout << "��ʰ";
			break;
		case 5:
			cout << "��ʰ";
			break;
		case 6:
			cout << "½ʰ";
			break;
		case 7:
			cout << "��ʰ";
			break;
		case 8:
			cout << "��ʰ";
			break;
		case 9:
			cout << "��ʰ";
			break;
		}
		switch (n4)
		{
		case 0:
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		}
		flag = 0;
	}
	if (a1 != 0 || a2 != 0 || a3 != 0)
	{
		cout << "Բ" ;
		if (a4 == 0)
		{
			cout << "��" << endl;
			return 0;
		}
	}
	if (a4 != 0)
	{
		n1 = a4 / 10;
		n2 = a4 % 10;
		switch (n1)	
	    {
		case 0:
			if (n2 != 0 && (a1 != 0 || a2 != 0 || a3 != 0))
				cout << "��";
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�ƽ�";
			break;
		case 9:
			cout << "����";
			break;
		}
		switch (n2)
		{
		case 0:
			cout << "��" << endl;
			break;
		case 1:
			cout << "Ҽ��";
			break;
		case 2:
			cout << "����";
			break;
		case 3:
			cout << "����";
			break;
		case 4:
			cout << "����";
			break;
		case 5:
			cout << "���";
			break;
		case 6:
			cout << "½��";
			break;
		case 7:
			cout << "���";
			break;
		case 8:
			cout << "�Ʒ�";
			break;
		case 9:
			cout << "����";
			break;
		}
	}
	if (a == 0)
		cout << "��Բ��" << endl ;
    return 0;
}