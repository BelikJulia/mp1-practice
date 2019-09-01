#pragma once
#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
    int i;

    Matrix m1(2, 3);
    Matrix m2(2, 3);
    cin >> m2;
    Matrix m3(2, 3);
    cin >> m3;
    Matrix m4(3, 2);

    try
    {
        m1 = m3 + m2;
        cout << "m1 = m2 + m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    try
    {
        m1 = m3 + m4;
        cout << "m1 = m2 + m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    cout << m1 << endl << m2 << endl << m3 << endl;

    try
    {
        m1 = m3 - m2;
        cout << "m1 = m2 - m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    cout << m1 << endl;

    try
    {
        m1 = m3 * m2;
        cout << "m1 = m2 * m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    try
    {
        m1 = m3 * m4;
        cout << "m1 = m2 * m1" << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }
    cout << m1 << endl;

    m1 = m3 + 1.0;
    cout << "m1 = m3 + 1.0" << endl;
    cout << m1 << endl;

    m1 = m3 - 2.0;
    cout << "m1 = m3 - 2.0" << endl;
    cout << m1 << endl;

    m1 = m3 * 1.5;
    cout << "m1 = m3 * 1.5" << endl;
    cout << m1 << endl;

    try
    {
        cout << "m2[1] = " << *m2[1] << endl;
        *m2[1] = 1.0;
        cout << "m2[1] = 1 = " << *m2[1] << endl;
    }
    catch (const char* A)
    {
        cout << A << endl;
    }

    cin >> i;
    return 0;
}