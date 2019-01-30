#include "sort.h"
#include "array.h"

void BubbleSort(int* arr,int iSize)
{
    for (int i = iSize - 1; i > 0; i--)
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1])
                Swap(arr, j, j + 1);
        }
}

void MergeSort(int *arr, int iSize)
{
    mergePtr *head, *tail;

    /*
    Use a linked-list to store all element.
    */
    head = (mergePtr *) malloc(sizeof(mergePtr));
    head->size = 1;
    head->ptr = (int *) malloc(sizeof(int));
    *(head->ptr) = arr[0];
    head->next = NULL;
    tail = head;

    /*
    Treat every element as a individual linked-list.
    And then merge them.
    */
    for (int i = 1; i < iSize; i++) {
        mergePtr *temp = (mergePtr *) malloc(sizeof(mergePtr));
        temp->size = 1;
        temp->ptr = malloc(sizeof(int));
        *(temp->ptr) = arr[i];
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;
    }

    /*
    Iterately merge two element until there is only
    1 element in this linked list.
    */
    while (head && head->next) {
        mergePtr *head1 = head, *head2 = head->next;
        mergePtr *temp = (mergePtr *) malloc(sizeof(mergePtr));

        temp->size = (head1->size + head2->size);
        temp->ptr = (int *) malloc(sizeof(int) * temp->size);
        for (int i = 0, j = 0, k = 0; i < temp->size; i++) {
            if ((j < head1->size && head1->ptr[j] < head2->ptr[k]) ||
                k == head2->size)
                temp->ptr[i] = head1->ptr[j++];
            else
                temp->ptr[i] = head2->ptr[k++];
        }
        temp->next = NULL;
        tail->next = temp;
        tail = tail->next;

        head = head2->next;
        free(head1->ptr);
        free(head1);
        free(head2->ptr);
        free(head2);
    }

    for (int i = 0; i < iSize; i++)
        arr[i] = head->ptr[i];

    free(head->ptr);
    free(head);
}

void QuickSort(int *arr, int iSize)
{
    QSort(arr, arr + iSize - 1);
}

void QSort(int *left, int *right)
{
    int pivot = *left;
    int *leftptr = left, *rightptr = right;
    leftptr++;

    while (leftptr < rightptr) {
        if (*leftptr > pivot && *rightptr < pivot) {
            int temp = *leftptr;
            *leftptr = *rightptr;
            *rightptr = temp;
        } else if (*leftptr > pivot && *rightptr > pivot)
            rightptr--;
        else if (*leftptr < pivot && *rightptr < pivot)
            leftptr++;
        else {
            leftptr++;
            rightptr--;
        }
    }

    if (leftptr == rightptr) {
        if (*leftptr < pivot) {
            int temp = *leftptr;
            *leftptr = *left;
            *left = temp;
            leftptr--;
            rightptr++;
        }
        if (*leftptr > pivot) {
            leftptr--;
            int temp = *(leftptr);
            *(leftptr) = *left;
            *left = temp;
        }

        if (left < leftptr)
            QSort(left, leftptr);
        if (rightptr < right)
            QSort(rightptr, right);
    } else {
        if (*rightptr < pivot) {
            int temp = *rightptr;
            *rightptr = *left;
            *left = temp;
            rightptr--;
        }
        if (left < rightptr)
            QSort(left, rightptr);
        if (leftptr < right)
            QSort(leftptr, right);
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
