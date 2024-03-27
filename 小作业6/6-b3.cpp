/*2253744 林觉凯 软工*/
#include <iostream>
using namespace std;
int main()
{
	char str[33] = { 0 };
	char* p;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	unsigned int number = 0;
	for (p = str; *p != '\0'; p++)
		number = 2 * number + *p - '0';
	cout << number << endl;
	return 0;
}