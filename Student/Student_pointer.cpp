#include <iostream>
#include <time.h>

using namespace std;

#define SUBJCNT 3
string subjnames[SUBJCNT] = { "KOR", "ENG", "MAT" };

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
	void setName(string _name) { name = _name; }
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
	Student *sp;
	int NOS;

	void init(string* stunames)
	{
		for (int i = 0; i < NOS; i++)
		{
			sp[i].setName(stunames[i]);
			sp[i].initStudent();
		}
	}

public:
	Classes(string* stunames, int num)
	{
		NOS = num;
		sp = new Student[num];
		init(stunames);
	}
	~Classes()
	{
		delete[] sp;
	}

	int FindMax(int idx)	// idx��° ������ �ְ����� �˻��ؼ� �л��� �ε����� �����Ѵ�.
	{
		int ret = 0;
		for (int i = 1; i < NOS; i++)
			if (sp[i].getGrade(idx) > sp[ret].getGrade(idx))
				ret = i;
		return ret;
	}
	int FindMin(int idx)	// idx��° ������ �������� �˻��ؼ� �л��� �ε����� �����Ѵ�.
	{
		int ret = 0;
		for (int i = 1; i < NOS; i++)
			if (sp[i].getGrade(idx) < sp[ret].getGrade(idx))
				ret = i;
		return ret;
	}
	void show(int idx, int ti)	// idx��° �л��� ti��° ������ ������ ����Ѵ�.
	{
		sp[idx].show(ti);
	}
};

int main()
{
	srand((unsigned int)time(NULL));

	string stunames[] = {
		"ȫ�浿", "ȫ�̵�", "ȫ�ﵿ", "ȫ�絿", "ȫ����",
		"ȫ����", "ȫĥ��", "ȫ�ȵ�", "ȫ����", "ȫ�ʵ�"
	};
	int num = sizeof(stunames) / sizeof(string);


	Classes cls(stunames, num);

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

