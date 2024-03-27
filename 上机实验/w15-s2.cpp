/*2253744 �־��� ��*/
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�������ȫ��ֻ��������궨�岻�ܴ����ƣ�
   3�������������������
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;		//ĳ�γ̵ĳɼ����ٷ��ƣ�
	float weight;	//ĳ�γ̵�ѧ�֣�Ȩ�أ�
	int   gpa;		//ĳ�γ̵ļ��㣨ͬ�ù���[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5��
};

struct student {
	int   no;               //ѧ�ţ���Ȼ��int���������˴������ǣ�
	char  name[9];          //���������4������
	struct course score[3]; //��������ſεĳɼ���δʹ�ú궨�壬����ʵ��ʱ��ֱ��д3���ɣ�
	float avg_gpa;                      //��������������Ϊ��Ҫ���ӵĽṹ���Ա����һ��������Ҫ��ɾ������
};

class gpa_calc {
private:
	struct student stu[N];
	//�������������κ����ݳ�Ա 
public:
	void input();
	void output_base();
	void output_max();
	int GPA(float value);                    //��������������Ϊ��Ҫ���ӵĳ�Ա��������һ��������Ҫ��ɾ������
};

/* �������gpa_calc��ĳ�Ա����������ʵ�֣������Լ����ӵ�
   Ҫ�����������cin/cout */
int gpa_calc::GPA(float value)
{
	if (value >= 90)
		return 5;
	if (value >= 80)
		return 4;
	if (value >= 70)
		return 3;
	if (value >= 60)
		return 2;
	return 0;
}
void gpa_calc::input()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		stu[i].avg_gpa = 0;
		cout << "�������" << setw(2) << i + 1 << "��ѧ������Ϣ��";
		cin >> stu[i].no >> stu[i].name;
		for (j = 0; j < 3; j++)
		{
			cin >> stu[i].score[j].value >> stu[i].score[j].weight;
			stu[i].score[j].gpa = GPA(stu[i].score[j].value);
			stu[i].avg_gpa += stu[i].score[j].gpa * stu[i].score[j].weight;
		}
		stu[i].avg_gpa /= (stu[i].score[0].weight + stu[i].score[1].weight + stu[i].score[2].weight);
	}
}
void gpa_calc::output_base()
{
	struct student* ps;
	cout << endl << "10��ѧ���ĳɼ�" << endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
	cout << "==================================================================" << endl;
	cout << setiosflags(ios::left);
	for (ps = stu; ps < stu + N; ps++)
	{
		cout << setw(4) << ps - stu + 1 << " " << setw(7) << ps->no << " " << setw(8) << ps->name;
		for (int i = 0; i < 3; i++)
			cout << " " << setw(5) << ps->score[i].gpa << " " << setw(5) << ps->score[i].weight;
		cout << " " << setw(5) << fixed << setprecision(3) << ps->avg_gpa << endl << resetiosflags(ios::fixed);
	}
	cout << resetiosflags(ios::left);
}
void gpa_calc::output_max()
{
	cout<<endl<<"������ߵ�ѧ��Ϊ"<<endl;
	cout << "��� ѧ��    ����     ����1 Ȩ��1 ����2 Ȩ��2 ����3 Ȩ��3 ƽ������" << endl;
	cout << "==================================================================" << endl;
	float max = 0;
	for (int i = 0; i < N; i++)
	{
		if (stu[i].avg_gpa > max)
			max = stu[i].avg_gpa;
	}
	cout << setiosflags(ios::left);
	for (int i = 0; i < N; i++)
	{
		if (stu[i].avg_gpa == max)
		{
			struct student* ps = &stu[i];
			cout << setw(4) << ps - stu + 1 << " " << setw(7) << ps->no << " " << setw(8) << ps->name;
			for (int i = 0; i < 3; i++)
				cout << " " << setw(5) << ps->score[i].gpa << " " << setw(5) << ps->score[i].weight;
			cout << " " << setw(5) << fixed << setprecision(3) << ps->avg_gpa << endl << resetiosflags(ios::fixed);
		}
	}
	cout << resetiosflags(ios::left);
}
   /***************************************************************************
	 �������ƣ�
	 ��    �ܣ�
	 ���������
	 �� �� ֵ��
	 ˵    ����main������׼��
   ***************************************************************************/
int main()
{
	gpa_calc g;

	g.input();		//����10��ѧ������Ϣ
	g.output_base();	//���10��ѧ���Ļ�����Ϣ
	g.output_max();	//�����ߣ������ж����

	return 0;
}

/*
�������ݣ����Ƶ�cmd����

2152482 ������ 76.5 4 82 5 52 2.5
2250411 �ֿ��� 63 4.5 49 1 87 6
2250821 ��ƽΰ 56 3 76 4 69 5
2251561 ������ 44.5 2 83.5 4 87 6
2252584 ŷ���� 91 4 43.5 1 66 3
2252753 ����� 79 6 85.5 3 62 2
2253554 �κ��� 86 3 63 3 77.5 4
2253711 ����� 49.5 3 86 6 93.5 3
2253968 ���ĳ� 81.5 2 64.5 3 87 4
2254174 ���� 73 3 62 2.5 85 5

*/