/*2253744 �־��� ��*/
#include <iostream>
using namespace std;
int main()
{
	int number[21] = { 0 };
	int i = 0;
	cout << "��������������������������20������0������������" << endl;
	for (; i < 20; i++)
	{
		cin >> number[i];
		if (number[i] <= 0)
			break;
	}
	i--;
	if (i >= 0)
	{
		cout << "ԭ����Ϊ��" << endl;
		for (int j = 0; j < i + 1; j++)
			cout << number[j] << ' ';
	}
	else
	{
		cout << "����Ч����" << endl;
		return 0;
	}
	cin.ignore(1024, '\n');
	cout << endl;
	cout << "������Ҫ�����������" << endl;
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
	cout << "����������Ϊ��" << endl;
	for (int k = 0; k < i + 2; k++)
		cout << number[k] << ' ';
	cout << endl;
}