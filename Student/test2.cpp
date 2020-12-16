#include <iostream>
#include <time.h>

using namespace std;
//
//#define SUBJCNT 3
//string subjnames[SUBJCNT] = { "KOR", "ENG", "MAT" };
//
//class Student
//{
//private:
//	string name;
//	int grades[SUBJCNT];
//public:
//	Student(string _name = "")
//	{
//		name = _name;
//		memset(grades, 0, sizeof(int) * SUBJCNT);
//	};
//	~Student() {}
//	void initStudent()
//	{
//		for (int i = 0; i < SUBJCNT; i++)
//		{
//			grades[i] = rand() % 101;
//		}
//	}
//	void setName(string _name) { name = _name; }
//	int getGrade(int i) { return grades[i]; }
//	void show(int idx)
//	{
//		printf("\t%s : %s : %d\n", name.c_str(), subjnames[idx].c_str(), grades[idx]);
//	}
//};
//
//class Classes
//{
//	Student* sp;
//	int NOS;
//
//	void init(string* stunames)
//	{
//		for (int i = 0; i < NOS; i++)
//		{
//			sp->initStudent();
//			(sp + 1)->initStudent();
//			sp[i].setName(stunames[i]);
//			sp[i].initStudent();
//		}
//	}
//public:
//	Classes(string* stunames, int num)
//	{
//		NOS = num;
//		sp = new Student[num];
//		init(stunames);
//	}
//	~Classes()
//	{
//		delete[] sp;
//	}
//	int FindMax(int idx)
//	{
//		int ret = 0;
//		for (int i = 0; i < NOS; i++)
//			if (sp[i].getGrade(idx) > sp[ret].getGrade(idx))
//				ret = i;
//		return ret;
//	}
//	int FindMin(int idx)
//	{
//		int ret = 0;
//		for (int i = 0; i < NOS; i++)
//			if (sp[i].getGrade(idx) < sp[ret].getGrade(idx))
//				ret = i;
//			return ret;
//	}
//	void show(int idx, int ti)
//	{
//		sp[idx].show(ti);
//	}
//};
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	string stunames[] = {
//		"全老悼", "全捞悼", "全伙悼","全荤悼" ,"全坷悼",
//		"全腊悼", "全磨悼", "全迫悼", "全备悼","全绞悼"
//	};
//	int num = sizeof(stunames) / sizeof(string);
//
//	Classes cls(stunames, num);
//
//	for (int i = 0; i < SUBJCNT; i++)
//	{
//		int t1 = cls.FindMax(i);
//		int t2 = cls.FindMin(i);
//
//		printf("=====================================\n");
//		printf("%s Max\n", subjnames[i].c_str());
//		cls.show(t1, i);
//		printf("%s Min\n", subjnames[i].c_str());
//		cls.show(t2, i);
//	}
//
//
//}

typedef struct _mypt
{
	int x, y;
}MYPT;

int main()
{
	MYPT* p = new MYPT[2];

	p[0].x = 1;
	p[0].y = 1;
	p->x = 2;
	p->y = 2;

	p[1].x = 2;
	p[1].y = 2;
	(p + 1)->x = 3;
	(p + 1)->y = 3;

	delete[] p;

	MYPT* q[2];
	q[0] = new MYPT;
	q[1] = new MYPT;

	q[0]->x = 1;
	q[0]->y = 2;
	q[1]->x = 1;
	q[1]->y = 2;

	delete q[0];
	delete q[1];
}