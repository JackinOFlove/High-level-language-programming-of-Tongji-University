/*2253744 �־��� ��*/
#include <iostream>
using namespace std;
int main()
{
	char str[33] = { 0 };
	char* p;
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;
	unsigned int number = 0;
	for (p = str; *p != '\0'; p++)
		number = 2 * number + *p - '0';
	cout << number << endl;
	return 0;
}