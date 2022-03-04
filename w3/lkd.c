#include "lkd.h"
#include <stdio.h>
#include <stdlib.h>

PointerType *InsertMiddle(PointerType *Prev, ElementType X)
{
  PointerType *TempNode;
  TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->data = X;
  TempNode->Next = Prev->Next;
  Prev->Next = TempNode;
  return TempNode;
}
ElementType Delete(PointerType *Prev)
{
  ElementType X;
  PointerType *TempNode;
  TempNode = Prev->Next;
  Prev->Next = Prev->Next->Next;
  X = TempNode->data;
  free(TempNode);
  return X;
}
PointerType *InsertToHead(PointerType *First, ElementType X)
{
  PointerType *TempNode;
  TempNode = (PointerType *)malloc(sizeof(PointerType));
  TempNode->data = X;
  TempNode->Next = First;
  First = TempNode;
  return First;
}
PointerType *InsertToLast(PointerType *First, ElementType X)
{
  PointerType *NewNode;
  PointerType *TempNode;
  NewNode = (PointerType *)malloc(sizeof(PointerType));
  NewNode->data = X;
  NewNode->Next = NULL;
  TempNode = First;
  while (TempNode->Next != NULL)
    TempNode = TempNode->Next;
  TempNode->Next = NewNode;
  return First;
}
PointerType *DeleteHead(PointerType *First)
{
  PointerType *TempNode;
  TempNode = First->Next;
  free(First);
  return TempNode;
}
PointerType *DeleteLast(PointerType *First)
{
  PointerType *Temp1, *Temp2;
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
int IsEmpty(PointerType *First)
{
  return !First;
}
PointerType *MakeNull(PointerType *First)
{
  while (!IsEmpty(First))
    First = DeleteHead(First);
  return First;
}
void Print(PointerType *First)
{
  PointerType *TempNode;
  printf("%p ", First);
  TempNode = First;
  while (TempNode != NULL)
  {
    printf("%d:%p ", TempNode->data, TempNode->Next);
    TempNode = TempNode->Next;
  }
  printf("\n");
}