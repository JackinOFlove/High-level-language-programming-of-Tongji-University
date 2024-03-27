/*2253744 林觉凯 软件*/
#include <iostream>
#include <iomanip>
using namespace std;
#define Pi 3.14159
int main()
{
	cout<< "请输入一个[1..30000]间的整数:"<<endl;
	int a;
	cin >> a;
	cout << setiosflags(ios::left);
	cout << "万位" << " : " << a /10000 % 10 << endl;
	cout << "千位" << " : " << a / 1000 % 10 << endl;
	cout << "百位" << " : " << a / 100 % 10 << endl;
	cout << "十位" << " : " << a / 10 % 10 << endl;
	cout << "个位" << " : " << a / 1 % 10 << endl;
	return 0;
}