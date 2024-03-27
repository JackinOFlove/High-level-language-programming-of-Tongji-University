#pragma once

#define MAX_STU_NUM			512	//����ÿ������������������511�ˣ����ظ���ѧ����
#define MAX_NAME_LEN			32	//��������������31���ַ���15.5�����֣�

/* ÿ��ѧ������Ϣ������ѧ�ź��������� */
struct student {
	int no;
	char name[MAX_NAME_LEN];
};

/* ��ָ���ļ��е�ѧ���б�
	1��stu�д��ԭʼ˳�򣬲����򡢲�ȥ��
	2��stu��ʵ�������飩�����max_num-1��ѧ���������ѧ��0��ʾ����
	3������ֵ��ʵ�ʶ����ѧ������ */
int read_stulist(const char* filename, struct student *stu, const int max_num);

/* ��ӡ������ѧ����Ϣ
	1����ԭʼ˳���ӡ�������򡢲�ȥ��
	2������ٴ�ӡѧ������
	3������ֵʼ��Ϊ0 */
int print_stulist(const char *prompt, const struct student* stu, const int stu_num);	

