#include <iostream>
#include <time.h>

using namespace std;

#define SUBJCNT 3
string subjnames[SUBJCNT] = { "KOR", "ENG", "MAT" };
#define STUDENTCOUNT 5
string stunames[STUDENTCOUNT] = { "홍길동", "홍이동", "홍삼동", "홍사동", "홍오동" };

class Student
{
private:
	string name;
	int grades[SUBJCNT];

public:
	Student(string _name = "")
	{
		name = _name;
		memset(grades, 0, sizeof(int) * SUBJCNT);

	};
	~Student() {}
	void initStudent()
	{
		for (int i = 0; i < SUBJCNT; i++)
		{
			grades[i] = rand() % 101;
		}
	}
	void setName(string _name) { name = _name;  }
	int getGrade(int i) { return grades[i]; }
	void show()
	{
		cout << name << endl;
		for (int i = 0; i < SUBJCNT; i++)
		{
			printf("%s\t", subjnames[i].c_str());
		}
		cout << endl;
		for (int i = 0; i < SUBJCNT; i++)
		{
			printf("%d\t", grades[i]);
		}
		cout << endl;
	}
	void show(int idx)
	{
		printf("\t%s : %s : %d\n", name.c_str(), subjnames[idx].c_str(), grades[idx]);
	}
};

class Classes
{
	Student s[STUDENTCOUNT];
public:
	Classes() {}
	~Classes() {}
	void init(string stunames[], int count)
	{
		for (int i = 0; i < STUDENTCOUNT; i++)
		{
			s[i].setName(stunames[i]);
			s[i].initStudent();
		}
	}
	int FindMax(int idx)	// idx번째 과목의 최고점을 검색해서 학생의 인덱스를 리턴한다.
	{
		int ret = 0;
		for (int i = 1; i < STUDENTCOUNT; i++)
			if (s[i].getGrade(idx) > s[ret].getGrade(idx))
				ret = i;
		return ret;
	}
	int FindMin(int idx)	// idx번째 과목의 최저점을 검색해서 학생의 인덱스를 리턴한다.
	{
		int ret = 0;
		for (int i = 1; i < STUDENTCOUNT; i++)
			if (s[i].getGrade(idx) < s[ret].getGrade(idx))
				ret = i;
		return ret;
	}
	void show(int idx, int ti)	// idx번째 학생의 ti번째 과목의 점수를 출력한다.
	{
		s[idx].show(ti);
	}
};

int main()
{
	srand((unsigned int)time(NULL));

	Classes cls;
	cls.init(stunames, 5);

	//int t1 = cls.FindMax(0);
	//int t2 = cls.FindMin(0);

	//printf("KOR Max\n");
	//cls.show(t1, 0);
	//printf("KOR Min\n");
	//cls.show(t2, 0);

	for (int i = 0; i < SUBJCNT; i++)
	{
		int t1 = cls.FindMax(i);
		int t2 = cls.FindMin(i);

		printf("===============================================\n");
		printf("%s Max\n", subjnames[i].c_str());
		cls.show(t1, i);
		printf("%s Min\n", subjnames[i].c_str());
		cls.show(t2, i);
	}
}

