#include "Sort.h"
#define _CRT_SECURE_NO_WARNINGS

Sort::Sort(int n, int min, int max)
{
	v.reserve(n);
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		int x = min + (rand() % (max - min - 1));
		v.push_back(x);
	}
}

Sort::Sort(initializer_list<int> list)
{
	v.reserve(list.size());
	for (int x : list)
	{
		v.push_back(x);
	}
}

Sort::Sort(vector<int> a, int n)
{
	v.reserve(n);
	for (int i = 0; i < n; i++)
		v.push_back(a[i]);
}

Sort::Sort(int n, ...)
{
	v.reserve(n);
	va_list list;
	va_start(list, n);
	for (int i = 0; i < n; ++i)
	{
		int x = va_arg(list, int);
		v.push_back(x);
	}
}

Sort::Sort(const char* s)
{
	char num[10] = { '\0' };
	int j = 0;
	v.reserve(100);
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] == ',')
		{
			int x = atoi(num);
			v.push_back(x);
			memset(num, '\0', sizeof(num));
			j = 0;
		}
		else
		{
			num[j] = s[i];
			j++;
		}
	}
	int x = atoi(num);
	v.push_back(x);
	
}

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < v.size(); i++)
	{
		int key = v[i];
		int j = i - 1;
		if (ascendent)
		{
			while (j >= 0 && v[j] > key)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[j + 1] = key;
		}
		else
		{
			while (j >= 0 && v[j] < key)
			{
				v[j + 1] = v[j];
				j = j - 1;
			}
			v[j + 1] = key;
		}
	}
}
int ascendingPartition(vector<int>v, int left, int right)
{
	int pivot = v[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
	{
		if (v[j] <= pivot)
		{
			i++;
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	int temp = v[i+1];
	v[i+1] = v[right];
	v[right] = temp;
	return i + 1;
}
int descendingPartition(vector<int>v, int left, int right)
{
	int pivot = v[left];
	int i = right + 1;
	for (int j = right; j > left; j--)
	{
		if (v[j] >= pivot)
		{
			i--;
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
	}
	int temp = v[i-1];
	v[i-1] = v[left];
	v[left] = temp;
	return i - 1;
}
void ascendingQuicksort(int left, int right, vector<int>v)
{
	if (left >= right)
		return;
	int pivot = ascendingPartition(v, left, right);
	ascendingQuicksort(left, pivot - 1, v);
	ascendingQuicksort(pivot + 1, right, v);
}
void descendingQuicksort(int left, int right, vector<int>v)
{
	if (left >= right)
		return;
	int pivot = descendingPartition(v, left, right);
	descendingQuicksort(left, pivot - 1, v);
	descendingQuicksort(pivot + 1, right, v);
}
void Sort::QuickSort( bool ascendent)
{

	if (ascendent)
		ascendingQuicksort(0, v.size() - 1, v);
	else descendingQuicksort(0, v.size() - 1, v);
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		int swapped = 0;
		for(int j = 0; j< (v.size()-i-1); j++)
			if (ascendent)
			{
				if (v[j] > v[j + 1])
				{
					int temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
					swapped = 1;
				}
			}
			else
			{

				if (v[j] < v[j + 1])
				{
					int temp = v[j];
					v[j] = v[j + 1];
					v[j + 1] = temp;
					swapped = 1;
				}
			}
		if (swapped == 0) break;
	}
}

void Sort::Print()
{
	for (int i = 0; i < v.size(); i++)
		printf("%d ", v[i]);
}

int Sort::GetElementsCount()
{
	return v.size();
}

int Sort::GetElementFromIndex(int index)
{
	return v[index];
}
