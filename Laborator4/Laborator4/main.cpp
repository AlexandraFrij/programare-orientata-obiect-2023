#include <iostream>
#include "Sort.h"
using namespace std;
int main()
{
	bool ascendent;
	vector <int> v = { 12, 89, 45,22,13 };
	Sort v1(4, 12, 35);
	v1.Print();
	cout << endl;
	cout << v1.GetElementsCount() << endl;
	Sort v2({3,6,1,9,2});
	v2.Print();
	cout << endl;
	Sort v3(v, 5);
	v3.Print();
	cout << endl;
	Sort v4(5, 67, 23, 1, 34, 45);
	v4.Print();
	cout << endl;
	cout << v4.GetElementFromIndex(2) << endl;
	Sort v5("10,40,100,5,70");
	v5.Print();
	cout << endl;
	v1.BubbleSort(ascendent = true);
	v1.Print();
	cout << endl;
	cout << "bubble sort" << endl;
	v2.InsertSort(ascendent = false);
	v2.Print();
	cout << endl;
	cout << "insert sort" << endl;
	v3.QuickSort(ascendent = true);
	v3.Print();
	cout << endl;
	cout << "quick sort" << endl;

	return 0;

}