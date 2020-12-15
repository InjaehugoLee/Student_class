// vector <student *> vec;  벡터를 이용한 show 출력 헤더 파일
#include <iostream>
#include <string>
using namespace std;

#define CNT 5   // 과목수

#define KOR   0   // 국
#define ENG   1   // 영
#define MAT   2   // 수
#define SCI   3   // 과
#define GEO   4   // 지

string subjTitles[CNT] =
{ "국어", "영어", "수학", "과학", "지리" };

class Student
{
private:
	string name;
	int grades[CNT];

public:
	Student(string _name = "")
	{
		name = _name;
		memset(grades, 0, sizeof(int) * CNT);
	}
	~Student() {}

	void setName(string _name)
	{
		name = _name;
	}
	void initStudent()
	{
		for (int i = 0; i < CNT; i++)
		{
			grades[i] = rand() % 101;
		}
	}
	int getGrade(int i) { return grades[i]; }

	void show()
	{
		printf("%s : ", name.c_str());
		for (int i = 0; i < CNT; i++)
		{
			printf("%5d", grades[i]);
		}
		printf("\n");
	}
};