#include "linked.h"
#include <stdlib.h>
#include <stdio.h>

LinkList *InsertMiddle(LinkList *Prev, ElementType X)
{
    LinkList *TempNode;
    TempNode = (LinkList *)malloc(sizeof(LinkList));
    TempNode->data = X;
    TempNode->Next = Prev->Next;
    Prev->Next = TempNode;
    return TempNode;
}

ElementType Delete(LinkList *Prev)
{
    ElementType X;
    LinkList *TempNode;

    TempNode = Prev->Next;
    Prev->Next = Prev->Next->Next;
    X = TempNode->data;
    free(TempNode);

    return X;
}

LinkList *InsertToHead(LinkList *First, ElementType X)
{
    LinkList *TempNode;

    TempNode = (LinkList *)malloc(sizeof(LinkList));
    TempNode->data = X;
    TempNode->Next = First;
    First = TempNode;

    return First;
}

LinkList *InsertToLast(LinkList *First, ElementType X)
{
    LinkList *NewNode;
    LinkList *TempNode;

    NewNode = (LinkList *)malloc(sizeof(LinkList));
    NewNode->data = X;
    NewNode->Next = NULL;
    TempNode = First;

    while (TempNode->Next != NULL)
        TempNode = TempNode->Next;

    TempNode->Next = NewNode;
    return First;
}

LinkList *DeleteHead(LinkList *First)
{
    LinkList *TempNode;

    TempNode = First->Next;
    free(First);

    return TempNode;
}

LinkList *DeleteLast(LinkList *First)
{
    LinkList *Temp1, *Temp2;
    Temp1 = First;
    Temp2 = First;

    while (Temp1->Next != NULL)
    {
        Temp2 = Temp1;
        Temp1 = Temp1->Next;
    }

    Temp2->Next = NULL;
    free(Temp1);
    return First;
}

int IsEmpty(LinkList *First)
{
    return !First;
}

LinkList *MakeNull(LinkList *First)
{
    while (!IsEmpty(First))
        First = DeleteHead(First);
    return First;
}
void Fprint(FILE *f, ElementType item)
{
    fprintf(f, "Name:  %sPhone: %sEmail: %s", item.name, item.phone, item.email);
}
void Print(FILE *f, LinkList *First)
{
    LinkList *TempNode;

    Fprint(f, First->data);
    TempNode = First->Next;
    while (TempNode != NULL)
    {
        Fprint(f, TempNode->data);
        TempNode = TempNode->Next;
    }
}