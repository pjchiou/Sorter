#include "array.h"

#define ShakeTime 1000

int *RandomArr(int iSize)
{
    int *ptr;

    ptr = (int *) malloc(sizeof(int) * iSize);
    for (int i = 0; i < iSize; i++)
        ptr[i] = i;

    return (ptr);
}

void Shake(int *arr, int iSize)
{
    int a, b;
    for (int i = 0; i < ShakeTime; i++) {
        a = rand() % iSize;
        b = rand() % iSize;
        if (a != b)
            Swap(arr, a, b);
    }
}

void Swap(int *arr, int i, int j)
{
    /*int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;*/
    arr[i] = arr[i] ^ arr[j];
    arr[j] = arr[i] ^ arr[j];
    arr[i] = arr[i] ^ arr[j];
}

void OutputArr(int* arr,int iSize)
{
    for (int i = 0; i < iSize; i++)
        printf("%d,", arr[i]);
    printf("\n");
}
