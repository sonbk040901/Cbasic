#define BIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
#ifndef STRUCT_DT
#define STRUCT_DT
typedef struct DT
{
    char tencpu[5];
    int dungluon;
} DataType;
typedef DataType ElementType;
#endif
struct BT
{
    ElementType data;
    struct BT *right;
    struct BT *left;
};
typedef struct BT BinaryTree;                                          /*Dinh nghia kieu cay nhi phan*/
BinaryTree *MakeTreeNode(ElementType x);                               /*Khoi tao data cho mot con tro rong*/
int SupperCmp(ElementType x, ElementType y, int mode);                 /**/
BinaryTree *InsertData(BinaryTree *tree, ElementType x, int mode);     /*Them data vao cay nhi phan*/
int sonut(BinaryTree *tree);                                           /*Tra ve so nut cua cay nhi phan(ke ca nut la va nut canh)*/
int sola(BinaryTree *tree);                                            /*Tra ve so nut la cua cay nhi phan*/
int docao(BinaryTree *tree);                                           /*Tra ve do cao cua cay nhi phan*/
BinaryTree *Min(BinaryTree *tree);                                     /*Tra ve dia chi nut trai nhat ben phai cua nut hien tai*/
BinaryTree *Max(BinaryTree *tree);                                     /*Tra ve dia chi nut phai nhat ben trai cua nut hien tai*/
BinaryTree *Delete(BinaryTree *tree, ElementType x, int mode);         /*Xoa mot nut bat ky trong cay*/
void Fprint(FILE *f, ElementType x);                                   /*In ra data cua mot nut*/
void PrintData(FILE *f, BinaryTree *tree);                             /*In ra data cua cay nhi phan va free(duyet theo chieu sau)*/
void PrintDataVip(FILE *f, BinaryTree *tree);                          /*In ra data cua cay nhi phan nhung khong free*/
BinaryTree *BinarySearch(BinaryTree *tree, ElementType key, int mode); /*Tim kiem va tra ve dia chi cua nut co khoa key va tra ve Null neu khong tim thay*/

void PrintData_duyet_anh_em(FILE *f, BinaryTree *tree); /*In ra data cua cay nhi phan (duyet ngang-anh em)*/