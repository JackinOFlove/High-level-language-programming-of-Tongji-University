/*2253744 林觉凯 软工*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STU_NUM 10
int tj_strlen(const char str[])
{
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length; 
}
void tj_strcpy(char s1[], const char s2[])
{
    int length2 = tj_strlen(s2);
    for (int i = 0; i <= length2; i++)
        s1[i] = s2[i];
}
int tj_strcmp(const char s1[], const char s2[])
{
    int ret;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (length1 > length2)
        ret = (int)s1[length2];
    else if (length1 < length2)
        ret = -(int)s2[length1];
    else
    {
        ret = 0;
        int len = length1 = length2;
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                ret = (int)s1[i] - (int)s2[i];
                break;
            }
        }
    }
    return ret; 
}
void Sort_by_Id(char Student_id[][8], char Student_name[][9], int Student_score[])
{
    for (int i = 0; i < STU_NUM - 1; i++)
    {
        for (int j = 0; j < STU_NUM - i - 1; j++)
        {
            int temp_score = 0;
            char  temp_id[8] = { 0 }, temp_name[9] = { 0 };
            if (tj_strcmp(Student_id[j], Student_id[j + 1]) < 0)
            {
                tj_strcpy(temp_id, Student_id[j]);
                tj_strcpy(Student_id[j], Student_id[j + 1]);
                tj_strcpy(Student_id[j + 1], temp_id);
                tj_strcpy(temp_name, Student_name[j]);
                tj_strcpy(Student_name[j], Student_name[j + 1]);
                tj_strcpy(Student_name[j + 1], temp_name);
                temp_score = Student_score[j];
                Student_score[j] = Student_score[j + 1];
                Student_score[j + 1] = temp_score;
            }
        }
    }
}
void Input(char Student_id[][8], char Student_name[][9], int Student_score[])
{
    for (int i = 0; i < STU_NUM; i++)
    {
        printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
        scanf("%s %s %d", Student_id[i], Student_name[i], &Student_score[i]);
    }
}
void Output(char Student_id[][8],char Student_name[][9],int Student_score[])
{
    printf("\n");
    printf("及格名单(学号降序):\n");
    for (int i = 0; i < STU_NUM; i++)
    {
        if (Student_score[i] >= 60)
            printf("%s %s %d\n", Student_name[i], Student_id[i], Student_score[i]);
    }
}
int main()
{
    char Student_id[STU_NUM][8];
    char Student_name[STU_NUM][9];
    int Student_score[STU_NUM] = { 0 };
    Input(Student_id, Student_name, Student_score);
    Sort_by_Id(Student_id, Student_name, Student_score);
    Output(Student_id, Student_name, Student_score);
    return 0;
}