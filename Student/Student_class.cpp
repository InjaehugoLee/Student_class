// vector <student *> vec;  ���͸� �̿��� show ���
#include <iostream>
#include <time.h>
#include <vector>
#include "Student_test.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	Students s;
	s.InitializeStudents();
	int i = s.FindMIN(KOR);
	printf("=======================================");
	printf("\n");
	printf("���� ���� ���� �л�\n");
	s.vec[i]->show();
	
	
	int j = s.FindMAX(KOR);
	printf("=======================================");
	printf("\n");
	printf("���� �ְ� ���� �л�\n");
	s.vec[j]->show();

	for (auto t : s.vec) delete t;
	s.vec.clear();
}
