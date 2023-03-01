#pragma once
#include "Student.h"
class Compare
{
public:
	int CompareName(Student a, Student b);
	int CompareMath(Student a, Student b);
	int CompareEnglish(Student a, Student b);
	int CompareHistory(Student a, Student b);
	int CompareAverage(Student a, Student b);
};

