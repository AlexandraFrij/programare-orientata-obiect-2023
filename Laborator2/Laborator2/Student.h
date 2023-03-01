#pragma once

class Student
{
	const char* name;
	float math;
	float english;
	float history;

public:
	void SetName(const char* name);
	const char* GetName();
	void SetMath(float math);
	float GetMath();
	void SetEnglish(float english);
	float GetEnglish();
	void SetHistory(float history);
	float GetHistory();
	float CalculateAverage();



};

