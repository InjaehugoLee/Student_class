#include <iostream>
#include <time.h>

using namespace std;

#define SUBJCNT 3
string subjnames[SUBJCNT] = { "KOR", "ENG", "MAT" };
#define STUDENTCOUNT 5
string stunames[STUDENTCOUNT] = { "홍길동", "홍이동", "홍삼동", "홍사동", "홍오동" };

class student
{
private:
	string name;
	int grades[SUBJCNT];
public:
	student() {}
	~student() {}

	void initstudent() 
	{
		for (int i = 0; i < SUBJCNT; i++)
		{
			grades[i] = rand() % 101;
		}
	};
	void setname(string _name) { name = _name; }
	int getgrade(int i) { return grades[i]; }
	void show(int idx) 
	{
		printf("\t%s %s %d\n", name.c_str(), subjnames[0].c_str(), grades[idx]);
	}
};

class classes
{
	student *s[STUDENTCOUNT];
public:
	classes() {}
	~classes() 
	{
		for (int i = 0; i < STUDENTCOUNT; i++)
		{
			delete s[i];
		}
	}

	void init(string stunames[],int count) 
	{
		for (int i = 0; i < STUDENTCOUNT; i++)
		{
			s[i] = new student;
			s[i]->setname(stunames[i]);
			s[i]->initstudent();
		}
	
	};
	int findMax(int idx) 
	{
		int ret = 0;
		for (int i = 1; i < STUDENTCOUNT; i++)
		{
			if (s[ret]->getgrade(idx) < s[i]->getgrade(idx))
				ret = i;
		}
		return ret;
	};
	int findMin(int idx) 
	{
		int ret = 0;
		for (int i = 1; i < STUDENTCOUNT; i++)
		{
			if (s[ret]->getgrade(idx) > s[i]->getgrade(idx))
				ret = i;
		}
		return ret;
	
	};
	void show(int idx, int ti) 
	{
		s[idx]->show(ti);
	};
};

int main()
{
	srand((unsigned int)time(NULL));
	classes cls;
	cls.init(stunames, STUDENTCOUNT);

	// 최고점수 출력
	// 최저점수 출력

	for (int i = 0; i < SUBJCNT; i++)
	{
		int t1 = cls.findMax(i);
		int t2 = cls.findMin(i);

		printf("===============================================\n");
		printf("%s Max\n", subjnames[i].c_str());
		cls.show(t1, i);
		printf("%s Min\n", subjnames[i].c_str());
		cls.show(t2, i);
	}
	
}