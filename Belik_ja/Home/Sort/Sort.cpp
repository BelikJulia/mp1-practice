#pragma once
#include "Header.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


void ChooseSort()
{
    int i, j, tmp, ind;
    int n;
    FILE *output = NULL;
    output = fopen("E:/output.bin", "rb");
    if (output == NULL)
    {
        cout << "Error opening file";
        return;
    }
    fread(&n, sizeof(int), 1, output);
    int *a = new int[n];
    for (i = 0; i < n; i++)
        fread(&a[i], sizeof(int), 1, output);
    for (i = 0; i < n - 1; i++)
    {
        ind = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[ind] > a[j])
                ind = j;
        }
        tmp = a[ind];
        a[ind] = a[i];
        a[i] = tmp;
    }
    NewFile(a, n);
    fclose(output);
    delete(a);
}

void Gener(int *a, int n, double m)
{
    srand((unsigned int)time(0));
    for (int i = 0; i < n; i++)
        a[i] = m / RAND_MAX * rand() + 1;
}

void Print(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void NewFile(int *a, int n)
{
    FILE *output = NULL;
    output = fopen("E:/output.bin", "wb");
    if (output == NULL)
    {
        cout << "Error opening file";
        exit(-1);
    }
    fwrite(&n, sizeof(int), 1, output);
    for (int i = 0; i < n; i++)
        fwrite(&a[i], sizeof(int), 1, output);
    fclose(output);
}