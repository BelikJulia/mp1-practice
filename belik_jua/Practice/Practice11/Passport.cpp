#include "Passport.h"
#include <iostream>
using namespace std;

Passport::Passport()
{
    ser = "";
    num = "";
    iss = "";
    bir = Date(0, 0, 0);
    adr = "";
    s = "";
}

Passport::Passport(string _ser, string _num, string _iss, Date _bir, string _adr, string _s)
{
    ser = _ser;
    num = _num;
    iss = _iss;
    bir = _bir;
    adr = _adr;
    s = _s;
}

Passport::Passport(const Passport& tmp)
{
    ser = tmp.ser;
    num = tmp.num;
    iss = tmp.iss;
    bir = Date(tmp.bir);
    adr = tmp.adr;
    s = tmp.s;
}

Passport::~Passport()
{
    ser.clear();
    num.clear();
    iss.clear();
    bir.~Date();
    adr.clear();
    s.clear();
}

void Passport::Print()const
{
    cout << "Passport ser: " << ser << " num: " << num << " issued by " << iss << " birth: ";
    bir.Print();
    cout << " adress: " << adr << " sex: " << s << endl;
}

Date Passport::GetDate()const
{
    return bir;
}

Passport& Passport::operator= (const Passport& tmp)
{
    if (this == &tmp)
        return *this;
    ser = tmp.ser;
    num = tmp.num;
    iss = tmp.iss;
    bir = tmp.bir;
    adr = tmp.adr;
    s = tmp.s;
    return *this;
}

string Passport::GetS()const
{
    return s;
}

int Passport::Age(const Date date)const
{
    return date - bir;
}