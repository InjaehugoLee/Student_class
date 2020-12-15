// vector <student *> vec;  벡터를 이용한 show 출력
#include <iostream>
#include <time.h>
#include <vector>
#include "Student_test.h"

using namespace std;
string name[3]{
	"홍길동","홍일동","홍이동"
};


//Student* FindMin(vector<Student*> &vec)
//{
//	Student* ret = NULL;
//	int MIN = 100;
//	for (auto t :vec)
//	{
//		if (MIN > t->getGrade(KOR))
//		{
//			MIN = t->getGrade(KOR);
//			ret = t;
//		}
//	}
//	return ret;
//}

Student* FindMax(vector <Student*> vec, int n)
{
	Student* ret = NULL;
	int MIN = vec[0]->getGrade(n);
	for (auto t : vec)
	{
		if (MIN < t->getGrade(n))
		{
			ret = t;
		}
	}
	return ret;
}

int FindMin(vector<Student*>& vec, int n)
{
	int ret=0;
	for (int i=1; i<3; i++)
	{
		if (vec[ret]->getGrade(n) > vec[i]->getGrade(n))
		{
			ret = i;
		}
	}
	return ret;
}

int main()
{
	//// 객체
	//Student a;
	//a.show();

	//// 포인터
	//Student* b;
	//b->show();
	//(*b).show();

	srand((unsigned int)time(NULL));
	vector <Student*> vec;

	// Student* s1은 주소를 가리키는 포인터이므로 같은 이름을 써도 무방, 가리키는 값이 변하므로.
	for (int i = 0; i < 3; i++) {
		Student* s1 = new Student(name[i]);
		s1->initStudent();
		s1->show();
		vec.push_back(s1);
	}

	//Student* s2 = new Student("홍이동");
	//s2->initStudent();
	//s2->show();
	//vec.push_back(s2);

	//Student* s3 = new Student("홍삼동");
	//s3->initStudent();
	//s3->show();
	//vec.push_back(s3);

	//Student* p = FindMin(vec);
	int i = FindMin(vec, KOR);
	printf("국어 최저 득점 학생\n");
	vec[i]->show();
	//p->show();

	printf("==========================\n");
	Student* k = FindMax(vec, KOR);
	printf("국어 최고 득점 학생\n");
	k->show();
	

	for (auto t : vec) delete t;
	vec.clear();

}
