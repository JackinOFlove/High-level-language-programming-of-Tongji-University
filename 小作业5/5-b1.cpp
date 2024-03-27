/*2253744 林觉凯 软工*/
#include <iostream>
using namespace std;
int main()
{
	int number[21] = { 0 };
	int i = 0;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (; i < 20; i++)
	{
		cin >> number[i];
		if (number[i] <= 0)
			break;
	}
	i--;
	if (i >= 0)
	{
		cout << "原数组为：" << endl;
		for (int j = 0; j < i + 1; j++)
			cout << number[j] << ' ';
	}
	else
	{
		cout << "无有效输入" << endl;
		return 0;
	}
	cin.ignore(1024, '\n');
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	int Insertnumber;
	cin >> Insertnumber;
	int Insertindex = 0;
	for (; Insertindex < i + 1; Insertindex++)
	{
		if (number[Insertindex] > Insertnumber)
			break;
	}
	for (int j = i; j >= Insertindex; j--)
		number[j + 1] = number[j];
	number[Insertindex] = Insertnumber;
	cout << "插入后的数组为：" << endl;
	for (int k = 0; k < i + 2; k++)
		cout << number[k] << ' ';
	cout << endl;
}