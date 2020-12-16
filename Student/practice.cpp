#include <iostream>
#include <time.h>

using namespace std;

#define SUBJCNT 3
string subjnames[SUBJCNT] = { "KOR", "ENG", "MAT" };
#define STUDENTCOUNT 5
string stunames[STUDENTCOUNT] = { "È«±æµ¿", "È«ÀÌµ¿", "È«»ïµ¿", "È«»çµ¿", "È«¿Àµ¿" };

class student
{
private:
	string name;
	int grades[SUBJCNT];
public:
	student() {};
	~student() {};

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

		printf("\t%s %s %d\n", name.c_str(), subjnames[idx].c_str(), grades[idx]);
	};
};

class student_s
{
	student s[STUDENTCOUNT];
public:
	void init_student_s()
	{
		for (int i = 0; i < STUDENTCOUNT; i++)
		{
			s[i].setname(stunames[i]);
			s[i].initstudent();
		}
	};

	int findMax(int idx)
	{
		int ret = 0;
		for (int i = 1; i < STUDENTCOUNT; i++)
			if (s[ret].getgrade(idx) < s[i].getgrade(idx))
				ret = i;
		return ret;
	}

	int findMin(int idx)
	{
		int ret = 0;
		for (int i = 1; i < STUDENTCOUNT; i++)
			if (s[ret].getgrade(idx) > s[i].getgrade(idx))
				ret = i;
		return ret;
	}

	void show_student_s(int idx, int i)
	{
		s[idx].show(i);
	}
};

int main()
{
	srand((unsigned int)time(NULL));
	student_s s1;
	s1.init_student_s();

	for (int i = 0; i < SUBJCNT; i++)
	{
	
		int a1=s1.findMax(i);
		int a2=s1.findMin(i);
		printf("====================================\n");
		printf("%s Max\n", subjnames[i].c_str());
		s1.show_student_s(a1, i);
		printf("%s Min\n", subjnames[i].c_str());
		s1.show_student_s(a2, i);

	}
	
}