#include "Task.h"
#include<iostream>

Task::Task()
{
    date = Date();
    description = "";
}

Task::~Task()
{
    description.clear();
}

Date Task::GetDate()const
{
    return date;
}

Type1::Type1()
{
    date = Date();
    description = "";
}

Type1::Type1(string des, Date d)
{
    date = d;
    description = des;
}

Type1::~Type1()
{
    description.clear();
}

Date Type1::GetDate()const
{
    return date;
}

void Type1::Print()const
{
    cout << "All day task: " << description << endl;
}

const Type1& Type1::operator= (const Type1& tmp)
{
    date = tmp.date;
    description = tmp.description;
    return *this;
}

Type2::Type2()
{
    date = Date();
    description = "";
    time = Time();
    durations = 0;
}

Type2::Type2(string des, Date d, Time t, unsigned dur)
{
    date = d; 
    description = des;
    time = t;
    durations = dur;
}

Type2::~Type2()
{
    description.clear();
    durations = 0;
}

Date Type2::GetDate()const
{
    return date;
}

void Type2::Print()const
{
    cout << "Task: ";
    time.Print();
    cout << description << " duration: " << durations << " min" << endl;
}

const Type2& Type2::operator= (const Type2& tmp)
{
    date = tmp.date;
    description = tmp.description;
    time = tmp.time;
    durations = tmp.durations;
    return *this;
}