#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
typedef int gtri; /*Dinh nghia kieu gia tri*/
#define NAME "%d" /*Dinh nghia nguyen mau cua gia tri*/
struct LKD  /*Struct dinh nghia mang*/
{
    gtri v;
    struct LKD *Next;
};
typedef struct LKD LinkList;
LinkList *themdaumang(LinkList *first, gtri x) /*Ham them phan tu vao dau mang gia tri*/
{
    LinkList *LinkLister;
    LinkLister = (LinkList *)malloc(sizeof(LinkList));
    LinkLister->v = x;
    LinkLister->Next = first;
    first = LinkLister;
    return first;
}
LinkList *themgiuamang(LinkList *first, gtri x, int n) /*Ham them phan tu vao giua mang*/
{
    LinkList *LinkLister;
    LinkList *mid;
    LinkList *head;
    int i;
    LinkLister = (LinkList *)malloc(sizeof(LinkList));
    mid = (LinkList *)malloc(sizeof(LinkList));
    head = (LinkList *)malloc(sizeof(LinkList));
    head = first;
    for (i = 2; i < n; i++)
    {
        head = head->Next;
    }
    LinkLister = head->Next;
    head->Next = mid;
    mid->v = x;
    mid->Next = LinkLister;
    return first;
}
LinkList *themcuoimang(LinkList *first, gtri x) /*Ham them phan tu vao cuoi mang*/
{
    LinkList *LinkLister, *end;
    LinkLister = (LinkList *)malloc(sizeof(LinkList));
    end = (LinkList *)malloc(sizeof(LinkList));
    end->v = x;
    LinkLister = first;
    while (LinkLister->Next != NULL)
    {
        LinkLister = LinkLister->Next;
    }
    LinkLister->Next = end;
    return first;
}
void Print(LinkList *mang) /*Ham in ra gia tri trong mang*/
{
    LinkList *LinkLister;
    LinkLister = (LinkList *)malloc(sizeof(LinkList));
    LinkLister = mang;
    while (LinkLister != NULL)
    {
        printf(NAME, LinkLister->v);
        printf(" %p\t", LinkLister->Next);
        LinkLister = LinkLister->Next;
    }
    putchar('\n');
}
void menu() /*MENU cua chuong trinh*/
{
    printf("I,     Them du lieu vao dau mang\n");
    printf("II,    Them du lieu vao giua mang\n");
    printf("III,   Them du lieu vao cuoi mang\n");
}
void main()
{
    LinkList *arr = NULL;
    gtri a;
    int chose, i;
    char check;
    do
    {
        puts("Hay nhap lua chon cua ban:");
        menu();
        while (scanf("%d", &chose) != 1)
        {
            puts("Hay nhap lai lua chon: ");
            __fpurge(stdin);
        }
        switch (chose)
        {
        case 1: /*Them phan tu vao dau mang*/
            printf("Hay nhap gia tri ma ban muon them vao dau mang:\n");
            __fpurge(stdin);
            while (scanf(NAME, &a))
            {
                arr = themdaumang(arr, a);
                __fpurge(stdin);
            }
            Print(arr);
            break;
        case 2: /*Them phan tu vao giua mang*/
            printf("Hay nhap vi tri ban muon chen vao: ");
            scanf("%d", &i);
            arr = themgiuamang(arr, 100, i);
            Print(arr);
            break;
        case 3: /*Them phan tu vao cuoi mang*/
            printf("Hay nhap gia tri ma ban muon them vao cuoi mang:\n");
            __fpurge(stdin);
            while (scanf(NAME, &a))
            {
                arr = themcuoimang(arr, a);
                __fpurge(stdin);
            }
            Print(arr);
            break;
        case 4 : /*Xoa phan tu trong mang*/

        default:
            chose = 10;
            break;
        }
    } while (chose != 10);
    free(arr);
}