/*2253744 �־��� ���*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
#define Pi 3.14159
int main()
{
	cout << "������һ��[1..100��]�������:" << endl;
	double a;
	cin >> a;
	int i, f, f1, f2;
	double n;
	f = (int)rint(modf(a, &n) * 100);
	f1 = f / 10;
	f1 = (int)fmin(9.0, (double)f1);
	f2 = f - f1 * 10;
	f2 = (int)fmin(9.0, (double)f2);
	i = (int)fmod(a, 1000000000.0);
	cout << f  << endl;
	cout << i << endl;
	cout << f1 << endl;
	cout << f2 << endl;
	cout << setiosflags(ios::left);
	cout << setw(6) << "ʮ��λ" << ":" << int(a / 1000000000.0) << endl;
	cout << setw(6) << "��λ" << ":" << i / 100000000 % 10 << endl;
	cout << setw(6) << "ǧ��λ" << ":" << i / 10000000 % 10 << endl;
	cout << setw(6) << "����λ" << ":" << i / 1000000 % 10 << endl;
	cout << setw(6) << "ʮ��λ" << ":" << i / 100000 % 10 << endl;
	cout << setw(6) << "��λ" << ":" << i / 10000 % 10 << endl;
	cout << setw(6) << "ǧλ" << ":" << i / 1000 % 10 << endl;
	cout << setw(6) << "��λ" << ":" << i / 100 % 10 << endl;
	cout << setw(6) << "ʮλ" << ":" << i / 10 % 10 << endl;
	cout << setw(6) << "Բ" << ":" << i / 1 % 10 << endl;
	cout << setw(6) << "��" << ":" << f1 << endl;
	cout << setw(6) << "��" << ":" << f2 << endl;
	return 0;
}