#pragma once
#include <initializer_list>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cstdarg>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Sort
{
    vector<int> v;
public:
    Sort(int n, int min, int max);
    Sort(initializer_list<int> list);
    Sort(vector<int>a, int n);
    Sort(int n, ...);
    Sort(const char* s);
    void InsertSort(bool ascendent = false);
    void QuickSort( bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

