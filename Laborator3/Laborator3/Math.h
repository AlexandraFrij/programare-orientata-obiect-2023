#pragma once
class Math
{
public:
    static int Add(int a, int b);
    static int Add(int a, int b, int c);
    static double Add(double a, double b);
    static double Add(double a , double b, double c);
    static int Mul(int a, int b );
    static int Mul(int a, int b, int c);
    static double Mul(double a, double b);
    static double Mul(double a, double b, double c);
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char* c1, const char* c2);
};
