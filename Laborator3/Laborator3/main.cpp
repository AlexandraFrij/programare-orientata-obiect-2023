#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>
#include "Math.h"
#include "Canvas.h"

int main()
{
	printf("%d\n", Math::Add(34, 12));
	printf("%d\n", Math::Add(12, 12, 12));
	printf("%f\n", Math::Add(12.2, 1.2));
	printf("%f\n", Math::Add(10.1, 11.2, 12.3));
	printf("%d\n", Math::Mul(3, 4));
	printf("%d\n", Math::Mul(3, 4, 5));
	printf("%f\n", Math::Mul(3.1, 4.0));
	printf("%f\n", Math::Mul(1.2, 2.2, 1.0));
	printf("%d\n", Math::Add(5, 1, 2, 3, 4, 5));
	printf("%s\n", Math::Add("hello ", "world!"));
	Canvas* canvas1 = new Canvas(20, 20);
	canvas1->DrawCircle(9, 1, 1 , '*');
	canvas1->Print();
	canvas1->FillCircle(9, 1, 1, '*');
	canvas1->Print();
	Canvas* canvas2 = new Canvas(20, 20);
	canvas2->DrawLine(1, 2, 1, 12, '*');
	canvas2->Print();
	Canvas* canvas3 = new Canvas(20, 20);
	canvas3->DrawRect(2, 2, 18, 18, '*');
	canvas3->Print();
	canvas3->FillRect(2, 2, 18, 18, '*');
	canvas3->Print();
	canvas3->SetPoint(6, 6, '&');
	canvas3->Print();
	canvas3->Clear();
	return 0;

}