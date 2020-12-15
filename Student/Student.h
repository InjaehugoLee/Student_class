// Student s;  Stack�� �����ؼ� show�� ��� �������
// Student *s = new Student;  Heap�� �����ؼ� show�� ��� �������
#include <string>
using namespace std;

#define CNT 5   // �����

#define KOR   0   // ��
#define ENG   1   // ��
#define MAT   2   // ��
#define SCI   3   // ��
#define GEO   4   // ��

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

		cout << "�̸�: " << name << endl;
		cout << "����" << "\t" << "����" << "\t" << "����" << "\t" << "����" << "\t" << "����" << endl;
		for (int i = 0; i < CNT; i++)
		{
			cout << grades[i] << "\t";
		}
		cout << endl << endl;
	}
};