/*2253744 林觉凯 软工*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int number = 0;
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;
	for (a3 = 1; a3 < 10; a3++)
	{
		for (a2 = 1; a2 < 10; a2++)
		{
			if (a2 == a3)
				continue;
			for (a1 = 1; a1 < 10; a1++)
			{
				if (a1 == a3 || a1 == a2)
					continue;
				for (b3 = a3+1; b3 < 10; b3++)
				{
					if (b3 == a3 || b3 == a2 || b3 == a1)
						continue;
					for (b2 = 1; b2 < 10; b2++)
					{
						if (b2==b3||b2 == a3 || b2 == a2 || b2 == a1)
							continue;
						for (b1 = 1; b1 < 10; b1++)
						{
							if (b1 == b3 || b1 == b2 || b1 == a3 || b1 == a2||b1==a1)
								continue;
							for (c3 = b3 + 1; c3 < 10; c3++)
							{
								if (c3 == b3 || c3 == b2 || c3 == b1 || c3 == a3 || c3 == a2 || c3 == a1)
									continue;
								for (c2 = 1; c2 < 10; c2++)
								{
									if (c2 == c3 || c2 == b3 || c2 == b2 || c2 == b1 || c2 == a3 || c2 == a2 || c2 == a1)
										continue;
									for (c1 = 1; c1 < 10; c1++)
									{
										if (c1 == c3 || c1 == c2 || c1 == b3 || c1 == b2 || c1 == b1 || c1 == a3 || c1 == a2 || c1 == a1)
											continue;
										if (a1 + b1 + c1 + (a2 + b2 + c2) * 10 + (a3 + b3 + c3) * 100 == 1953)
										{
											number++;
											cout << "No." <<setw(3)<< number << " : " << a3 << a2 << a1 << "+" << b3 << b2 << b1 << "+" << c3 << c2 << c1 << "=1953" << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
			
	}
	cout << "total=" << number << endl;
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}