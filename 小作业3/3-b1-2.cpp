/*2253744 �־��� ���*/
#include <iostream>
#include <iomanip>
using namespace std;
#define Pi 3.14159
int main()
{
	cout << "������뾶�͸߶�:" << endl;
	double r, h;
	cin >> r >> h;
	cout << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2);
	cout << setw(10) << "Բ�ܳ�" << " : " << Pi * 2 * r << endl;
	cout << setw(10) << "Բ���" << " : " << Pi * r * r << endl;
	cout << setw(10) << "Բ������" << " : " << Pi * 4 * r * r << endl;
	cout << setw(10) << "Բ�����" << " : " << Pi * 4 * r * r * r / 3 << endl;
	cout << setw(10) << "Բ�����" << " : " << Pi * r * r * h << endl;
	return 0;
}