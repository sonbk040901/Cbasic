#define BIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
typedef struct DT
{
    char anh[25];
    char viet[25];
} DataType;
typedef DataType ElementType;
struct BT
{
    ElementType data;
    struct BT *right;
    struct BT *left;
};
typedef struct BT BinaryTree;                            /*Dinh nghia kieu cay nhi phan*/
BinaryTree *MakeTreeNull(ElementType x);                 /*Khoi tao data cho mot con tro rong*/
BinaryTree *InsertData(BinaryTree *tree, ElementType x); /*Them data vao cay nhi phan*/
BinaryTree *InsertData3(BinaryTree *tree, ElementType *x);
int sonut(BinaryTree *tree);                             /*Tra ve so nut cua cay nhi phan(ke ca nut la va nut canh)*/
int sola(BinaryTree *tree);                              /*Tra ve so nut la cua cay nhi phan*/
int docao(BinaryTree *tree);                             /*Tra ve do cao cua cay nhi phan*/
BinaryTree *Minleft(BinaryTree *tree);                   /*Tra ve dia chi nut trai nhat ben phai*/
BinaryTree *delete (BinaryTree *tree, ElementType x);    /*Xoa mot nut bat ky trong cay*/
void Fprint(FILE *f, ElementType x);                     /*In ra data cua mot nut*/
void PrintData(FILE *f, BinaryTree *tree);               /*In ra data cua cay nhi phan (duyet theo chieu sau)*/
void Print(FILE *f, BinaryTree *tree);
ElementType PopData(FILE *f);
void PrintData_duyet_anh_em(FILE *f, BinaryTree *tree); /*In ra data cua cay nhi phan (duyet ngang-anh em)*/