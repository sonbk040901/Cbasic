#include <stdio_ext.h>
#include "linked.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 51
int supercmp(ElementType x, ElementType y, int chose)
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
        printf("Khong the sap xep\n");
        exit(0);
        break;
    }
}
LinkList *Mid(LinkList *First)
{
    LinkList *a = First, *b = First;
    while (b->Next && b->Next->Next)
    {
        b = b->Next->Next;
        a = a->Next;
    }
    LinkList *temp = a->Next;
    a->Next = NULL;
    return temp;
}
LinkList *Merge(LinkList *First, LinkList *Second, int chose)
{
    if (First == NULL)
        return Second;
    if (Second == NULL)
        return First;
    if (supercmp(First->data, Second->data, chose) <= 0)
    {
        First->Next = Merge(First->Next, Second, chose);
        return First;
    }
    else
    {
        Second->Next = Merge(First, Second->Next, chose);
        return Second;
    }
}
LinkList *Merge_sort(LinkList *First, int chose)
{
    if (First == NULL || First->Next == NULL)
        return First;
    LinkList *Second = Mid(First);
    First = Merge_sort(First, chose);
    Second = Merge_sort(Second, chose);
    return Merge(First, Second, chose);
}
int main()
{
    FILE *fin = fopen("data.txt", "r+");
    FILE *fout = fopen("datasx.txt", "w+");
    ElementType x;
    LinkList *list = NULL;
    int chose;
    scanf("%d", &chose);
    for (int i = 0; i < MAX; i++)
    {
        fgets(x.name, 40, fin);
        fgets(x.phone, 15, fin);
        fgets(x.email, 40, fin);
        list = InsertToHead(list, x);
    }
    list = Merge_sort(list, chose);
    Print(fout, list);
    list = MakeNull(list);
    fclose(fin);
    fclose(fout);
    return 0;
}