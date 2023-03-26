#include "Number.h"

Number::Number(const char* value, int base)
{
	number = new char[100];
	strcpy(this->number, value);
	this->base = base;
}

Number::~Number()
{
	if(number != nullptr)
		delete[] number;
}

Number::Number(const Number& a)
{
	number = new char[100];
	printf("Copy constructor\n");
	strcpy(number, a.number);
	base = a.base;
}

Number::Number(Number&& a)
{
	printf("Move constructor\n");
	number = a.number;
	base = a.base;
	a.number = nullptr;
}

int convertToBase10(char* n, int b)
{
	int num = 0;
	int power = 1;
	char* copy = n;
	for (int i = strlen(copy) - 1; i >= 0; i--)
	{
		int digit;
		if (copy[i] >= '0' && copy[i] <= '9')
			digit = copy[i] - '0';
		else digit = copy[i] - 'A' + 10;
		if (i == strlen(copy) - 1)
			num = digit;
		else
		{
			num = num + digit * power;
			power = power * b;
		}
	}
	return num;
}
char* convertFromBase10(int num, int b)
{ 
	char* value = new char[100];
	int i = 0;
	while (num != 0)
	{ 
		if (num % b < 10)
			value[i] = (num % b) + '0';
		else value[i] = (num % b - 10) + 'A';
		i++;
		num = num / b;
	}
	value[i] = '\0';
	std::reverse(value, value+i);
	return value;

}
Number operator+(Number a, Number b)
{
	if (a.base > b.base)
	{
		char* value;
		int num1 = convertToBase10(b.number, b.base);
		int num2 = convertToBase10(a.number, a.base);
		int sum = num1 + num2;
		value = convertFromBase10(sum, a.base);
		return Number(value, a.base);
	}
	else
	{
		char* value;
		int num1 = convertToBase10(b.number, b.base);
		int num2 = convertToBase10(a.number, a.base);
		int sum = num1 + num2;
		value = convertFromBase10(sum, b.base);
		return Number(value, a.base);
	}
}

Number operator-(Number a, Number b)
{
	if (a.base > b.base)
	{
		char* value;
		int num1 = convertToBase10(b.number, b.base);
		int num2 = convertToBase10(a.number, a.base);
		int dif = abs(num1 - num2);
		value = convertFromBase10(dif, a.base);
		return Number(value, a.base);
	}
	else
	{
		char* value;
		int num1 = convertToBase10(b.number, b.base);
		int num2 = convertToBase10(a.number, a.base);
		int dif = abs(num1 - num2);
		value = convertFromBase10(dif, b.base);
		return Number(value, a.base);
	}
}
bool Number::operator>(Number a)
{
	int num1 = convertToBase10(a.number, a.base);
	int num2 = convertToBase10(number, base);
	if (num2 > num1) return true;
	else return false;
}

bool Number::operator<(Number a)
{
	int num1 = convertToBase10(a.number, a.base);
	int num2 = convertToBase10(number, base);
	if (num2 < num1) return true;
	else return false;
}

bool Number::operator>=(Number a)
{
	int num1 = convertToBase10(a.number, a.base);
	int num2 = convertToBase10(number, base);
	if (num2 >= num1) return true;
	else return false;
}

bool Number::operator<=(Number a)
{
	int num1 = convertToBase10(a.number, a.base);
	int num2 = convertToBase10(number, base);
	if (num2 <= num1) return true;
	else return false;
}

bool Number::operator==(Number a)
{
	int num1 = convertToBase10(a.number, a.base);
	int num2 = convertToBase10(number, base);
	if (num2 == num1) return true;
	else return false;
}

char Number::operator[](int index)
{
	if(index >= 0 && index < strlen(number))
		return number[index];
}

Number& Number::operator--()
{
	printf("Prefix\n");
	char* temp = new char[strlen(number)];
	strcpy(temp, number + 1);
	strcpy(number, temp);
	return *this;
}

Number& Number::operator--(int)
{
	printf("Postfix\n");
	char* temp = new char[strlen(number)];
	strncpy(temp, number, strlen(number)-1);
	temp[strlen(number) - 1] = '\0';
	strcpy(number, temp);
	return *this;
}

Number& Number::operator=(Number&& a)
{
	printf("Move assignment\n");
	number = a.number;
	base = a.base;
	a.number = nullptr;
	return *this;
}

Number& Number::operator=(const char* s)
{
	printf("Move assignment\n");
	delete[] number;
	number = new char[100];
	strcpy(number,s);
	delete[] s;
	return *this;
}

Number& Number::operator=(int n)
{
	printf("Move assignment\n");
	char* num = new char[100];
	int i = 0;
	while (n != 0)
	{
		num[i] = n % 10 + '0';
		i++;
		n = n / 10;
	}
	num[i] = '\0';
	std::reverse(num, num + i);
	delete[] number;
	number = new char[100];
	strcpy(number, num);
	base = 10;
	return *this;
}

Number& Number::operator+=(const Number& n)
{
	int b;
	if (this->base > n.base)
		b = this->base;
	else b = n.base;
	int num1 = convertToBase10(this->number, this->base );
	int num2 = convertToBase10(n.number, n.base);
	this->base = b;
	char* c = convertFromBase10(num1 + num2, this->base);
	delete[] this->number;
	strcpy(this->number, c);
	return *this;
}

Number& Number::operator-=(const Number& n)
{
	int b;
	if (this->base > n.base)
		b = this->base;
	else b = n.base;
	int num1 = convertToBase10(this->number, this->base);
	int num2 = convertToBase10(n.number, n.base);
	this->base = b;
	char* c = convertFromBase10(abs(num1 - num2), this->base);
	delete[] this->number;
	strcpy(this->number, c);
	return *this;
}

void Number::SwitchBase(int newBase)
{
	int num = convertToBase10(number, base);
	char* value = convertFromBase10(num, newBase);
	base = newBase;
	strcpy(number, value);
}

void Number::Print()
{
	printf("%s%d\n", "The base is: ", base);
	printf("%s%s\n", "The representation is: ", number);
}

int Number::GetDigitsCount()
{
	return strlen(number);
}

int Number::GetBase()
{
	return base;
}
