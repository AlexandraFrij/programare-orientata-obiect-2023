#include "Math.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;
}

double Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

double Math::Mul(double a, double b)
{
	return a * b;
}

double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list list;
	va_start(list, count);
	int sum = 0;
	for (int i = 0; i < count; i++)
		sum += va_arg(list, int);
	return sum;
}

char* Math::Add(const char* c1, const char* c2)
{
	if(c1 == nullptr || c2 == nullptr)
		return nullptr;
	int length1 = sizeof(c1);
	int length2 = sizeof(c2);
	char* c3 = new char[length1 + length2];
	strcpy(c3, c1);
	strcat(c3, c2);
	return c3;
	delete[] c3;
}

