#pragma once
#include "Date.h"
#include "Passport.h"
#include <string>
using namespace std;

class Emp
{
private:
    Passport pas;
    string educ;
    string pos;
    double sal;
    Date arr;
    Date last;
public:
    Emp();
    Emp(Passport _pas, string _educ, string _pos, double _sal, Date _arr, Date _last);
    ~Emp();

    void Print()const;
    int Age(const Date& date)const;
    string GetS()const;
};
