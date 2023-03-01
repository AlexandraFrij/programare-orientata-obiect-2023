#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "NumberList.h"
#include "Student.h"
#include "Compare.h"
using namespace std;

int main()
{
	NumberList number;
	number.Init();
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			number.Add(i * 2 + 1);
		else
			number.Add(i);
	}
	number.Sort();
	number.Print();
	cout << endl;
	Student a;
	Student b;
	a.SetName("Ioana");
	const char* name = a.GetName();
	cout << "Name: " << name << endl;
	a.SetMath(4.55);
	float math = a.GetMath();
	cout << "Math: " << math << endl;
	a.SetEnglish(8.6);
	float english = a.GetEnglish();
	cout << "English: " << english << endl;
	a.SetHistory(7.2);
	float history = a.GetHistory();
	cout << "History: " << history << endl;
	float avg = a.CalculateAverage();
	cout << "Average: " << avg;

	b.SetName("Claudia");
	b.SetMath(8.4);
	b.SetEnglish(7.8);
	b.SetHistory(7.2);
	a.CalculateAverage();

	Compare compare;
	cout << "Compare names: " << compare.CompareName(a, b) << endl;
	cout << "Compare math: " << compare.CompareMath(a, b) << endl;
	cout << "Compare english: " << compare.CompareEnglish(a, b) << endl;
	cout << "Compare history: " << compare.CompareHistory(a, b) << endl;
	cout << "Compare average: " << compare.CompareAverage(a, b) << endl;


	return 0;
}