// Fourier Series of a Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#define pi 3.14159265
long double function(long double x)
{
    return abs(sin(x));                          //WRITE YOUR FUNCTION HERE
}
long double a0Area(long double a, long double b,long double h=0.001)
{
    long double area = (function(a) + function(b)) * h / 2;
    for (long double i = a+h; i < b; i += h)
    {
        area += h * function(i);
    }
    return area;
}
long double anArea(long double a, long double b, int n,long double h=0.001)
{
    long double l{ (b - a) / 2 };
    long double area{ (h/2) * ((function(a) * cos(n * pi * a / l)) + (function(b) * cos(n*pi*b/l)))};
    for (long double i = a+h; i < b; i+=h)
    {
        area += h * function(i) * cos(n * pi * i / l);
    }
    return area;
}
long double bnArea(long double a, long double b, int n, long double h = 0.001)
{
    long double l{ (b - a) / 2 };
    long double area{ (h / 2) * ((function(a) * sin(n * pi * a / l)) + (function(b) * sin(n * pi * b / l))) };
    for (long double i = a + h; i < b; i += h)
    {
        area += h * function(i) * sin(n * pi * i / l);
    }
    return area;
}
int main()
{
    std::cout << "\t\n\tFOURIER SERIES FOR AN ARBITRARY FUNCTION\n";
    int n{ 10 };
    long double a{ 0 }, b{ 2 * pi }, l{ 0 };
    cout << "Enter the number of terms required: ";
    cin >> n;
    cout << "Enter the starting value: ";
    cin >> a;
    cout << "Enter the ending value: ";
    cin >> b;
    l = (b - a) / 2;
    cout << "f(x) = ";
    cout << a0Area(a, b, 0.0000001) / (b - a) << " + ";
    for (int i = 1; i <= n; i++)
    {
        cout << anArea(a, b, i, 0.0000001) * 2 / (b - a) << "cos(" << i * pi / l << "x)" << " + ";
        cout << bnArea(a, b, i, 0.0000001) * 2 / (b - a) << "sin(" << i * pi / l << "x)" << " + ";
    }
    cout << "\n\n\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
