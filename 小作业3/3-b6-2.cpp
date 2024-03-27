/*2253744 ÁÖ¾õ¿­ Èí¹¤*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
    double a, n;
    cin >> a;
    cout << "´óĞ´½á¹ûÊÇ:" << endl;
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
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
        }
		switch (n2)
		{
		case 0:
			cout << "ÒÚ";
			break;
		case 1:
			cout << "Ò¼ÒÚ";
			break;
		case 2:
			cout << "·¡ÒÚ";
			break;
		case 3:
			cout << "ÈşÒÚ";
			break;
		case 4:
			cout << "ËÁÒÚ";
			break;
		case 5:
			cout << "ÎéÒÚ";
			break;
		case 6:
			cout << "Â½ÒÚ";
			break;
		case 7:
			cout << "ÆâÒÚ";
			break;
		case 8:
			cout << "°ÆÒÚ";
			break;
		case 9:
			cout << "¾ÁÒÚ";
			break;
		}
		if (a2==0 && a3==0 && a4==0)
		{
			cout << "Ô²Õû" << endl;
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
				cout << "Áã";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0) && (n3 != 0 || n4 != 0))
			{
				cout << "Áã";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0 || n1 != 0||n2!=0)&&n4!=0) || (flag && n2 != 0 && n4 != 0))
			{
				cout << "Áã";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
		}
		switch (n4)
		{
		case 0:
			cout << "Íò";
			break;
		case 1:
			cout << "Ò¼Íò";
			break;
		case 2:
			cout << "·¡Íò";
			break;
		case 3:
			cout << "ÈşÍò";
			break;
		case 4:
			cout << "ËÁÍò";
			break;
		case 5:
			cout << "ÎéÍò";
			break;
		case 6:
			cout << "Â½Íò";
			break;
		case 7:
			cout << "ÆâÍò";
			break;
		case 8:
			cout << "°ÆÍò";
			break;
		case 9:
			cout << "¾ÁÍò";
			break;
		}
		flag = 0;
		if (a3 == 0 && a4 == 0)
		{
			cout << "Ô²Õû" << endl;
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
				cout << "Áã";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ò¼Çª";
			break;
		case 2:
			cout << "·¡Çª";
			break;
		case 3:
			cout << "ÈşÇª";
			break;
		case 4:
			cout << "ËÁÇª";
			break;
		case 5:
			cout << "ÎéÇª";
			break;
		case 6:
			cout << "Â½Çª";
			break;
		case 7:
			cout << "ÆâÇª";
			break;
		case 8:
			cout << "°ÆÇª";
			break;
		case 9:
			cout << "¾ÁÇª";
			break;
		}
		switch (n2)
		{
		case 0:
			if (!flag && (n1 != 0 || a1 != 0|| a2 != 0) && (n3 != 0 || n4 != 0))
			{
				cout << "Áã";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ò¼°Û";
			break;
		case 2:
			cout << "·¡°Û";
			break;
		case 3:
			cout << "Èş°Û";
			break;
		case 4:
			cout << "ËÁ°Û";
			break;
		case 5:
			cout << "Îé°Û";
			break;
		case 6:
			cout << "Â½°Û";
			break;
		case 7:
			cout << "Æâ°Û";
			break;
		case 8:
			cout << "°Æ°Û";
			break;
		case 9:
			cout << "¾Á°Û";
			break;
		}
		switch (n3)
		{
		case 0:
			if ((!flag && (a1 != 0|| a2!=0 || n1 != 0 || n2 != 0) && n4) || (flag && n2 != 0 && n4 != 0))
			{
				cout << "Áã";
				flag = 1;
			}
			break;
		case 1:
			cout << "Ò¼Ê°";
			break;
		case 2:
			cout << "·¡Ê°";
			break;
		case 3:
			cout << "ÈşÊ°";
			break;
		case 4:
			cout << "ËÁÊ°";
			break;
		case 5:
			cout << "ÎéÊ°";
			break;
		case 6:
			cout << "Â½Ê°";
			break;
		case 7:
			cout << "ÆâÊ°";
			break;
		case 8:
			cout << "°ÆÊ°";
			break;
		case 9:
			cout << "¾ÁÊ°";
			break;
		}
		switch (n4)
		{
		case 0:
			break;
		case 1:
			cout << "Ò¼";
			break;
		case 2:
			cout << "·¡";
			break;
		case 3:
			cout << "Èş";
			break;
		case 4:
			cout << "ËÁ";
			break;
		case 5:
			cout << "Îé";
			break;
		case 6:
			cout << "Â½";
			break;
		case 7:
			cout << "Æâ";
			break;
		case 8:
			cout << "°Æ";
			break;
		case 9:
			cout << "¾Á";
			break;
		}
		flag = 0;
	}
	if (a1 != 0 || a2 != 0 || a3 != 0)
	{
		cout << "Ô²" ;
		if (a4 == 0)
		{
			cout << "Õû" << endl;
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
				cout << "Áã";
			break;
		case 1:
			cout << "Ò¼½Ç";
			break;
		case 2:
			cout << "·¡½Ç";
			break;
		case 3:
			cout << "Èş½Ç";
			break;
		case 4:
			cout << "ËÁ½Ç";
			break;
		case 5:
			cout << "Îé½Ç";
			break;
		case 6:
			cout << "Â½½Ç";
			break;
		case 7:
			cout << "Æâ½Ç";
			break;
		case 8:
			cout << "°Æ½Ç";
			break;
		case 9:
			cout << "¾Á½Ç";
			break;
		}
		switch (n2)
		{
		case 0:
			cout << "Õû" << endl;
			break;
		case 1:
			cout << "Ò¼·Ö";
			break;
		case 2:
			cout << "·¡·Ö";
			break;
		case 3:
			cout << "Èş·Ö";
			break;
		case 4:
			cout << "ËÁ·Ö";
			break;
		case 5:
			cout << "Îé·Ö";
			break;
		case 6:
			cout << "Â½·Ö";
			break;
		case 7:
			cout << "Æâ·Ö";
			break;
		case 8:
			cout << "°Æ·Ö";
			break;
		case 9:
			cout << "¾Á·Ö";
			break;
		}
	}
	if (a == 0)
		cout << "ÁãÔ²Õû" << endl ;
    return 0;
}