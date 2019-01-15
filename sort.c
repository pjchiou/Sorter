#include "sort.h"
#include "array.h"

void BubbleSort(int* arr,int iSize)
{
  for(int i=iSize-1;i>0;i--)
    for(int j=0;j<i;j++){
        if (arr[j] > arr[j + 1])
            Swap(arr, j, j + 1);
    }
}

sorterList *addNode(sorterList *list, char *name, void (*fun)(int *, int))
{
    sorterList *ptr;

    ptr = (sorterList *) malloc(sizeof(sorterList));

    ptr->fun = fun;
    ptr->funName = strdup(name);
    ptr->next = list;

    return (ptr);
}

void freeList(sorterList *list)
{
    sorterList *ptr = list, *temp;

    while (ptr) {
        temp = ptr->next;
        free(ptr->funName);
        free(ptr);
        ptr = temp;
    }
}
