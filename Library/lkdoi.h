#define LKDOI_H
#include <stdio.h>
#include <stdlib.h>
#ifndef STRUCT_DT
#define STRUCT_DT
typedef struct DT
{
    char name[40];
    char phone[15];
    char email[40];
} DataType;
typedef DataType ElementType;
const ElementType NotFound = {"Not Found", "Not Found", "Not Found"};
#endif
typedef struct Node
{
    ElementType data;
    struct Node *Next;
    struct Node *Prev;
} Node;
typedef struct lkdoi
{
    Node *head;
    Node *tail;
} LKDOI;
Node *GetNewNode(ElementType x);            /*Tao Node moi*/
void InsertAtHead(LKDOI *L, ElementType x); /*Them Node moi vao head*/
void InsertAtTail(LKDOI *L, ElementType x); /*Them Node moi vao tail*/
void DeleteAtHead(LKDOI *L);                /*Xoa Node o head*/
void DeleteAtTail(LKDOI *L);                /*Xoa NOde o tail*/
void Print(LKDOI L);                        /*In ra data cua list tu head->tail*/
void ReversePrint(LKDOI L);                 /*In ra data cua list tu tail->head*/