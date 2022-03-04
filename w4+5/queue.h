#define QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct_type.h"
typedef struct QUEUE
{
    LinkList *Front;
    LinkList *Rear;
} QUEUE;
QUEUE *MakeNullQueue(void);         /*Khoi tao mot QUEUE rong*/
int sizeQ(QUEUE *);                 /*Tra ve so phan tu trong QUEUE*/
int isEmptyQ(QUEUE *);              /*Kiem tra QUEUE co rong khong*/
int isFullQ(QUEUE *);               /*Kiem tra QUEUE co day khong*/
LinkList *front(QUEUE *);           /*Tra ve con tro cua phan tu FRONT*/
void EnQueue(QUEUE *, ElementType); /*Them phan tu vao phia sau QUEUE*/
ElementType DeQueue(QUEUE *);       /*Xoa phan tu o phia truoc QUEUE va tra ve data cua phan tu do*/
void PrintQ(QUEUE *);               /*In ra danh sach cua cac phan tu trong QUEUE*/