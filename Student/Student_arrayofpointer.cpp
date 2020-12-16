// Student *s[10]; Arrays of pointer를 이용한 show 출력
#include <iostream>
#include <time.h>
#include <vector>
#include "Student3.h"

using namespace std;

string name[3]{
	"홍길동","홍일동","홍이동"
};

int FindMin(Student* s[3], int n)
{
	int ret = 0;
	for (int i = 0; i < 3; i++)
	{
		if (s[ret]->getGrade(KOR) > s[i]->getGrade(KOR))
			ret = i;
	}
	return ret;
}

int main()
{
	srand((unsigned int)time(NULL));
	Student* s[3];
	s[0]= new Student("이인재");
	s[1]= new Student("조용운");
	s[2]= new Student("주나현");
	s[0]->initStudent();
	s[1]->initStudent();
	s[2]->initStudent();
	int i = FindMin(s, KOR);
	printf("국어 최저 득점 학생\n");
	
	s[i]->show();
	for (auto t : s) delete t;
}
