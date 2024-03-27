/*2253744 �־��� ��*/

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��return 0ֻ��һ��ʾ�����ɸı� */

/* ���������κ���ʽ���ⲿȫ�֡���̬ȫ�֡��궨�塢ֻ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char str[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length = 0;
    while (str[length] != '\0')
        length++;
    return length; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    for (int i = 0; i <= length2; i++)
        s1[length1 + i] = s2[i];
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (len > length2)
        tj_strcat(s1, s2);
    else
    {
        for (int i = 0; i < len; i++)
            s1[length1 + i] = s2[i];
        s1[length1 + len] = '\0';
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length2 = tj_strlen(s2);
    for (int i = 0; i <= length2; i++)
        s1[i] = s2[i];
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length2 = tj_strlen(s2);
    if (len >= length2)
    {
        for (int i = 0; i < length2; i++)
            s1[i] = s2[i];
    }
    else
    {
        for (int i = 0; i < len; i++)
            s1[i] = s2[i];
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int ret;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if (length1 > length2)
        ret = (int)s1[length2];
    else if (length1 < length2)
        ret = - (int)s2[length1];
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
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char s1[], const char s2[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int ret;
    const int distance = 'a' - 'A';
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    if(length1 > length2)
        ret = (int)s1[length2];
    else if (length1 < length2)
        ret = - (int)s2[length1];
    else
    {
        ret = 0;
        int len = length1 = length2;
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                int S1 = (int)s1[i];
                int S2 = (int)s2[i];
                if (s1[i] >= 'A' && s1[i] <= 'Z')
                    S1 += distance;
                if (s2[i] >= 'A' && s2[i] <= 'Z')
                    S2 += distance;
                if (S1 != S2)
                {
                    ret = S1 - S2;
                    break;
                }  
            }
        }
    }
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int ret = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length;
    int minlength;
    int maxlength;
    if (length1 != length2)
    {
        if (length1 < length2)
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
            ret = tj_strcmp(s1, s2);
        else if (len <= minlength)
        {
            for (int i = 0; i < len; i++)
            {
                if (s1[i] != s2[i])
                {
                    ret = s1[i] - s2[i];
                    break;
                }
            }
        }
        else if (len > minlength && len <= maxlength)
            ret = s1[minlength] - s2[minlength];
    }
    else
    {
        length = length1 = length2;
        if (len >= length)
            ret = tj_strcmp(s1, s2);
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (s1[i] != s2[i])
                {
                    ret = s1[i] - s2[i];
                    break;
                }
            }
        }
    }
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int ret = 0;
    int length1 = tj_strlen(s1);
    int length2 = tj_strlen(s2);
    int length;
    int minlength;
    int maxlength;
    int distance = 'a' - 'A';
    if (length1 != length2)
    {
        if (length1 < length2)
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
            ret = tj_strcasecmp(s1, s2);
        else if (len <= minlength)
        {
            for (int i = 0; i < len; i++)
            {
                if (s1[i] != s2[i])
                {
                    int S1 = (int)s1[i];
                    int S2 = (int)s2[i];
                    if (s1[i] >= 'A' && s1[i] <= 'Z')
                        S1 += distance;
                    if (s2[i] >= 'A' && s2[i] <= 'Z')
                        S2 += distance;
                    if (S1 != S2)
                    {
                        ret = S1 - S2;
                        break;
                    }
                }
            }
        }
        else if (len > minlength && len <= maxlength)
            ret = s1[minlength] - s2[minlength];
    }
    else
    {
        length = length1 = length2;
        if (len >= length)
            ret = tj_strcasecmp(s1, s2);
        else
        {
            for (int i = 0; i < len; i++)
            {
                if (s1[i] != s2[i])
                {
                    int S1 = (int)s1[i];
                    int S2 = (int)s2[i];
                    if (s1[i] >= 'A' && s1[i] <= 'Z')
                        S1 += distance;
                    if (s2[i] >= 'A' && s2[i] <= 'Z')
                        S2 += distance;
                    if (S1 != S2)
                    {
                        ret = S1 - S2;
                        break;
                    }
                }
            }
        }
    }
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strupr(char str[])
{
    int distance = 'a' - 'A';
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    for (int i = 0; i < tj_strlen(str); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= distance;
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlwr(char str[])
{
    int distance = 'a' - 'A';
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    for (int i = 0; i < tj_strlen(str); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += distance;
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    int ret = 1;
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    for (int i = 0; i < tj_strlen(str); i++)
    {
        if (str[i] != ch)
            ret++;
        else
            break;
    }
    if (ret >= tj_strlen(str))
        ret = 0;
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    int ret = 0;
    int length = tj_strlen(str);
    int sublength = tj_strlen(substr);
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    for (int i = 0; i < length; i++)
    {
        if (str[i] == substr[0])
        {
            for (int j = 0; j < sublength; j++)
            {
                if (str[i + j] != substr[j])
                    break;
                else if (str[i + j] == substr[j] && j == sublength - 1)
                {
                    ret = i + 1;
                    break;
                }
            }
        }
        if (ret)
            break;
    }
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    int ret = tj_strlen(str);
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    for (int i = tj_strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] != ch)
            ret--;
        else
            break;
    }
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length= tj_strlen(str);
    int sublength = tj_strlen(substr);
    int ret = 0;
    for (int i = length - 1; i >= 0; i--)
    {
        if (str[i] == substr[sublength - 1])
        {
            int n = i - sublength + 1;
            for (int j = sublength - 1; j >= 0; j--)
            {
                if (str[n + j] != substr[j])
                    break;
                else if (str[n + j] == substr[j] && j == 0)
                {
                    ret = n + 1;
                    break;
                }
            }
        }
        if (ret)
            break;
    }
    return ret; //returnֵ�ɸ�����Ҫ�޸�
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrev(char str[])
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int length = tj_strlen(str);
    int mid = (length - 1) / 2;
    if (length == 0) {}
    else if (length % 2 == 1)
    {
        for (int i = 0; i < mid; i++)
        {
            char temp = str[i];
            str[i] = str[length - i - 1];
            str[length - i - 1] = temp;
        }
    }
    else if (length % 2 == 0)
    {
        for (int i = 0; i <= mid; i++)
        {
            char temp = str[i];
            str[i] = str[length - i - 1];
            str[length - i - 1] = temp;
        }
    }
    return 0; //returnֵ�ɸ�����Ҫ�޸�
}