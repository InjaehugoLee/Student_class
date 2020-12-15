// Student *s = new Student;  Heap에 저장해서 show로 출력
#include <iostream>
#include "Student.h"

int main()
{
	Student *s1 = new Student ;
	s1->initStudent("이인재");
	s1->show();
	delete(s1);

	Student* s2 = new Student;
	s2->initStudent("김재민");
	s2->show();
	delete(s2);

	Student* s3 = new Student;
	s3->initStudent("조용운");
	s3->show();
	delete(s3);

	Student* s4 = new Student;
	s4->initStudent("조영평");
	s4->show();
	delete(s4);

	return 0;
}