#define STRUCT_TYPE_H_
#include <stdio.h>
#include <stdlib.h>
#define FULL 100 /*Gia tri nay thuoc vao gioi han cua QUEUE ma ban muon cai dat*/
typedef struct DT
{
    char name[40];
    char phone[15];
    char email[40];
} DataType;
typedef DataType ElementType;
const ElementType NotFound = {"Not Found", "Not Found", "Not Found"};
typedef struct LKD
{
    ElementType data;
    struct LKD *next;
} LinkList;