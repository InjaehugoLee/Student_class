#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define CNT 5
#define KOR 0
#define ENG 1
#define MAT 2
#define SCI 3
#define GEO 4
#define CNTNAME 10

string subject[5]{
	"±¹¾î", "¿µ¾î", "¼öÇÐ", "°úÇÐ", "Áö¸®"
};
string name[CNTNAME]{
	"È«ÀÏµ¿","È«ÀÌµ¿", "È«»ïµ¿", "È«»çµ¿", "È«¿Àµ¿", "È«À°µ¿", "È«Ä¥µ¿", "È«ÆÈµ¿", "È«±¸µ¿", "È«½Êµ¿"
};

class Student
{
private:
	string name;
	int grades[CNTNAME];

public:
	Student(string _name="") 
	{
		name = _name;
		memset(grades, 0, sizeof(int) * CNTNAME);
	
	};
	~Student() {}

	void initStudent()
	{
		for (int i = 0; i < CNTNAME; i++)
		{
			grades[i] = rand() % 101;
		}
	}

	int getGrade(int i) { return grades[i]; }

	void show()
	{
		cout << name << endl;
		for (int i = 0; i < CNT; i++) 
		{
			printf("%s\t", subject[i].c_str());
		}
		cout << endl;
		for (int i = 0; i < CNT; i++)
		{
			
			printf("%d\t", grades[i]);
		}
		cout << endl;
	}
};

class Students
{
public:
	vector<Student*>vec;
	Students() {}
	void InitializeStudents()
	{
		for (int i = 0; i < CNTNAME; i++) {
			Student* s1 = new Student(name[i]);
			s1->initStudent();
			s1->show();
			vec.push_back(s1);
		}
	};

	int FindMIN(int n)
	{
		int ret = 0;
		for (int i = 1; i < CNTNAME; i++)
		{
			if (vec[ret]->getGrade(n) > vec[i]->getGrade(n))
			{
				ret = i;
			}
		}
		return ret;
	};

	int FindMAX(int n)
	{

		int ret = 0;
		for (int i = 1; i < CNTNAME; i++)
		{
			if (vec[ret]->getGrade(n) < vec[i]->getGrade(n))
			{
				ret = i;
			}
		}
		return ret;
	};
};