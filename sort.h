#include <stdlib.h>
#include <string.h>

typedef struct eleSorter {
    void (*fun)(int *arr, int size);
    char *funName;
    struct eleSorter *next;
} sorterList;

typedef struct mergePointer {
    int *ptr, size;
    struct mergePointer *next;
} mergePtr;

void BubbleSort(int* arr,int iSize);
void MergeSort(int *arr, int iSize);

sorterList *addNode(sorterList *list, char *name, void (*fun)(int *, int));
void freeList(sorterList *list);
