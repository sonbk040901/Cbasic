#include <stdio.h>
#include <stdlib.h>

typedef struct DT
{
    char name[40];
    char phone[15];
    char email[40];
} ElementType;

typedef struct LL
{
    ElementType data;
    struct LL *Next;
} LinkList;
LinkList *InsertMiddle(LinkList *Prev, ElementType X);
ElementType Delete(LinkList *Prev);
LinkList *InsertToHead(LinkList *First, ElementType X);
LinkList *InsertToLast(LinkList *First, ElementType X);
LinkList *DeleteHead(LinkList *First);
LinkList *DeleteLast(LinkList *First);
int IsEmpty(LinkList *First);
LinkList *MakeNull(LinkList *First);
void Fprint(FILE *f, ElementType item);
void Print(FILE *f, LinkList *First);