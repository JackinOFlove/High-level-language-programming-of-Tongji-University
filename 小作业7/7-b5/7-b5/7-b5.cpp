/*2253744 �־��� ��*/

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <cstring>
#include <iostream>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�

/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list;
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	int round1, round2;

	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
	friend stu_list;
	
public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������

	void merge();
	int reorder();
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */


/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
	for (int i = 0; i < MAX_STU_NUM; i++)
	{
		list_merge[i].stu_no = -1;
		list_merge[i].round1 = 0;
		list_merge[i].round2 = 0;
	}
	list_merge_num = list_num_1 = list_num_2 = 0;
}

void stu_list::merge()
{
	for (int i = 0; list_round_1[i].no > 0; i++)
	{
		for (int j = 0; j < MAX_STU_NUM; j++)
			if (list_merge[j].stu_no == list_round_1[i].no || list_merge[j].stu_no < 0)
			{
				strcpy(list_merge[j].stu_name, list_round_1[i].name);
				list_merge[j].stu_no = list_round_1[i].no;
				list_merge[j].round1 = 1;
				break;
			}
	}
	for (int i = 0; list_round_2[i].no > 0; i++)
	{
		for (int j = 0; j < MAX_STU_NUM; j++)
			if (list_merge[j].stu_no == list_round_2[i].no || list_merge[j].stu_no < 0)
			{
				strcpy(list_merge[j].stu_name, list_round_2[i].name);
				list_merge[j].stu_no = list_round_2[i].no;
				list_merge[j].round2 = 1;
				break;
			}
	}
}

int stu_list::reorder()
{
	int tail;
	for (tail = 0; list_merge[tail].stu_no > 0; tail++);
	for (int i = tail - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (list_merge[j].stu_no > list_merge[j + 1].stu_no)
			{
				stu_merge tmp = list_merge[j];
				list_merge[j] = list_merge[j + 1];
				list_merge[j + 1] = tmp;
			}
	return tail;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸�
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
	case 1:
		this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
		if (this->list_num_1 > 0)
			print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
		else
			ret = -1;
		break;
	case 2:
		this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
		if (this->list_num_2 > 0)
			print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
		else
			ret = -1;
		break;
	default:
		ret = -1;
		break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	this->merge();
	this->reorder();
	cout << "����ѡ������" << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                            ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	for (int i = 0; list_merge[i].stu_no > 0; i++)
	{
		cout << setiosflags(ios::left);
		cout << setw(5) << i + 1 << list_merge[i].stu_no << "  " << setw(32) << list_merge[i].stu_name;
		if (list_merge[i].round1)
		{
			cout << "Y      ";
			if (list_merge[i].round2)
				cout << "Y";
			else
				cout << "�˿�";
		}
		else
			cout << "/      " << "��ѡ";
		cout << endl;

	}
	cout << resetiosflags(ios::left);
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */


	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}