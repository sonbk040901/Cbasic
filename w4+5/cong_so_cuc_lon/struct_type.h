#define STRUCT_TYPE_H_
#include <stdio.h>
#include <stdlib.h>
#define FULL 100 /*Gia tri nay thuoc vao gioi han cua QUEUE ma ban muon cai dat*/
typedef int ElementType;
typedef struct LKD
{
    ElementType data;
    struct LKD *next;
} LinkList;