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
        printf("%s use %lf seconds.\n", head->funName,
               (double) (toc - tic) / CLOCKS_PER_SEC);
    }

    free(arr);
    freeList(list);
    return (0);
}

