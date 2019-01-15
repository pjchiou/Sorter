#include <stdlib.h>
#include <string.h>

typedef struct eleSorter {
    void (*fun)(int *arr, int size);
    char *funName;
    struct eleSorter *next;
} sorterList;

void BubbleSort(int* arr,int iSize);

sorterList *addNode(sorterList *list, char *name, void (*fun)(int *, int));
void freeList(sorterList *list);
