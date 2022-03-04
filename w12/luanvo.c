#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <time.h>
#define MAX_CHOSE 4
typedef struct bxhType
{
    char name[40];
    int rank;
} BXH;
const BXH oo = {"zzz", -1};
int SupperCmp(BXH x, BXH y, int chose)
{
    return y.rank - x.rank;
}
void SupperCpy(BXH *key, BXH x)
{
    *key = x;
}
void Merge(BXH list[], int left, int mid, int right, int chose);
float Merge_sort(BXH list[], int left, int right, int chose);
void menu(void)
{
    printf("\t\t\t|======================================================|\n");
    printf("\t\t\t|%25sMENU%25s|\n", " ", " ");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|  1  |   %-45s|\n", "Doc du lieu");
    printf("\t\t\t|  2  |   %-45s|\n", "Tien hanh thi dau");
    printf("\t\t\t|  3  |   %-45s|\n", "Xep hang vo si");
    printf("\t\t\t|  4  |   %-45s|\n", "Ket thuc chuong trinh");
    printf("\t\t\t|======================================================|\n");
}
ElementType PopData(FILE *f)
{
    ElementType data;
    if (fscanf(f, "%s ", data.name) > 0)
    {
        fscanf(f, "%d %d %d %d\n", &(data.hp), &(data.tc), &(data.nn), &(data.pt));
    }
    return data;
}
void PrintDataQueue(QUEUE *Q)
{
    LinkList *root;
    ElementType data;
    int i = 0;
    root = Q->Front->next;
    while (root)
    {
        data = root->data;
        printf("%37s%-3d%-10s%-5d%-5d%-5d%-5d\n", " ", ++i, data.name, data.hp, data.tc, data.nn, data.pt);
        root = root->next;
    }
}
int ATACK(ElementType a, ElementType b, int *matmau)
{
    *matmau = a.tc - b.pt;
    int x = b.hp - *matmau;
    return x > 0 ? x : 0;
}
int dem = 0;
void fight(ElementType *a, ElementType *b, int i)
{
    int matmau, hp;
    if (a->hp == 0)
    {
        if (i <= 2)
        {
            b->rank += 2;
            printf("Dau si %s bi KNOCKOUT!\n\n\n", a->name);
        }
        else
            printf("Dau si %s bi loai!\n\n\n", a->name);
    }
    else
    {
        hp = ATACK(*a, *b, &matmau);
        printf("Dau si %-10s(mau con lai: %-2d) danh dau si %-10s(mau con lai: %-2d) mat %-2d mau\n", a->name, a->hp, b->name, b->hp, matmau > b->hp ? b->hp : matmau);
        a->rank++;
        b->hp = hp;
        fight(b, a, i + 1);
    }
}
int main()
{
    FILE *mp1, *mp2;
    mp1 = fopen("monphai1.txt", "r");
    mp2 = fopen("monphai2.txt", "r");
    QUEUE *Q1, *Q2;
    Q1 = MakeNullQueue();
    Q2 = MakeNullQueue();
    int chose, thoat;
    ElementType data;
    ElementType p1, p2;
    BXH *bxh;
    int i;
    do
    {
        menu();
        printf("Hay nhap lua chon cua ban: ");
        while (!scanf("%d", &chose))
        {
            printf("Nhap sai: Khong duoc nhap chu!\nChi duoc nhap so tu %d - %d\n", 1, MAX_CHOSE);
            menu();
            printf("Hay nhap lua chon cua ban: ");
            __fpurge(stdin);
        }
        __fpurge(stdin);
        switch (chose)
        {
        case 1:
            thoat = 0;
            while (!feof(mp1))
            {
                data = PopData(mp1);
                if (data.hp < 0 || data.tc < 0 || data.nn < 0 || data.pt < 0)
                {
                    thoat = 1;
                    puts("File du lieu khong hop le!!!");
                    break;
                }
                EnQueue(Q1, data);
            }
            if (thoat)
            {
                break;
            }
            while (!feof(mp2))
            {
                data = PopData(mp2);
                if (data.hp < 0 || data.tc < 0 || data.nn < 0 || data.pt < 0)
                {
                    thoat = 1;
                    puts("File du lieu khong hop le!!!");
                    break;
                }
                EnQueue(Q2, data);
            }
            if (thoat)
            {
                break;
            }
            if (sizeQ(Q1) != sizeQ(Q2))
            {
                puts("Luc luong cua hai mon phai khong can bang!!!");
                break;
            }
            printf("%47sMon phai 1:\n", " ");
            PrintDataQueue(Q1);
            printf("%47sMon phai 2:\n", " ");
            PrintDataQueue(Q2);
            bxh = (BXH *)malloc(sizeof(BXH) * (sizeQ(Q1) + sizeQ(Q2)));
            break;
        case 2:
            p1.hp = 0;
            p2.hp = 0;
            i = 0;
            while (!isEmptyQ(Q1) || !isEmptyQ(Q2))
            {
                if (p1.hp == 0 && !isEmptyQ(Q1))
                {
                    bxh[p1.index].rank = p1.rank;
                    p1 = DeQueue(Q1);
                    p1.rank = 0;
                    strcpy(bxh[i].name, p1.name);
                    p1.index = i++;
                }
                if (p2.hp == 0 && !isEmptyQ(Q2))
                {
                    bxh[p2.index].rank = p2.rank;
                    p2 = DeQueue(Q2);
                    p2.rank = 0;
                    strcpy(bxh[i].name, p2.name);
                    p2.index = i++;
                }
                if (p1.hp != 0 && p2.hp != 0)
                {
                    printf("Tran thu %i\n", ++dem);
                    if (p1.nn > p2.nn)
                        fight(&p1, &p2, 1);
                    else
                        fight(&p2, &p1, 1);
                }
                else
                    break;
            }
            printf("Mon phai %d thang!\n", p1.hp ? 1 : 2);
            bxh[p1.index].rank = p1.rank;
            bxh[p2.index].rank = p2.rank;
            while (!isEmptyQ(Q1))
            {
                strcpy(bxh[i].name, DeQueue(Q1).name);
                bxh[i++].rank = 0;
            }
            while (!isEmptyQ(Q2))
            {
                strcpy(bxh[i].name, DeQueue(Q2).name);
                bxh[i++].rank = 0;
            }
            break;
        case 3:
            Merge_sort(bxh, 0, 9, 0);
            printf("\t\t\t\tBANG XEP HANG\n");
            printf("\t\t\t%10s\t%5s\n", "NAME", "RANK");
            for (int k = 0; k < 10; k++)
            {
                printf("\t\t\t%10s\t%5d\n", bxh[k].name, bxh[k].rank);
            }
            break;
        case 4:
            printf("\tKet thuc chuong trinh\n");
            chose = 0;
            fclose(mp1);
            fclose(mp2);
            free(bxh);
            while (!isEmptyQ(Q1))
            {
                DeQueue(Q1);
            }
            while (!isEmptyQ(Q2))
            {
                DeQueue(Q2);
            }
            break;
        default:
            printf("Chi duoc chon cac so tu %d - %d!!!\n", 1, MAX_CHOSE);
            chose = 1;
            break;
        }
    } while (chose);
    return 0;
}
void Merge(BXH list[], int left, int mid, int right, int chose)
{
    BXH *L, *R;
    int i = 0, j = 0, k, a, b;
    L = (BXH *)malloc(sizeof(BXH) * (mid - left + 2));
    R = (BXH *)malloc(sizeof(BXH) * (right - mid + 1));
    a = 0;
    for (int f = left; f <= mid; f++)
    {
        L[a++] = list[f];
    }
    SupperCpy(&L[a], oo);
    b = 0;
    for (int f = mid + 1; f <= right; f++)
    {
        R[b++] = list[f];
    }
    SupperCpy(&R[b], oo);
    for (k = left; k <= right; k++)
    {
        if (SupperCmp(L[i], R[j], chose) <= 0)
            list[k] = L[i++];
        else
            list[k] = R[j++];
    }
    free(L);
    free(R);
}
float Merge_sort(BXH list[], int left, int right, int chose)
{
    clock_t tstart, tfinish;
    tstart = clock();
    if (left < right)
    {
        int mid = (left + right) / 2;
        Merge_sort(list, left, mid, chose);
        Merge_sort(list, mid + 1, right, chose);
        Merge(list, left, mid, right, chose);
    }
    tfinish = clock();
    return (float)(tfinish - tstart) / CLOCKS_PER_SEC;
}