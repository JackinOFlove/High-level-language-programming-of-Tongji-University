/*2253744 林觉凯 软工*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#define TIMES 10
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";
int tj_strlen(const char str[])
{
	int length = 0;
	while (str[length] != '\0')
		length++;
	return length;
}
int main()
{
	cin.ignore(1024, '\n');
	bool ret = true;
	int Length, Upper_num, Lower_num, Number_num, Other_num;
	cin >> Length >> Upper_num >> Lower_num >> Number_num >> Other_num;
	cin.ignore(1024, '\n');
	if (cin.good() == 0 || (Length < 12 || Length > 16) || (Upper_num < 2 || Upper_num > 16) || (Lower_num < 2 || Lower_num > 16) || (Number_num < 2 || Number_num > 16) || (Other_num < 2 || Other_num > 16) || (Upper_num + Lower_num + Number_num + Other_num > Length))
		ret = false;
	else 
	{
		for (int time = 0; time < TIMES; time++)
		{
			char key[17] = { 0 };
			int Check_uppernum, Check_lowernum, Check_numbernum, Check_othernum;
			Check_uppernum = Check_lowernum = Check_numbernum = Check_othernum = 0;
			cin.getline(key, 17, '\n');
			if (tj_strlen(key) != Length)
			{
				ret = false;
				break;
			}
			for (int i = 0; i < Length; i++)
			{
				if (key[i] >= 'A' && key[i] <= 'Z')
					Check_uppernum++;
				else if (key[i] >= 'a' && key[i] <= 'z')
					Check_lowernum++;
				else if (key[i] >= '0' && key[i] <= '9')
					Check_numbernum++;
				else
				{
					bool Exist = false;
					for (int j = 0; j < 15; j++)
					{
						if (key[i] == other[j])
						{
							Exist = true;
							break;
						}
					}
					if (Exist == false)
						ret = false;
				}
				if (ret == false)
					break;
			}
			Check_othernum = Length - Check_uppernum - Check_lowernum - Check_numbernum;
			if (Upper_num > Check_uppernum || Lower_num > Check_lowernum || Number_num > Check_numbernum || Other_num > Check_othernum)
				ret = false;
			if (ret == false)
				break;
		}
	}
	if (ret)
		cout << "正确" << endl;
	else
		cout << "错误" << endl;
	return 0;
}