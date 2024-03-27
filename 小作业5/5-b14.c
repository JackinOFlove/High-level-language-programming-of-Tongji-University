/*2253744 林觉凯 软工*/
/*2252974 胡琪昂 2153264 任思剑 2253909 张宏晔 2250397 秦成 2250779 艾靖淞 2253187 张又文 2253984 施帅乾 2250821 郭平伟*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define X_MAX 10
#define Y_MAX 26
#define BOOM_NUM 50
int main()
{
	int ret = 1;
	int boom_num = 0;
	char array[X_MAX][Y_MAX];
	for (int i = 0; i < X_MAX; i++)
	{
		for (int j = 0; j < Y_MAX; j++)
		{
			scanf("%c", &array[i][j]);
			if (array[i][j] == ' ' || array[i][j] == '\n')
				j--;
		}
	}
	while (1)
	{
		for (int i = 0; i < X_MAX; i++)
		{
			for (int j = 0; j < Y_MAX; j++)
			{
				if (array[i][j] == '*')
					boom_num++;
			}
		}
		if (boom_num != BOOM_NUM)
		{
			printf("错误1\n");
			break;
		}
		for (int row = 0; row < X_MAX; row++)
		{
			for (int col = 0; col < Y_MAX; col++)
			{
				int count = 0;
				if (array[row][col] != '*')
				{
					if (row - 1 >= 0)
					{
						if (array[row - 1][col] == '*')
							count++;
					}
					if (row + 1 < X_MAX)
					{
						if (array[row + 1][col] == '*')
							count++;
					}
					if (col - 1 >= 0)
					{
						if (array[row][col - 1] == '*')
							count++;
					}
					if (col + 1 < Y_MAX)
					{
						if (array[row][col + 1] == '*')
							count++;
					}
					if (row - 1 >= 0 && col - 1 >= 0)
					{
						if (array[row - 1][col - 1] == '*')
							count++;
					}
					if (row - 1 >= 0 && col + 1 < Y_MAX)
					{
						if (array[row - 1][col + 1] == '*')
							count++;
					}
					if (row + 1 < X_MAX && col - 1 >= 0)
					{
						if (array[row + 1][col - 1] == '*')
							count++;
					}
					if (row + 1 < X_MAX && col + 1 < Y_MAX)
					{
						if (array[row + 1][col + 1] == '*')
							count++;
					}
					if (array[row][col] != '0' + count)
					{
						printf("错误2\n");
						ret = 0;
						break;
					}
				}
			}
			if (!ret)
				break;
		}
		if (ret)
		{
			printf("正确\n");
			break;
		}
		else
			break;
	}
	return 0;
}