/*2253744 �־��� ��*/
#define _CRT_NO_WARNING
#include <stdio.h>
#include <windows.h> //ȡϵͳʱ��

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	/* �˴�����ĳ���ʼ */
	int number = 0;
	int a1, a2, a3, b1, b2, b3, c1, c2, c3;
	for (a3 = 1; a3 < 10; a3++)
	{
		for (a2 = 1; a2 < 10; a2++)
		{
			if (a2 == a3)
			{
				continue;
			}
			for (a1 = 1; a1 < 10; a1++)
			{
				if (a1 == a3 || a1 == a2)
				{
					continue;
				}
				for (b3 = a3 + 1; b3 < 10; b3++)
				{
					if (b3 == a3 || b3 == a2 || b3 == a1)
					{
						continue;
					}
					for (b2 = 1; b2 < 10; b2++)
					{
						if (b2 == b3 || b2 == a3 || b2 == a2 || b2 == a1)
						{
							continue;
						}
						for (b1 = 1; b1 < 10; b1++)
						{
							if (b1 == b3 || b1 == b2 || b1 == a3 || b1 == a2 || b1 == a1)
							{
								continue;
							}
							for (c3 = b3 + 1; c3 < 10; c3++)
							{
								if (c3 == b3 || c3 == b2 || c3 == b1 || c3 == a3 || c3 == a2 || c3 == a1)
								{
									continue;
								}
								for (c2 = 1; c2 < 10; c2++)
								{
									if (c2 == c3 || c2 == b3 || c2 == b2 || c2 == b1 || c2 == a3 || c2 == a2 || c2 == a1)
									{
										continue;
									}
									for (c1 = 1; c1 < 10; c1++)
									{
										if (c1 == c3 || c1 == c2 || c1 == b3 || c1 == b2 || c1 == b1 || c1 == a3 || c1 == a2 || c1 == a1)
										{
											continue;
										}
										if (a1 + b1 + c1 + (a2 + b2 + c2) * 10 + (a3 + b3 + c3) * 100 == 1953)
										{
											number++;
											printf("%s%3d%s%d%d%d%s%d%d%d%s%d%d%d%s\n", "No.", number, " : ", a3, a2, a1, "+", b3, b2, b1, "+", c3, c2, c1, "=1953");
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
	printf("total=%d\n", number);

	/* �˴�����ĳ������ */

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	printf("������Ƶ�� : %lldHz\n", tick.QuadPart);
	printf("���������� : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f��\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}
