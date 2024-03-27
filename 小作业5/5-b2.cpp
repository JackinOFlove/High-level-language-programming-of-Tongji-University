/*2253744 ÁÖ¾õ¿­ Èí¹¤*/
#include <iostream>
using namespace std;
int main()
{
	bool deng[101] = { false };
	for (int i = 1; i < 101; i++)
		for (int j = i; j < 101; j+=i)
			deng[j] = !deng[j];
	for (int i = 1; i < 101; i++)
		if (deng[i])
			cout << i << ' ';
	cout << endl;
	return 0;
}