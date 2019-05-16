#pragma once
#include "Date.h"
#include <string>
using namespace std;

class Passport
{
private:
    string ser;
    string num;
    string iss;
    Date bir;
    string adr;
    string s;
public:
    Passport();
    Passport(string _ser, string _num, string _iss, Date _bir, string _adr, string _s);
    Passport(const Passport& tmp);
    ~Passport();

    void Print()const;
    Date GetDate()const;
    Passport& operator= (const Passport& tmp);
    string GetS()const;
    int Age(const Date date)const;
};