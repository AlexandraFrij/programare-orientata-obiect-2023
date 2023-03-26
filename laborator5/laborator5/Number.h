#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <string.h>
#include <iostream>
#include <algorithm>
class Number

{
	// add data members
	char* number ;
	int base;

public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& a);
	Number(Number&& a);
	// add operators and copy/move constructor
	friend Number operator+(Number a, Number b);
	friend Number operator-(Number a, Number b);
	bool operator>(Number a);
	bool operator<(Number a);
	bool operator>=(Number a);
	bool operator<=(Number a);
	bool operator==(Number a);
	char operator[](int index);
	Number& operator--();
	Number& operator--(int);
	Number& operator=(Number&& a);
	Number& operator=(const char* s);
	Number& operator=(int n);
	Number& operator+=(const Number& n);
	Number& operator-=(const Number& n);
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base

};

