/*2253744 林觉凯 软工*/
#include <iostream>
#define Length 9
using namespace std;
bool Judgerow(int Array[Length][Length])
{
	bool flag = 1;
	for (int row = 0; row < Length; row++)
	{
		int Set_sequese[10] = { 0 };
		for (int col = 0; col < Length; col++)
		{
			if (Set_sequese[Array[row][col]] != 0)
			{
				flag = 0;
				return flag;
			}
			else
				Set_sequese[Array[row][col]] = 1;
		}
	}
	return flag;
}
bool Judgecol(int Array[Length][Length])
{
	bool flag = 1;
	for (int col = 0; col < Length; col++)
	{
		int Set_sequese[10] = { 0 };
		for (int row = 0; row < Length; row++)
		{
			if (Set_sequese[Array[row][col]] != 0)
			{
				flag = 0;
				return flag;
			}
			else
				Set_sequese[Array[row][col]] = 1;
		}
	}
	return flag;
}
bool Judgeblock(int Array[Length][Length])
{
	bool flag = 1;
	for (int row = 0; row < Length; row += 3)
	{
		for (int col = 0; col < Length; col += 3)
		{
			int Set_sequese[10] = { 0 };
			Set_sequese[Array[row][col]]++;
			Set_sequese[Array[row][col + 1]]++;
			Set_sequese[Array[row][col + 2]]++;
			Set_sequese[Array[row + 1][col]]++;
			Set_sequese[Array[row + 1][col + 1]]++;
			Set_sequese[Array[row + 1][col + 2]]++;
			Set_sequese[Array[row + 2][col]]++;
			Set_sequese[Array[row + 2][col + 1]]++;
			Set_sequese[Array[row + 2][col + 2]]++;
			for (int i = 1; i < 10; i++)
			{
				if (Set_sequese[i] > 1)
				{
					flag = 0;
					return flag;
				}
			}
		}
	}
	return flag;
}
int main()
{
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int tempnumber;
	int array[Length][Length] = { 0 };
	for (int i = 0; i < Length * Length; i++)
	{
		cin >> tempnumber;
		if (cin.good() == 0)
		{
			cout << "请重新输入第" << (i / 9 + 1) << "行" << (i % 9 + 1) << "列(行列均从1开始计数)的值";
			cin.clear();
			cin.ignore(1024, '\n');
			i--;
			continue;
		}
		if (tempnumber < 1 || tempnumber > 9)
		{
			cout << "请重新输入第" << (i / 9 + 1) << "行" << (i % 9 + 1) << "列(行列均从1开始计数)的值";
			i--;
			continue;
		}
		array[i / 9][i % 9] = tempnumber;
	}
	bool Judgement = 1;
	Judgement = (Judgerow(array) && Judgecol(array) && Judgeblock(array));
	if (Judgement)
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
}