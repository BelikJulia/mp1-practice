#include "Matrix.h"
#include <iostream>
using namespace std;

Matrix::Matrix(int _x, int _y)
{
    x = _x;
    y = _y;
    matr = new double[_x * _y];
    memset(&matr[_x * _y], 0.0, sizeof(matr[_x * _y]));
}

Matrix::Matrix(double *_matr, int _x, int _y)
{
    x = _x;
    y = _y;
    matr = new double[_x * _y];
    for (int i = 0; i < (_x * _y); i++)
        memcpy(&matr[i], &_matr[i], sizeof(matr[i]));
}

Matrix::Matrix(const Matrix& m)
{
    x = m.x;
    y = m.y;
    matr = new double[x * y];
    for (int i = 0; i < (x * y); i++)
        memcpy(&matr[i], &m.matr[i], sizeof(matr[i]));
}

Matrix::~Matrix()
{
    delete[] matr;
    x = 0;
    y = 0;
}

Matrix Matrix::operator+ (const Matrix& m) const
{
    if ((x != m.x) || (y != m.y))
        throw "Size";
    Matrix res(m);
    for (int i = 0; i < (x * y); i++)
        res.matr[i] += matr[i];
    return res;
}

Matrix Matrix::operator- (const Matrix& m) const
{
    if ((x != m.x) || (y != m.y))
        throw "Size";
    Matrix res(*this);
    for (int i = 0; i < (x * y); i++)
        res.matr[i] -= m.matr[i];
    return res;
}

Matrix Matrix::operator* (const Matrix& m) const
{
    if (y != m.x)
        throw "Size";
    Matrix res(x, m.y);
    for (int i = 0; i < x; i++)
        for (int j = 0; j < m.y; j++)
        {
            res.matr[i * m.y + j] = 0.0;
            for (int k = 0; k < y; k++)
                res.matr[i * m.y + j] += matr[i * y + k] * m.matr[k * m.y + i];
        }
    return res;
}

Matrix Matrix::operator+ (double a) const
{
    Matrix res(*this);
    for (int i = 0; i < (x * y); i++)
        res.matr[i] += a;
    return res;
}

Matrix Matrix::operator- (double a) const
{
    Matrix res(*this);
    for (int i = 0; i < (x * y); i++)
        res.matr[i] -= a;
    return res;
}

Matrix Matrix::operator* (double a) const
{
    Matrix res(*this);
    for (int i = 0; i < (x * y); i++)
        res.matr[i] *= a;
    return res;
}

double* Matrix::operator[] (int a) const
{
    if ((a < 0) || (a >= x))
        throw "No row";
    return matr + y * a;
}

const Matrix& Matrix::operator= (const Matrix& m)
{ 
    if (*this == m)
    {
        return *this;
    }
    delete[] matr;
    x = m.x;
    y = m.y;
    matr = new double[x * y];
    for (int i = 0; i < (x * y); i++)
        memcpy(&matr[i], &m.matr[i], sizeof(matr[i]));
    return *this;
}

bool Matrix:: operator== (const Matrix& m) const
{
    if ((x != m.x) || (y != m.y)) return false;
    for (int i = 0; i < (x * y); i++)
    {
        if (matr[i] != m.matr[i]) 
            return false;
    }
    return true;
}

istream& operator>>(istream& in, Matrix& m)
{
    for (int i = 0; i < (m.x * m.y); i++)
        in >> m.matr[i];
    return in;
}

ostream& operator<<(ostream &out, const Matrix& m)
{
    for (int i = 0; i < (m.x * m.y); i++)
    {
        out << matr[i] << " ";
        if (i % y == (y - 1))
            out << endl;
    }
    return out;
}