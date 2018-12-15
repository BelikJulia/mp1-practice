#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define K 100
#define MAX_LEN 100
#define MAX_NAME 100

int ListDirectoryContents(const wchar_t *sDir, long *size, wchar_t *name) 
{
    WIN32_FIND_DATA fdFile;
    HANDLE hFind = NULL;
    wchar_t sPath[MAX_NAME]; 
    int i = 0; 
    int j = 0;

    wsprintf(sPath, L"%s\\*.*", sDir);
    if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
    {
        wprintf(L"Path not found: [%s]\n", sDir);
        return 1;
    }

    do
    {
        if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
        {
            ULONGLONG fileSize = fdFile.nFileSizeHigh;
            fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
            fileSize |= fdFile.nFileSizeLow;

//            wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
//            wprintf(L"File: %s Size: %d\n", sPath, fileSize);
            
            *(name + i) = sPath;
            *(size + i) = (long)fileSize; printf("%d ", name[i]); i++; //del
        }
    } while (FindNextFile(hFind, &fdFile));
    FindClose(hFind);
    return i;
}

void Command()
{
    printf("\n1 - ChooseSort \n");
    printf("2 - InsertionSort \n");
    printf("3 - BubbleSort \n");
    printf("4 - CountingSort \n");
    printf("5 - QuickSort \n");
    printf("6 - MergeSort \n");
    printf("7 - Exit \n");
}

void Print(int *a, long *size, wchar_t *name, int n) 
{
    int i;     WIN32_FIND_DATA fdFile;
    for (i = 0; i < n; i++)
    {
//        wsprintf(name[a[i] * MAX_NAME], L"%s\\%s", sDir, fdFile.cFileName);
//        wprintf(L"File: %s Size: %d\n", name[a[i] * MAX_NAME], size[a[i]]);
        printf("%s size: %d", *(name + a[i]), a[i]);
//        printf("%d ", *(size + a[i]));
    }
    printf("\n");
}

void ChooseSort(int *a, long *size, int n)
{
    int i, j, tmp, ind;
    for (i = 0; i < n - 1; i++)
    {
        ind = i;
        for (j = i + 1; j < n; j++)
        {
            if (size[a[ind]] > size[a[j]])
                ind = j; 
        }
        tmp = a[ind];
        a[ind] = a[i];
        a[i] = tmp;
    }
}

void InsertionSort(int *a, long *size, int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (size[a[j]] > size[tmp]))
        {
            a[j + 1] = a[j];
            a[j] = tmp;
            j--;
        }
    }
}

void BubbleSort(int *a, long *size, int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (size[a[j]] < size[a[j - 1]])
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
            }
        }
    }
}

void CountingSort(int *a, long *size, int n)
{
    int *b = (int*)malloc(K * sizeof(int));
    int i, j, idx = 0;
    int h = 0;
    for (i = 0; i < K; i++)
        b[i] = 0;
    for (i = 0; i < n; i++)
        b[size[a[i]]]++;
    for (i = 0; i < K; i++)
    {
        if (b[i]>0)
        {
            h = 0;
            for (j = 0; j < b[i]; j++)
            {
                while (size[h] != i)
                    h++;
                a[idx++] = h++;
            }
        }
    }
    free(b);
}

void Quicksplit(int *a, long *size, int *i, int *j, int p)
{
    int tmp;
    do {
        while (size[a[(*i)]] < p)
            (*i)++; 
        while (size[a[(*j)]] > p)
            (*j)--; 
        if ((*i) <= (*j))
        {
            tmp = a[(*i)];
            a[(*i)] = a[(*j)];
            a[(*j)] = tmp;
            (*i)++;
            (*j)--;
        } 
    } while ((*i) < (*j));
}

void QuickSort(int *a, long *size, int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    Quicksplit(a, size, &i, &j, size[a[m]]);
    if (j > n1)
        QuickSort(a, size, n1, j);
    if (i < n2)
        QuickSort(a, size, i, n2); 
}

void Merge(int *a, long *size, int l, int m, int r) 
{
    int i, j = m + 1, h, tmp;
    for (i = l; ((i < r) && (j <= r)); i++)
    {
        if (size[a[i]] > size[a[j]])
        {
            tmp = a[j];
            for (h = j; h > i; h--)
                a[h] = a[h - 1];
            a[i] = tmp;
            j++;
        }
    }
    
}

void MergeSort(int *a, long *size, int l, int r)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    MergeSort(a, size, l, m);
    MergeSort(a, size, m + 1, r);
    Merge(a, size, l, m, r);
}

void main()
{
    int i = 0; 
    int* ind; 
    int N;

    long* size;                          
    size = (long*)malloc(MAX_LEN);         
    wchar_t* name[] = {""};
    *name = (wchar_t*)malloc(MAX_NAME * MAX_LEN);
    char* a = (char*)malloc(MAX_LEN);
    wchar_t* sDir = (wchar_t*)malloc(MAX_LEN);
    fgets(a, MAX_LEN, stdin);
    a[strlen(a) - 1] = '\0';
    swprintf(sDir, MAX_LEN, L"%hs", a);
    N = ListDirectoryContents(sDir, size, name);
    free(a);
    free(sDir); 
    
    do
    { 
        Command();
        ind = (int*)malloc(N * sizeof(int));
        for (i = 0; i < N; i++)
            ind[i] = i;  Print(ind, size, name, N);  //del
        scanf("%d", &i);
        printf("\n");//time
        switch (i) {
        case 1:
            ChooseSort(ind, size, N);
            break;
        case 2:
            InsertionSort(ind, size, N);
            break;
        case 3:
            BubbleSort(ind, size, N);
            break;
        case 4:
            CountingSort(ind, size, N);
            break;
        case 5:
            QuickSort(ind, size, 0, (N - 1));
            break;
        case 6:
            MergeSort(ind, size, 0, (N - 1));
        }
        Print(ind, size, name, N, sDir);
        free(ind);
    } while (i != 7); 
    free(name);
    free(size);
}