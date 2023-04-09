#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;

template<typename T>
class Vector
{
private:
	T v[100];
	int count = 0;
public:
	void remove(int index)
	{
		if (index < 0 || index >= count)
			printf("Index not valid");
		else {
			for (int i = index; i < count - 1; i++)
				v[i] = v[i + 1];
			delete v[count - 1];
			count--;
		}
	}

	void print()
	{
		for (int i = 0; i < count; i++)
			cout << v[i] << ' ';
	}
	void insert(int index, T value)
	{
		if (index < 0 || index > count)
			printf("Index not valid");
		else {
			v[index] = value;
			if (index == count) count++;
		}
	}
	T operator[](int index)
	{
		if (index >= 0 && index < count)
			return v[index];
		else return -1;
	}
	Vector(const Vector& v1) {
		v = new T[100];
		printf("Copy constructor\n");
		for (int i = 0; i < v1.count; i++)
			v[i] = v1[i];
		count = v1.count;
	}
	Vector(Vector&& v1)
	{
		printf("Move constructor\n");
		for (int i = count; i < count + v1.count; i++)
			v[i] = v1[i - count];
		count += v1.count;
	}
	


};

