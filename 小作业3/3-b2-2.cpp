/*2253744 �־��� ���*/
#include <iostream>
#include <iomanip>
using namespace std;
#define Pi 3.14159
int main()
{
	cout<< "������һ��[1..30000]�������:"<<endl;
	int a;
	cin >> a;
	cout << setiosflags(ios::left);
	cout << "��λ" << " : " << a /10000 % 10 << endl;
	cout << "ǧλ" << " : " << a / 1000 % 10 << endl;
	cout << "��λ" << " : " << a / 100 % 10 << endl;
	cout << "ʮλ" << " : " << a / 10 % 10 << endl;
	cout << "��λ" << " : " << a / 1 % 10 << endl;
	return 0;
}