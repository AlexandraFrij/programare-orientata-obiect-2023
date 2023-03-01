#include "Compare.h"
#include <cstring>
int Compare::CompareName(Student a, Student b)
{
	return strcmp(a.GetName(), b.GetName());
}
int Compare::CompareMath(Student a, Student b)
{
	if (a.GetMath() > b.GetMath())
		return 1;
	else
		if (a.GetMath() == b.GetMath())
			return 0;
	else return -1;
}
int Compare::CompareEnglish(Student a, Student b)
{
	if (a.GetEnglish() > b.GetEnglish())
		return 1;
	else
		if (a.GetEnglish() == b.GetEnglish())
			return 0;
		else return -1;
}
int Compare::CompareHistory(Student a, Student b)
{
	if (a.GetHistory() > b.GetHistory())
		return 1;
	else
		if (a.GetHistory() == b.GetHistory())
			return 0;
		else return -1;
}
int Compare::CompareAverage(Student a, Student b)
{
	if (a.CalculateAverage() > b.CalculateAverage())
		return 1;
	else
		if (a.CalculateAverage() == b.CalculateAverage())
			return 0;
		else return -1;
}
