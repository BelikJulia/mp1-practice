#pragma once
#include "Employee.h"
#include <string>
using namespace std;

class Base
{
private:
    Emp* base;
    int count;
public:
    Base();
    Base(int _count);
    ~Base();

    void Print()const;
    void Read(const char* A);
    void Pen(Date a)const;
};

