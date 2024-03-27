/*2253744 �־��� ��*/

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length = 0;
    if (str != NULL)
    {
        for (; *str != '\0'; str++)
            length++;
    }
    return length;
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
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