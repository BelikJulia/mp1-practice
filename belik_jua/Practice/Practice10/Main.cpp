#include "Container.h"
#include "mContainer.h"
#include <iostream>
using namespace std;
#define MAX_SIZE 10

void main()
{
    cout << "mContainer" << endl;
    int size;
    cout << "Size = ";
    cin >> size;
    Container<int> A(MAX_SIZE);
    for (int i = 0; i < size; i++)
        A.Add(i);
    cout << A;
    int n;

    cout << "Remove ";
    cin >> n;
    try
    {
        A.Remove(n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    cout << A;

    cout << "Add ";
    cin >> n;
    try
    {
        A.Add(n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    cout << A;

    cout << "Find ";
    cin >> n;
    cout << A.Find(n) << endl;

    try
    {
        cout << "A[1] = " << A[1] << endl;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    try
    {
        A[1] = 6;
        cout << "A[1] = 6" << endl;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    cout << A;

    cout << "Container" << endl;
    cout << "Size = ";
    cin >> size;
    Container<int*> B(MAX_SIZE);
    for (int i = 0; i < size; i++)
        B.Add(&i);

    cout << B;

    cout << "Remove ";
    cin >> n;
    try
    {
        B.Remove(n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    cout << B;

    cout << "Add ";
    cin >> n;
    try
    {
        B.Add(&n);
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    cout << B;

    cout << "Find ";
    cin >> n;
    cout << B.Find(n) << endl;

    try
    {
        cout << "B[1] = " << B[1] << endl;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }

    try
    {
        B[1] = 6;
    }
    catch (int& i)
    {
        switch (i)
        {
        case 1:
            cout << "Container is empty" << endl;
            break;
        case 2:
            cout << "Container is full" << endl;
            break;
        case 3:
            cout << "No elem" << endl;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    cout << "B[1] = 6" << endl;
    cout << B;
}