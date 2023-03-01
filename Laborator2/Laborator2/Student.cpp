#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;

void Student::SetName(const char* name)
{
	this->name = name;
}
const char* Student::GetName()
{
	return name;
}
void Student::SetMath(float math)
{
	if (math < 1 || math > 10)
		return;
	this->math = math;
}
float Student::GetMath()
{
	return math;
}
void Student::SetEnglish(float english)
{
	if (english < 1 || english > 10)
		return;
	this->english = english;
}
float Student::GetEnglish()
{
	return english;
}
void Student::SetHistory(float history)
{
	if (history < 1 || history > 10)
		return;
	this->history = history;
}
float Student::GetHistory()
{
	return history;
}
float Student::CalculateAverage()
{
	float avg;
	avg = (math + history + english) / 3;
	return avg;
}