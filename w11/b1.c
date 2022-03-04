#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 40
typedef struct ElementType
{
    int key;
} ElementType;
void SWAP(ElementType *x, ElementType *y)
{
    ElementType temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
float insertion_sort(ElementType list[], int n)
{
    int i, j;
    ElementType next;
    clock_t tstart, tfinish;
    tstart = clock();
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && next.key < list[j].key; j--)
            list[j + 1] = list[j];
        list[j + 1] = next;
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
float slection_sort(ElementType a[], int n)
{
    int i, j, min;
    ElementType tmp;
    clock_t tstart, tfinish;
    tstart = clock();
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j].key < a[min].key)
                min = j;
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
void adjust(ElementType list[], int root, int n)
{
    int child, rootkey;
    ElementType temp;
    temp = list[root];
    rootkey = list[root].key;
    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) && list[child].key < list[child + 1].key)
            child++;
        if (rootkey > list[child].key)
            break;
        else
        {
            list[child / 2] = list[child];
            child *= 2;
        }
    }
    list[child / 2] = temp;
}
float heap_sort(ElementType list[], int n)
{
    int i, j;
    int temp;
    clock_t tstart, tfinish;
    tstart = clock();
    for (i = n / 2; i > 0; i--)
        adjust(list, i, n);
    for (i = n - 1; i > 0; i--)
    {
        temp = list[1].key;
        list[1].key = list[i + 1].key;
        list[i + 1].key = temp;
        adjust(list, 1, i);
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
int partiton(ElementType list[], int left, int right)
{
    int pivot, i, j;
    i = left;
    j = right + 1;
    pivot = list[left].key;
    do
    {
        do
            i++;
        while (list[i].key < pivot);
        do
            j--;
        while (list[j].key > pivot);
        if (i < j)
            SWAP(&list[i], &list[j]);
    } while (i < j);
    SWAP(&list[left], &list[j]);
    return j;
}
float quick_sort(ElementType list[], int left, int right)
{
    int j;
    clock_t tstart, tfinish;
    tstart = clock();
    // if (right - left < 10)
    // {
    //     heap_sort(list + left - 1, right - left + 1);
    //     insertion_sort(list + left, right - left + 1);
    // }
    if (left < right)
    {
        j = partiton(list, left, right);
        quick_sort(list, left, j - 1);
        quick_sort(list, j + 1, right);
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
int main(int argc, char const *argv[])
{
    ElementType list1[MAX + 1], list2[MAX], list3[MAX], list4[MAX];
    srand((unsigned)(time(NULL)));
    for (int i = 0; i < MAX; i++)
    {
        list1[i + 1].key = rand() % (MAX * 10);
        list2[i].key = list1[i + 1].key;
        list3[i].key = list1[i + 1].key;
        list4[i].key = list1[i + 1].key;
    }
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", list4[i].key);
    }
    printf("\nHeap_sort: %g\n", heap_sort(list1, MAX));
    // for (int i = 1; i <= MAX; i++)
    // {
    //     printf("%d ", list1[i].key);
    // }
    // printf("\nInsertion_sort: %g\n", insertion_sort(list2, MAX));
    // for (int i = 0; i < MAX; i++)
    // {
    //     printf("%d ", list2[i].key);
    // }
    // printf("\nSelection_sort: %g\n", slection_sort(list3, MAX));
    // for (int i = 0; i < MAX; i++)
    // {
    //     printf("%d ", list3[i].key);
    // }
    printf("\nQuick_sort: %g\n", quick_sort(list4, 0, MAX - 1));
    for (int i = 0; i < MAX; i++)
    {
        printf("%d ", list4[i].key);
    }
    printf("\n");
    return 0;
}
