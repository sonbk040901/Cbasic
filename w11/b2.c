#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51 //Toi da la 51
typedef struct DT
{
    char name[40];
    char phone[15];
    char email[40];
} DataType;
typedef DataType ElementType;
const ElementType oo = {"zzz", "zzz", "zzz"};
void SWAP(ElementType *x, ElementType *y)
{
    ElementType temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int SupperCmp(ElementType x, ElementType y, int chose)
{
    switch (chose)
    {
    case 1:
        return strcmp(x.name, y.name);
        break;
    case 2:
        return strcmp(x.phone, y.phone);
        break;
    case 3:
        return strcmp(x.email, y.email);
        break;
    default:
        puts("Fail!! Khong the sap xep!");
        exit(0);
        break;
    }
}
void SupperCpy(ElementType *key, ElementType x)
{
    *key = x;
}
float insertion_sort(ElementType list[], int n, int chose)
{
    int i, j;
    ElementType next;
    clock_t tstart, tfinish;
    tstart = clock();
    for (i = 1; i < n; i++)
    {
        next = list[i];
        for (j = i - 1; j >= 0 && SupperCmp(next, list[j], chose) < 0; j--)
            list[j + 1] = list[j];
        list[j + 1] = next;
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
float slection_sort(ElementType a[], int n, int chose)
{
    int i, j, min;
    ElementType tmp;
    clock_t tstart, tfinish;
    tstart = clock();
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (SupperCmp(a[j], a[min], chose) < 0)
                min = j;
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
void adjust(ElementType list[], int root, int n, int chose)
{
    int child;
    ElementType rootkey; //Chu y o day tuy vao struct Element
    ElementType temp;
    temp = list[root];
    SupperCpy(&rootkey, list[root]);
    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) && SupperCmp(list[child], list[child + 1], chose) < 0)
            child++;
        if (SupperCmp(rootkey, list[child], chose) > 0)
            break;
        else
        {
            list[child / 2] = list[child];
            child *= 2;
        }
    }
    list[child / 2] = temp;
}
float heap_sort(ElementType list[], int n, int chose)
{
    int i, j;
    int temp;
    clock_t tstart, tfinish;
    tstart = clock();
    for (i = n / 2; i > 0; i--)
        adjust(list, i, n, chose);
    for (i = n - 1; i > 0; i--)
    {
        SWAP(&list[1], &list[i + 1]);
        adjust(list, 1, i, chose);
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
int partiton(ElementType list[], int left, int right, int chose)
{
    int i, j;
    ElementType pivot;
    i = left;
    j = right + 1;
    SupperCpy(&pivot, list[left]);
    do
    {
        do
            i++;
        while (SupperCmp(list[i], pivot, chose) < 0);
        do
            j--;
        while (SupperCmp(list[j], pivot, chose) > 0);
        if (i < j)
            SWAP(&list[i], &list[j]);
    } while (i < j);
    SWAP(&list[left], &list[j]);
    return j;
}
float quick_sort(ElementType list[], int left, int right, int chose)
{
    int j;
    clock_t tstart, tfinish;
    tstart = clock();
    if (left < right)
    {
        j = partiton(list, left, right, chose);
        quick_sort(list, left, j - 1, chose);
        quick_sort(list, j + 1, right, chose);
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
void Merge(ElementType list[], int left, int mid, int right, int chose)
{
    ElementType *L, *R;
    int i = 0, j = 0, k, a, b;
    L = (ElementType *)malloc(sizeof(ElementType) * (mid - left + 2));
    R = (ElementType *)malloc(sizeof(ElementType) * (right - mid + 1));
    a = 0;
    for (int f = left; f <= mid; f++)
    {
        L[a++] = list[f];
    }
    SupperCpy(&L[a], oo);
    b = 0;
    for (int f = mid + 1; f <= right; f++)
    {
        R[b++] = list[f];
    }
    SupperCpy(&R[b], oo);
    for (k = left; k <= right; k++)
    {
        if (SupperCmp(L[i], R[j], chose) <= 0)
            list[k] = L[i++];
        else
            list[k] = R[j++];
    }
    free(L);
    free(R);
}
float Merge_sort(ElementType list[], int left, int right, int chose)
{
    clock_t tstart, tfinish;
    tstart = clock();
    if (left < right)
    {
        int mid = (left + right) / 2;
        Merge_sort(list, left, mid, chose);
        Merge_sort(list, mid + 1, right, chose);
        Merge(list, left, mid, right, chose);
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}
void Fprint(FILE *f, ElementType x)
{
    fputs(x.name, f);
    fputs(x.phone, f);
    fputs(x.email, f);
}
ElementType PopData(FILE *f)
{
    ElementType x;
    fgets(x.name, 40, f);
    fgets(x.phone, 15, f);
    fgets(x.email, 40, f);
    return x;
}
int main(int argc, char const *argv[])
{
    FILE *fin;
    FILE *fout;
    fin = fopen("data.txt", "r");
    fout = fopen("datasx.txt", "w+");
    ElementType list1[MAX + 1], list2[MAX], list3[MAX], list4[MAX], list5[MAX];
    int chose;
    scanf("%d", &chose);
    for (int i = 0; i < MAX && !feof(fin); i++)
    {
        SupperCpy(&list1[i + 1], PopData(fin));
        // SupperCpy(&list2[i], list1[i + 1]);
        // SupperCpy(&list3[i], list1[i + 1]);
        // SupperCpy(&list4[i], list1[i + 1]);
        SupperCpy(&list5[i], list1[i + 1]);
    }
    printf("Heap_sort: %g\n", heap_sort(list1, MAX, chose));
    // for (int i = 1; i <= MAX; i++)
    // {
    //     Fprint(fout, list1[i]);
    // }
    printf("Merge_sort: %g\n", Merge_sort(list5, 0, MAX - 1, chose));
    for (int i = 0; i < MAX; i++)
    {
        Fprint(fout, list5[i]);
    }
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
    // printf("\nQuick_sort: %g\n", quick_sort(list4, 0, MAX - 1, chose));
    // for (int i = 0; i < MAX; i++)
    // {
    //     Fprint(fout, list4[i]);
    // }
    printf("\n");
    fclose(fin);
    fclose(fout);
    return 0;
}