/*2253744 �־��� ��*/
#include <iostream>
using namespace std;
int tj_strlen(const char str[])
{
	int length = 0;
	while (str[length] != '\0')
		length++;
	return length;
}
int main()
{
	char str[3][128];
	int Uppercases, Lowercases, Numbers, Spaces, Others;
	Uppercases = Lowercases = Numbers = Spaces = Others = 0;
	for (int i = 0; i < 3; i++)
	{
		cout << "�������" << i + 1 << "��" << endl;
		cin.getline(str[i], 128);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < tj_strlen(str[i]); j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				Uppercases++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				Lowercases++;
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				Numbers++;
			else if (str[i][j] == ' ')
				Spaces++;
			else
				Others++;
		}
	}
	cout << "��д : " << Uppercases << endl;
	cout << "Сд : " << Lowercases << endl;
	cout << "���� : " << Numbers << endl;
	cout << "�ո� : " << Spaces << endl;
	cout << "���� : " << Others << endl;
	return 0;
}