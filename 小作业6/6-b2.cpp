/*2253744 林觉凯 软工*/
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
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
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