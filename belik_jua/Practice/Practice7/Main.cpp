#pragma once
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
    int i;
    double a;

    Vector v1(3);
    Vector v2(3);
    cin >> v2;
    Vector v3(3);
    cin >> v3;
    try 
    {
        v1 = v3 + v2;
        cout << "v1 = v2 + v1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    cout << v1 << endl << v2 << endl << v3 << endl;

    try
    {
        v1 = v3 - v2;
        cout << "v1 = v2 - v1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    cout << v1 << endl;

    v2 -= 5;
    cout << "v2 -= 5" << endl;
    cout << v2 << endl;

    v2 += 10;
    cout << "v2 += 10" << endl;
    cout << v2 << endl;

    v2 *= 1.5;
    cout << "v2 *= 1.5" << endl;
    cout << v2 << endl;

    v1 = v3 + 1.0;
    cout << "v1 = v3 + 1.0" << endl;
    cout << v1 << endl;
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
        cout << "v2[0] = " << v2[0] << endl;
        v2[0] = 1.0;
        cout << "v2[0] = 1 = " << v2[0] << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    cout << v2 << endl;

    cin >> i;   
    return 0;
}