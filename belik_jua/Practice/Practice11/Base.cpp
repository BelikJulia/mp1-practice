#include "Base.h"
#include <iostream>
using namespace std;

Base::Base()
{
    count = 0;
}

Base::Base(int _count)
{
    count = _count;
    base = new Emp[count];
}

Base::~Base()
{
    for (int i = 0; i < count; i++)
        base[i].~Emp();
    delete base;
    count = 0;
}

void Base::Print()const
{
    for (int i = 0; i < count; i++)
    {
        base[i].Print();
        cout << endl;
    }
}

void Base::Read(const char* A)
{
    //////////////////////////////////////////
}

void Base::Pen(Date a)const
{
    for (int i = 0; i < count; i++)
    {
        if (((base[i].GetS == "f") && (base[i].Age(a) >= 60)) || ((base[i].GetS() == "m") && (base[i].Age(a) >= 65)))
            base[i].Print();
    }
}