/*2253744 林觉凯 软工*/
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
		cout << "请输入第" << i + 1 << "行" << endl;
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
	cout << "大写 : " << Uppercases << endl;
	cout << "小写 : " << Lowercases << endl;
	cout << "数字 : " << Numbers << endl;
	cout << "空格 : " << Spaces << endl;
	cout << "其它 : " << Others << endl;
	return 0;
}