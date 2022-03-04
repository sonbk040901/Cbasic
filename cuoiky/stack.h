#define STACK_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FULL 100 /*Gia tri nay thuoc vao gioi han cua STACK ma ban muon cai dat*/
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
#ifndef STRUCT_LKD
#define STRUCT_LKD
typedef struct LKD
{
    ElementType data;
    struct LKD *next;
} LinkList;
#endif
typedef struct STACK
{
    LinkList *top;
} STACK;
STACK *MakeNullStack(void);        /*Khoi tao STACK rong*/
int sizeS(STACK *S);               /*Tra ve do dai cua STACK*/
int isEmptyS(STACK *S);            /*Kiem tra STACK co rong hay khong*/
int isFullS(STACK *S);             /*Kiem tra STACK co day hay khong*/
int Push(STACK *S, ElementType x); /*Chen them mot phan tu vao STACK*/
ElementType Pop(STACK *S);         /*Xoa phan tu o vi tri TOP va tra ve data cua phan tu do*/
void PrintS(STACK *S);             /*In ra data cua cac phan tu trong STACK*/