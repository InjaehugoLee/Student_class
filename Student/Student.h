// Student s;  Stack에 저장해서 show로 출력 헤더파일
// Student *s = new Student;  Heap에 저장해서 show로 출력 헤더파일
#include <string>
using namespace std;

#define CNT 5   // 과목수

#define KOR   0   // 국
#define ENG   1   // 영
#define MAT   2   // 수
#define SCI   3   // 과
#define GEO   4   // 지

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

	void initStudent(string _name)
	{
		name = _name;
		for (int i = 0; i < CNT; i++)
		{
			grades[i] = rand() % 101;
		}
	}
	void show()
	{

		cout << "이름: " << name << endl;
		cout << "국어" << "\t" << "영어" << "\t" << "수학" << "\t" << "과학" << "\t" << "지리" << endl;
		for (int i = 0; i < CNT; i++)
		{
			cout << grades[i] << "\t";
		}
		cout << endl << endl;
	}
};