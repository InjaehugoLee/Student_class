// Student s[10] �迭�� �̿��� show ���
#include <iostream>
#include <time.h>
#include "Student2.h"

using namespace std;

int FindMin(Student s[3], int subj)
{
	int ret = 0;
	int MIN = s[0].getGrade(subj);
	for (int i = 0; i < CNT; i++)
	{
		if (MIN > s[i].getGrade(subj))
		{
			MIN = s[i].getGrade(subj);
			ret = i;
		}
	}
	return ret;
}

int main()
{
	srand((unsigned int)time(NULL));
	Student s[10];
	string name[10] = {
		"������", "������", "��û��", "������","������",
		"�����", "�����","�ֳ���","������","������"

	};
	for (int i = 0; i < 10; i++)
	{
		s[i].setName(name[i]);
		s[i].initStudent();
	}

	int t = FindMin(s, KOR);
	printf("���� ���� ���� �л�\n");
	s[t].show();
}
