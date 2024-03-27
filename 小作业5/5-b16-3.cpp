/*2253744 林觉凯 软工*/
#include <iostream>
#include <string>
#define STU_NUM 10
using namespace std;
void Input(string Student_id[], string Student_name[], int Student_score[])
{
	for (int i = 0; i < STU_NUM; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> Student_id[i] >> Student_name[i] >> Student_score[i];
	}
}
void Sort_by_Id(string Student_id[], string Student_name[], int Student_score[])
{
    for (int i = 0; i < STU_NUM - 1; i++)
    {
        for (int j = 0; j < STU_NUM - i - 1; j++)
        {
            int temp_score = 0;
            string temp_id, temp_name;
            if (Student_id[j] > Student_id[j + 1])
            {
                temp_id = Student_id[j];
                Student_id[j] = Student_id[j + 1];
                Student_id[j + 1] = temp_id;
                temp_name = Student_name[j];
                Student_name[j] = Student_name[j + 1];
                Student_name[j + 1] = temp_name;
                temp_score = Student_score[j];
                Student_score[j] = Student_score[j + 1];
                Student_score[j + 1] = temp_score;
            }
        }
    }
}
void Output(string Student_id[], string Student_name[], int Student_score[])
{
    cout << endl << "全部学生(学号升序):" << endl;
    for (int i = 0; i < STU_NUM; i++)
        cout << Student_name[i] << " " << Student_id[i] << " " << Student_score[i] << endl;
}
int main()
{
	int Student_score[STU_NUM] = { 0 };
	string Student_id[STU_NUM], Student_name[STU_NUM];
	Input(Student_id, Student_name, Student_score);
	Sort_by_Id(Student_id, Student_name, Student_score);
	Output(Student_id, Student_name, Student_score);
	return 0;
}