#define B1_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
#define FULL 100 /*Gia tri nay thuoc vao gioi han cua QUEUE ma ban muon cai dat*/
typedef struct DT
{
    char name[40];
    char phone[15];
    char email[40];
} DataType;
typedef DataType ElementType;
struct BT
{
    ElementType data;
    struct BT *right;
    struct BT *left;
};
typedef struct BT BinaryTree; /*Dinh nghia kieu cay nhi phan*/
typedef struct LKD
{
    BinaryTree data1;
    struct LKD *next;
} LinkList;
typedef struct QUEUE
{
    LinkList *Front;
    LinkList *Rear;
} QUEUE;

QUEUE *MakeNullQueue(void);        /*Khoi tao mot QUEUE rong*/
int sizeQ(QUEUE *);                /*Tra ve so phan tu trong QUEUE*/
int isEmpty(QUEUE *);              /*Kiem tra QUEUE co rong khong*/
int isFull(QUEUE *);               /*Kiem tra QUEUE co day khong*/
LinkList *front(QUEUE *);          /*Tra ve con tro cua phan tu FRONT*/
void EnQueue(QUEUE *, BinaryTree); /*Them phan tu vao phia sau QUEUE*/
BinaryTree DeQueue(QUEUE *);       /*Xoa phan tu o phia truoc QUEUE va tra ve data cua phan tu do*/
void Print(QUEUE *);               /*In ra danh sach cua cac phan tu trong QUEUE*/

typedef struct BT BinaryTree;                            /*Dinh nghia kieu cay nhi phan*/
BinaryTree *MakeTreeNull(ElementType x);                 /*Khoi tao data cho mot con tro rong*/
BinaryTree *InsertData(BinaryTree *tree, ElementType x); /*Them data vao cay nhi phan*/
int sonut(BinaryTree *tree);                             /*Tra ve so nut cua cay nhi phan(ke ca nut la va nut canh)*/
int sola(BinaryTree *tree);                              /*Tra ve so nut la cua cay nhi phan*/
int docao(BinaryTree *tree);                             /*Tra ve do cao cua cay nhi phan*/
BinaryTree *Minleft(BinaryTree *tree);                   /*Tra ve dia chi nut trai nhat ben phai*/
BinaryTree *Delete(BinaryTree *tree, ElementType x);     /*Xoa mot nut bat ky trong cay*/
void Fprint(FILE *f, ElementType x);                     /*In ra data cua mot nut*/
void PrintData(FILE *f, BinaryTree *tree);               /*In ra data cua cay nhi phan (duyet theo chieu sau)*/

void PrintData_duyet_anh_em(FILE *f, BinaryTree tree); /*In ra data cua cay nhi phan (duyet ngang-anh em)*/