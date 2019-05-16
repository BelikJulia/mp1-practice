#include "Employee.h"
#include <iostream>
using namespace std;

Emp::Emp()
{
    pas = Passport();
    educ = "";
    pos = "";
    sal = 0;
    arr = Date();
    last = Date();
}

Emp::Emp(Passport _pas, string _educ, string _pos, double _sal, Date _arr, Date _last)
{
    pas = Passport(_pas);
    educ = "";
    pos = "";
    sal = 0;
    arr = Date();
    last = Date();
}

Emp::~Emp()
{
    pas.~Passport();
    educ.clear();
    pos.clear();
    sal = 0;
    arr.~Date();
    last.~Date();
}

void Emp::Print()const
{
    pas.Print();
    cout << " Education: " << educ << " Position: " << pos << " Sal: " << sal << " Arr: ";
    arr.Print();
    cout << " last: ";
    last.Print();
    cout << endl;
}

int Emp::Age(const Date& date)const
{
    return pas.Age(date);
}

string Emp::GetS()const
{
    return pas.GetS();
}
