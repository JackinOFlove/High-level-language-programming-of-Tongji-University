/*2253744 林觉凯 软工*/
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int x;
	double n = 1;
	double exp = 1;
	double m = 1;
	cout << setprecision(10) << std::left;
	while (1)
	{
		cout << "请输入x的值[-10~+65]" << endl;
		cin >> x;
		if (x <-10 || x > 65)
		{
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		for (m = 1;; m++)
		{
			n = n * x / m;
			if (fabs(n) < 1e-6)
				break;
			exp += n;
		}
		cout << "e^" << x << "=" << exp << endl;
		break;
	}
	return 0;
}