#include "lkdoi.h"
Node *GetNewNode(ElementType x)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->Prev = NULL;
    newNode->Next = NULL;
    return newNode;
}
void InsertAtHead(LKDOI *L, ElementType x)
{
    Node *newNode = GetNewNode(x);
    if (!(L->head))
    {
        L->head = newNode;
        L->tail = newNode;
    }
    else
    {
        L->head->Prev = newNode;
        newNode->Next = L->head;
        L->head = newNode;
    }
}
void InsertAtTail(LKDOI *L, ElementType x)
{
    Node *newNode = GetNewNode(x);
    if (!(L->head))
    {
        L->head = newNode;
        L->tail = newNode;
    }
    else
    {
        L->tail->Next = newNode;
        newNode->Prev = L->tail;
        L->tail = newNode;
    }
}
void DeleteAtHead(LKDOI *L)
{
    if (L->head)
    {
        L->head = L->head->Next;
        free(L->head->Prev);
        L->head->Prev = NULL;
    }
}
void DeleteAtTail(LKDOI *L)
{
    if (L->head)
    {
        L->tail = L->tail->Prev;
        free(L->tail->Next);
        L->tail->Next = NULL;
    }
}
void Print(LKDOI L)
{
    Node *temp = L.head;
    printf("\nForward: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->Next;
    }
    printf("\n");
}
void ReversePrint(LKDOI L)
{
    Node *temp = L.tail;
    printf("\nReverse: ");
    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->Prev;
    }
    printf("\n");
}