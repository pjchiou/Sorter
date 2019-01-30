#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "array.h"
#include "sort.h"

#define vSize 100

int main()
{
    clock_t tic, toc;
    sorterList *list = NULL;
    int *arr;

    list = addNode(list, "Quick sort", QuickSort);
    list = addNode(list, "Merge sort", MergeSort);
    list = addNode(list, "Bubble sort", BubbleSort);

    arr = RandomArr(vSize);

    for (sorterList *head = list; head; head = head->next) {
        Shake(arr, vSize);
        tic = clock();
        head->fun(arr, vSize);
        toc = clock();
#if defined(OUTPUT)
        OutputArr(arr, vSize);
#endif
        printf("%s use %lf seconds, %s.\n", head->funName,
               (double) (toc - tic) / CLOCKS_PER_SEC,
               Check(arr, vSize) == 1 ? "correct" : "error");
    }

    free(arr);
    freeList(list);
    return (0);
}

