#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Container
{
private:
    T** arr;
    int n;
    int maxsize;
public:
    Container();
    Container(int x, int m);
    Container(const Container& temp);
    ~Container();

    bool IsFull()const;
    bool IsEmpty()const;

    int Find(T a)const;
    void Add(T a);
    void Remove(T a);
    T* operator[](int i);

    void Print()const;
    void Fill();
    void Increase(int a);
};

template <typename T>
Container<T>::Container()
{
    n = 0;
    maxsize = 0;
}

template <typename T>
Container<T>::Container(int x, int m)
{
    n = x;
    maxsize = m;
    arr = new T*[maxsize];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new T;
    }
}

template <typename T>
Container<T>::Container(const Container& temp)
{
    n = temp.n;
    maxsize = temp.maxsize;
    arr = new T*[maxsize];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new T;
        *arr[i] = temp.*arr[i];
    }
}

template <typename T>
Container<T>::~Container()
{
    for (int i = 0; i < n; i++)
    {
        delete arr[i];
    }
    delete arr;
    n = 0;
}

template <typename T>
bool Container<T>::IsFull()const
{
    return (n == maxsize);
}

template <typename T>
bool Container<T>::IsEmpty()const
{
    return (n == 0);
}

template <typename T>
int Container<T>::Find(T a)const
{
    for (int i = 0; i < n; i++)
        if (*arr[i] == a)
            return i;
    return -1;
}

template <typename T>
void Container<T>::Add(T a)
{
    if (this->IsFull())
        this->Increase(1);
    n++;
    arr[n - 1] = new T;
    *arr[n - 1] = a;
}

template <typename T>
void Container<T>::Remove(T a)
{
    if (this->IsEmpty())
        throw 1;
    int j = Find(a);
    if (j == -1)
        throw 3;
    *arr[j] = *arr[n - 1];
    delete arr[n - 1];
    n--;
}

template <typename T>
T* Container<T>::operator[](int i)
{
    if ((i < 0) || (i >= n))
        throw 3;
    return arr[i];
}

template <typename T>
void Container<T>::Print()const
{
    if (this->IsEmpty())
        throw 1;
    for (int i = 0; i < n; i++)
    {
        cout << *(arr[i]) << " ";
    }
    cout << endl;
}

template <typename T>
void Container<T>::Fill()
{
    if (this->IsEmpty())
        throw 1;
    for (int i = 0; i < n; i++)
    {
        cin >> *(arr[i]);
    }
}

template <typename T>
void Container<T>::Increase(int a)
{
    T** x = new T*[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = new T;
        x[i] = arr[i];
        delete arr[i];
    }
    delete arr;
    maxsize += a;
    arr = new T*[maxsize];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new T;
        arr[i] = x[i];
        delete x[i];
    }
    delete x;
}