#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "sort.h"

#define vSize 100

int main()
{
    sorterList *list = NULL;
    int *arr;

    list = addNode(list, "Bubble sort", BubbleSort);

    arr = RandomArr(vSize);

    for (sorterList *head = list; head; head = head->next) {
        Shake(arr, vSize);

        head->fun(arr, vSize);
        OutputArr(arr, vSize);
    }

    free(arr);
    freeList(list);
    return (0);
}

