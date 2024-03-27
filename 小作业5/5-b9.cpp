/*2253744 �־��� ��*/
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
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	int tempnumber;
	int array[Length][Length] = { 0 };
	for (int i = 0; i < Length * Length; i++)
	{
		cin >> tempnumber;
		if (cin.good() == 0)
		{
			cout << "�����������" << (i / 9 + 1) << "��" << (i % 9 + 1) << "��(���о���1��ʼ����)��ֵ";
			cin.clear();
			cin.ignore(1024, '\n');
			i--;
			continue;
		}
		if (tempnumber < 1 || tempnumber > 9)
		{
			cout << "�����������" << (i / 9 + 1) << "��" << (i % 9 + 1) << "��(���о���1��ʼ����)��ֵ";
			i--;
			continue;
		}
		array[i / 9][i % 9] = tempnumber;
	}
	bool Judgement = 1;
	Judgement = (Judgerow(array) && Judgecol(array) && Judgeblock(array));
	if (Judgement)
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;
	return 0;
}