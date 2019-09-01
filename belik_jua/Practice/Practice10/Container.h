#pragma once
#include <iostream>
#include "mContainer.h"
using namespace std;

template <typename T>
class Container<T*>
{
private:
    T** arr;
    int n;
    int maxsize;
    void Increase(int a);
public:
    Container();
    Container(int m);
    Container(const Container& temp);
    ~Container();

    bool IsFull()const;
    bool IsEmpty()const;

    int Find(T a)const;
    void Add(T* a);
    void Remove(T a);
    T& operator[](int i);
    const T& operator[](int i)const;

    friend istream& operator>>(istream&, Container& c)
    {
        for (int i = 0; i < c.n; i++)
            in >> c[i];
        return in;
    }

    friend ostream& operator<<(ostream& out, const Container& c)
    {
        for (int i = 0; i < c.n; i++)
            out << c[i] << " ";
        return out;
    }
};

template <typename T>
Container<T*>::Container()
{
    n = 0;
    maxsize = 0;
}

template <typename T>
Container<T*>::Container(int m)
{
    maxsize = m;
    n = 0;
    arr = new T*[maxsize];
}

template <typename T>
Container<T*>::Container(const Container& temp)
{
    n = temp.n;
    maxsize = temp.maxsize;
    arr = new T*[maxsize];
    for (int i = 0; i < n; i++)
        arr[i] = new T(*(temp.arr[i]));
}

template <typename T>
Container<T*>::~Container()
{
    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete arr;
    n = 0;
}

template <typename T>
bool Container<T*>::IsFull()const
{
    return (n == maxsize);
}

template <typename T>
bool Container<T*>::IsEmpty()const
{
    return (n == 0);
}

template <typename T>
int Container<T*>::Find(T a)const
{
    for (int i = 0; i < n; i++)
        if (*arr[i] == a)
            return i;
    return -1;
}

template <typename T>
void Container<T*>::Add(T* a)
{
    if (this->IsFull())
        this->Increase(1);
    arr[n++] = new T(*a);
}

template <typename T>
void Container<T*>::Remove(T a)
{
    if (this->IsEmpty())
        throw 1;
    int j = Find(a);
    if (j == -1)
        throw 3;
    delete arr[j];
    arr[j] = arr[n - 1];
    arr[--n] = 0;
}

template <typename T>
T& Container<T*>::operator[](int i)
{
    if ((i < 0) || (i >= n))
        throw 3;
    return *arr[i];
}

template <typename T>
const T& Container<T*>::operator[](int i)const
{
    if ((i < 0) || (i >= n))
        throw 3;
    return *arr[i];
}

template <typename T>
void Container<T*>::Increase(int a)
{
    maxsize += a;
    T** x = new T*[maxsize];
    for (int i = 0; i < n; i++)
    {
        x[i] = arr[i];
    }
    arr = x;
}
