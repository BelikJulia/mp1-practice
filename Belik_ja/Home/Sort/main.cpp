#pragma once
#include "Header.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define N 10

int main()
{
    int *a = new int[N];
    Gener(a, N, 10.0);
    NewFile(a, N);
    ChooseSort();
    delete(a);
    return 0;
}