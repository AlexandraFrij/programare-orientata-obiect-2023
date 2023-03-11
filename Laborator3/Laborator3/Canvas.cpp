#include "Canvas.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cstdlib>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	canvas = new char*[height];
	for (int i = 0; i < height; i++)
		canvas[i] = new char[width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			canvas[i][j] = ' ';
}

Canvas::~Canvas()
{
	for (int i = 0; i < height; i++)
		delete[] canvas[i];
	delete[] canvas;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
				if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
					canvas[i][j] = ch;

}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
				canvas[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i == top && j >= left && j <= right)
				canvas[i][j] = ch;
			else if (i == bottom && j >= left && j <= right)
				canvas[i][j] = ch;
			else if (j == left && i > top && i <= bottom)
				canvas[i][j] = ch;
			else if (j == right && i > top && i <= bottom)
				canvas[i][j] = ch;
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			if (i >= top && i <= bottom && j >= left && j <= right)
				canvas[i][j] = ch;
}

void Canvas::SetPoint(int x, int y, char ch)
{
	canvas[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	if (y1 == y2)
		for (int i = x1; i <= x2; i++ )
				canvas[y1][i] = ch;
	else if(x1 == x2)
	{ 
		for (int i = y1; i <= y2; i++)
			canvas[i][x1] = ch;
	}
}

void Canvas::Print()
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%c", canvas[i][j]);
		printf("%c", '\n');
	}
}

void Canvas::Clear()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			canvas[i][j] = ' ';
}
