/*2253744 �־��� ��*/
#include <iostream>
using namespace std;
int tj_strlen(const char* str)
{
	int length = 0;
	if (str != NULL)
	{
		for (; *str != '\0'; str++)
			length++;
	}
	return length;
}
int main()
{
	char str[80];
	char* begin;
	char* end;
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, 80, stdin);
	int length = tj_strlen(str);
	begin = str;
	end = str + length - 2;
	for (; begin < end; begin++, end--)
	{
		if (*begin != *end)
		{
			cout << "no" << endl;
			return 0;
		}
	}
	cout << "yes" << endl;
	return 0;
}