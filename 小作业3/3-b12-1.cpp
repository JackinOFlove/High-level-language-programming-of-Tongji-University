/*2253744 林觉凯 软工*/
#include <iostream>
#include <limits> 
using namespace std;
int main()
{
	int x;
	while (1) 
	{
		cout << "请输入x的值[0-100] : ";
		cin >> x;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}
	cout << "cin.good()=" << cin.good() << " x=" << x << endl; //此句不准动，并且要求输出时good为1
	return 0;
}
