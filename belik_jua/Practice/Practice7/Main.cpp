#pragma once
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    int i;
    double a;

    Vector v1;
    Vector v2(3);
    v2.Fill();
    Vector v3(3);
    v3.Fill();
    try 
    {
        v1 = v3 + v2;
        cout << "v1 = v2 + v1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    v1.PrintVector();
    v2.PrintVector();
    v3.PrintVector();

    try
    {
        v1 = v3 - v2;
        cout << "v1 = v2 - v1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    v1.PrintVector();

    v2 -= 5;
    cout << "v2 -= 5" << endl;
    v2.PrintVector();

    v2 += 10;
    cout << "v2 += 10" << endl;
    v2.PrintVector();

    v2 *= 1.5;
    cout << "v2 *= 1.5" << endl;
    v2.PrintVector();

    v1 = v3 + 1.0;
    cout << "v1 = v3 + 1.0" << endl;
    v1.PrintVector();
    try
    {
        a = v2 * v3;
    }
    catch (int i)
    {
        a = i;
    }
    cout << "a = v2 * v3 = " << a << endl;

    a = v2.Lenght();
    cout << "Len(v2) = " << a << endl;
    try
    {
        cout << "v2[0] = " << *v2[0] << endl;
        *v2[0] = 1.0;
        cout << "v2[0] = 1 = " << *v2[0] << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    v2.PrintVector();

    cin >> i;   
    return 0;
}