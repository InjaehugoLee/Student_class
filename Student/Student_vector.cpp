// vector <student *> vec;  ���͸� �̿��� show ���
#include <iostream>
#include <time.h>
#include <vector>
#include "Student_test.h"

using namespace std;
string name[3]{
	"ȫ�浿","ȫ�ϵ�","ȫ�̵�"
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
	//// ��ü
	//Student a;
	//a.show();

	//// ������
	//Student* b;
	//b->show();
	//(*b).show();

	srand((unsigned int)time(NULL));
	vector <Student*> vec;

	// Student* s1�� �ּҸ� ����Ű�� �������̹Ƿ� ���� �̸��� �ᵵ ����, ����Ű�� ���� ���ϹǷ�.
	for (int i = 0; i < 3; i++) {
		Student* s1 = new Student(name[i]);
		s1->initStudent();
		s1->show();
		vec.push_back(s1);
	}

	//Student* s2 = new Student("ȫ�̵�");
	//s2->initStudent();
	//s2->show();
	//vec.push_back(s2);

	//Student* s3 = new Student("ȫ�ﵿ");
	//s3->initStudent();
	//s3->show();
	//vec.push_back(s3);

	//Student* p = FindMin(vec);
	int i = FindMin(vec, KOR);
	printf("���� ���� ���� �л�\n");
	vec[i]->show();
	//p->show();

	printf("==========================\n");
	Student* k = FindMax(vec, KOR);
	printf("���� �ְ� ���� �л�\n");
	k->show();
	

	for (auto t : vec) delete t;
	vec.clear();

}
