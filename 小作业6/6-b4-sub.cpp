/*2253744 林觉凯 软工*/

#include <cstdio>   //NULL
//不再允许包含任何系统头文件

/* ----- 不允许定义任何形式的全局变量/全部数组/只读全局变量/宏定义!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length = 0;
    if (str != NULL)
    {
        for (; *str != '\0'; str++)
            length++;
    }
    return length;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (s1 == NULL || s2 == NULL)
        return s1;
    char* p = s1 + length1;
    for (; *s2 != '\0'; s2++, p++)
        *p = *s2;
    *p = '\0';
    return s1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (s1 == NULL || s2 == NULL)
        return s1;
    if (len >= length2)
        tj_strcat(s1, s2);
    else
    {
        char* p1 = s1 + length1;
        const char* p2 = s2 + len;
        for (; s2 < p2; s2++, p1++)
            *p1 = *s2;
        *p1 = '\0';
    }
    return s1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (s1 == NULL)
        return s1;
    if (s2 == NULL)
    {
        *s1 = '\0';
        return s1;
    }
    char* p = s1;
    for (; *s2 != '\0'; p++, s2++)
        *p = *s2;
    *p = '\0';
    return s1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    if (s1 == NULL || s2 == NULL)
        return s1;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (len >= length2)
    {
        char* p = s1;
        for (; *s2 != '\0'; p++, s2++)
            *p = *s2;
    }
    else
    {
        char* q = s1;
        const char* p = s2 + len;
        for (; s2 < p; q++, s2++)
            *q = *s2;
    }
    return s1;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cmp = 0;
    if (s1 == NULL && s2 != NULL)
        cmp = -1;
    if (s1 != NULL && s2 == NULL)
        cmp = 1;
    if (s1 != NULL && s2 != NULL)
    {
        for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++)
        {
            if (*s1 != *s2)
            {
                cmp = *s1 - *s2;
                break;
            }
        }
    }
    return cmp;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cmp = 0;
    if (s1 == NULL && s2 != NULL)
        cmp = -1;
    if (s1 != NULL && s2 == NULL)
        cmp = 1;
    if (s1 != NULL && s2 != NULL)
    {
        for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++)
        {
            if (*s1 != *s2)
            {
                char temp1, temp2;
                temp1 = *s1;
                temp2 = *s2;
                if (temp1 >= 'A' && temp1 <= 'Z')
                    temp1 += 32;
                if (temp2 >= 'A' && temp2 <= 'Z')
                    temp2 += 32;
                if (temp1 != temp2)
                {
                    cmp = temp1-temp2;
                    break;
                }  
            }
        }
    }
    return cmp;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cmp = 0;
    if (s1 == NULL && s2 != NULL)
        cmp = -1;
    if (s1 != NULL && s2 == NULL)
        cmp = 1;
    if (s1 != NULL && s2 != NULL)
    {
        int minlength, maxlength;
        int length1 = tj_strlen(s1);
        int length2 = tj_strlen(s2);
        if (length1 <= length2)
        {
            minlength = length1;
            maxlength = length2;
        }
        else
        {
            minlength = length2;
            maxlength = length1;
        }
        if (len >= maxlength)
            cmp = tj_strcmp(s1, s2);
        else if (len <= minlength)
        {
            const char* standard = s1 + len;
            for (; s1 < standard; s1++, s2++)
            {
                if (*s1 != *s2)
                {
                    cmp = *s1 - *s2;
                    return cmp;
                }
            }
        }
        else
        {
            for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++)
            {
                if (*s1 != *s2)
                {
                    cmp = *s1 - *s2;
                    return cmp;
                }
            }
        }
    }
    return cmp;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int cmp = 0;
    if (s1 == NULL && s2 != NULL)
        cmp = -1;
    if (s1 != NULL && s2 == NULL)
        cmp = 1;
    if (s1 != NULL && s2 != NULL)
    {
        int minlength, maxlength;
        int length1 = tj_strlen(s1);
        int length2 = tj_strlen(s2);
        if (length1 <= length2)
        {
            minlength = length1;
            maxlength = length2;
        }
        else
        {
            minlength = length2;
            maxlength = length1;
        }
        if (len >= maxlength)
            cmp = tj_strcasecmp(s1, s2);
        else if (len <= minlength)
        {
            const char* standard = s1 + len;
            for (; s1 < standard; s1++, s2++)
            {
                if (*s1 != *s2)
                {
                    char temp1, temp2;
                    temp1 = *s1;
                    temp2 = *s2;
                    if (temp1 >= 'A' && temp1 <= 'Z')
                        temp1 += 32;
                    if (temp2 >= 'A' && temp2 <= 'Z')
                        temp2 += 32;
                    if (temp1 != temp2)
                    {
                        cmp = temp1 - temp2;
                        break;
                    }
                }
            }
        }
        else
        {
            for (; *s1 != '\0' || *s2 != '\0'; s1++, s2++)
            {
                if (*s1 != *s2)
                {
                    char temp1, temp2;
                    temp1 = *s1;
                    temp2 = *s2;
                    if (temp1 >= 'A' && temp1 <= 'Z')
                        temp1 += 32;
                    if (temp2 >= 'A' && temp2 <= 'Z')
                        temp2 += 32;
                    if (temp1 != temp2)
                    {
                        cmp = temp1 - temp2;
                        break;
                    }
                }
            }
        }
    }
    return cmp;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str != NULL)
    {
        char* p = str;
        for (; *p != '\0'; p++)
        {
            if (*p >= 'a' && *p <= 'z')
                *p -= 32;
        }
    }
    return str;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str != NULL)
    {
        char* p = str;
        for (; *p != '\0'; p++)
        {
            if (*p >= 'A' && *p <= 'Z')
                *p += 32;
        }
    }
    return str;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int number = 0;
    if (str != NULL)
    {
        for (; *str != '\0'; str++)
        {
            number++;
            if (*str == ch)
                return number;
        }
    }
    return 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int number = 0;
    if (str != NULL)
    {
        for (; *str != '\0'; str++)
        {
            number++;
            if (tj_strncmp(str, substr, tj_strlen(substr)) == 0)
                return number;
        }
    }
    return 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int number = 0;
    int length = tj_strlen(str);
    if (str != NULL)
    {
        const char* p = str + length - 1;
        for (; p >= str; p--)
        {
            number++;
            if (*p == ch)
                return length - number + 1;
        }
    }
    return 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int number = 0;
    int length = tj_strlen(str);
    if (str != NULL)
    {
        const char* p = str + length - 1;
        for (; p >= str; p--)
        {
            number++;
            if (tj_strncmp(p, substr, tj_strlen(substr)) == 0)
                return length - number + 1;
        }
    }
    return 0;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (str == NULL || str == "")
        return str;
    else
    {
        int length = tj_strlen(str);
        char* head = str;
        char* tail = str + length - 1;
        for (; head < tail; head++, tail--)
        {
            char temp = *head;
            *head = *tail;
            *tail = temp;
        }       
    }
    return str;
}