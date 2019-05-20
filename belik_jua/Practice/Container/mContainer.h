#pragma once
#include <iostream>
using namespace std;

template <typename T>
class mContainer
{
private:
    T* arr;
    int n;
    int maxsize;
public:
    mContainer();
    mContainer(int x, int m);
    mContainer(const mContainer& temp);
    ~mContainer();

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
mContainer<T>::mContainer()
{
    n = 0;
    maxsize = 0;
}

template <typename T>
mContainer<T>::mContainer(int x, int m)
{
    n = x;
    maxsize = m;
    arr = new T[maxsize];
}

template <typename T>
mContainer<T>::mContainer(const mContainer& temp)
{
    n = temp.n;
    maxsize = temp.maxsize;
    arr = new T[maxsize];
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp.arr[i];
    }
}

template <typename T>
mContainer<T>::~mContainer()
{
    delete arr;
    n = 0;
}

template <typename T>
bool mContainer<T>::IsFull()const
{
    return (n == maxsize);
}

template <typename T>
bool mContainer<T>::IsEmpty()const
{
    return (n == 0);
}

template <typename T>
int mContainer<T>::Find(T a)const
{
    for (int i = 0; i < n; i++)
        if (arr[i] == a)
            return i;
    return -1;
}

template <typename T>
void mContainer<T>::Add(T a)
{
    if (this->IsFull())
        this->Increase(1);
    n++;
    arr[n - 1] = a;
}

template <typename T>
void mContainer<T>::Remove(T a)
{   
    if (this->IsEmpty())
        throw 1;
    int j = Find(a);
    if (j == -1)
        throw 3;
    arr[j] = arr[n - 1];
    n--;
}

template <typename T>
T* mContainer<T>::operator[](int i)
{
    if ((i < 0) || (i >= n))
        throw 3;
    return &(arr[i]);
}

template <typename T>
void mContainer<T>::Print()const
{
    if (this->IsEmpty())
        throw 1;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void mContainer<T>::Fill()
{
    if (this->IsEmpty())
        throw 1;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

template <typename T>
void mContainer<T>::Increase(int a)
{
    T* x = new T[n];
    for (int i = 0; i < n; i++)
        x[i] = arr[i];
    delete arr;
    maxsize += a;
    arr = new T[maxsize];
    for (int i = 0; i < n; i++)
        arr[i] = x[i];
    delete x;
}
