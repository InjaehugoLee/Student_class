// Student s;  Stack에 저장해서 show로 출력 (객체를 바로 만듦)
#include <iostream>
#include "Student.h"

int main()
{
	Student s1;
	s1.initStudent("이인재");
	s1.show();

	Student s2;
	s2.initStudent("김재민");
	s2.show();

	Student s3;
	s3.initStudent("조용운");
	s3.show();


	return 0;
}