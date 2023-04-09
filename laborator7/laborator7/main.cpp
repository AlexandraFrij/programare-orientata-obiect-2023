#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include "Vector.h"
using namespace std;

float operator""_Kelvin(unsigned long long x) {
	return x - 273.15;
}
float operator""_Fahrenheit(unsigned long long x) {
	return (x- 32)/1.8;
}
int main()
{ 
	/*float a = 300_Kelvin;
	cout << a<<endl;
	float b = 120_Fahrenheit;
	cout <<b;*/
	Vector<int> v;
	return 0;

}
