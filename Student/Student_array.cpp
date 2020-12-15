// Student s[10] 배열을 이용한 show 출력
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
		"조영평", "서여진", "남청우", "김현우","정진영",
		"조용운", "김재민","주나현","이인재","이진욱"

	};
	for (int i = 0; i < 10; i++)
	{
		s[i].setName(name[i]);
		s[i].initStudent();
	}

	int t = FindMin(s, KOR);
	printf("국어 최저 득점 학생\n");
	s[t].show();
}
