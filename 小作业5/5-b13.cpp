/*2253744 ÁÖ¾õ¿­ Èí¹¤*/
#include <iostream>
#include <cstdlib>
#define X_MAX 10
#define Y_MAX 26
#define BOOM_NUM 50
using namespace std;
int main()
{
	char array[X_MAX][Y_MAX];
	for (int i = 0; i < X_MAX; i++)
		for (int j = 0; j < Y_MAX; j++)
			array[i][j] = '0';
	srand((unsigned int)(time(NULL)));
	for (int i = 0; i < BOOM_NUM; i++)
	{
		int x = rand() % X_MAX;
		int y = rand() % Y_MAX;
		if (array[x][y] == '0')
			array[x][y] = '*';
		else
			i--;
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
				array[row][col] = '0' + count;
			}
		}
	}
	for (int i = 0; i < X_MAX; i++)
	{
		for (int j = 0; j < Y_MAX; j++)
			cout << array[i][j] << " ";
		cout << endl;
	}
	return 0;
}