#define SD_MANG_H
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAX 51 //Toi da la 51
typedef struct DT
{
    char name[40];
    char phone[15];
    char email[40];
} DataType;
typedef DataType ElementType;
const ElementType oo = {"zzz", "zzz", "zzz"};
void SWAP(ElementType *x, ElementType *y);                  /*Doi du lieu cua hai bien*/
int SupperCmp(ElementType x, ElementType y, int chose);     /*So sanh data cua 2 phan tu*/
void SupperCpy(ElementType *key, ElementType x);            /*Copy data tu x sang key*/
float insertion_sort(ElementType list[], int n, int chose); /*Sap xep chen*/
float slection_sort(ElementType a[], int n, int chose);     /*Sap xep chon*/
void adjust(ElementType list[], int root, int n, int chose);
float heap_sort(ElementType list[], int n, int chose);
int partiton(ElementType list[], int left, int right, int chose);
float quick_sort(ElementType list[], int left, int right, int chose);
void Merge(ElementType list[], int left, int mid, int right, int chose);
float Merge_sort(ElementType list[], int left, int right, int chose);
void Fprint(FILE *f, ElementType x);
ElementType PopData(FILE *f);