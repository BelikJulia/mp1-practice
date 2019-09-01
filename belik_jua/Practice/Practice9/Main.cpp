#include "ToDoList.h"
#include <iostream>
using namespace std;

void main()
{
    ToDoList t;
    string Aa;
    cin >> Aa;
    try 
    {
        t.Read(Aa);
    }
    catch (const char* A)
    {
        cout << A << endl;
    } 
    int y, m, d;
    cout << "Date: " << "Day: ";
    cin >> d;
    cout << "Month: ";
    cin >> m;
    cout << "Year: ";
    cin >> y;
    Date date = Date(y, m, d);
    t.Print(date);
}