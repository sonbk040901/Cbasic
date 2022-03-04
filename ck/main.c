#include <stdio.h> //LE DUC SON-20194658
#include <stdlib.h>
#include <stdio_ext.h>
#include "lkd.h"
#include <string.h>
#define MAX_CHOSE 6
void menu(void)
{
    printf("\t\t\t|======================================================|\n");
    printf("\t\t\t|%25sMENU%25s|\n", " ", " ");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|  1  |   %-45s|\n", "Nap file log lich su di chuyen");
    printf("\t\t\t|  2  |   %-45s|\n", "In ra lich su di chuyen");
    printf("\t\t\t|  3  |   %-45s|\n", "Tim kiem lich su theo dia diem");
    printf("\t\t\t|  4  |   %-45s|\n", "Tim kiem lich su theo thoi gian");
    printf("\t\t\t|  5  |   %-45s|\n", "Kiem tra truy vet moi nhat");
    printf("\t\t\t|  6  |   %-45s|\n", "Ket thuc chuong trinh");
    printf("\t\t\t|======================================================|\n");
}
void Inthudata(PointerType *First)
{
    PointerType *root;
    root = First;
    printf("\t\t\t%-50s%-10s%-10s\n", "Dia diem", "Gio", "Phut");
    while (root)
    {
        printf("\t\t\t%-50s%-10d%-10d\n", root->data.diadiem, root->data.gio, root->data.phut);
        root = root->Next;
    }
}
void Timkiem_vitri(PointerType *First, ElementType key)
{
    PointerType *root;
    root = First;
    int i = 0;
    while (root)
    {
        if (strcmp(root->data.diadiem, key.diadiem) == 0)
        {
            if (i)
            {
                printf(", ");
            }
            printf("%d:%d", root->data.gio, root->data.phut);
            ++i;
        }
        root = root->Next;
    }
    if (i == 0)
    {
        printf("Ban chua toi dia diem do lan nao trong ngay hom nay\n");
    }
    else
        printf("\n");
}
void Timkiem_thoigian(PointerType *First, ElementType key)
{
    PointerType *root;
    root = First;
    while (root)
    {
        if (root->data.gio == key.gio && root->data.phut == key.phut)
            break;
        root = root->Next;
    }
    if (root)
    {
        printf("Vao thoi gian nay ban dang o vi tri: %s\n", root->data.diadiem);
    }
    else
        printf("KHONG tim thay lich su di chuyen!\n");
}
void warning(PointerType *First, ElementType key)
{
    PointerType *root, *root2;
    root = First;
    float now, next;
    float check = key.gio + (float)(key.phut) / 60;
    while (root)
    {
        if (strcmp(root->data.diadiem, key.diadiem) == 0)
        {
            now = root->data.gio + (float)(root->data.phut) / 60;
            root2 = root->Next;
            next = root2->data.gio + (float)root2->data.phut / 60;
            if (check >= now && check <= next)
            {
                printf("Ban co kha nang bi lay covid, can phai khai bao y te ngay lap tuc!\n");
                break;
            }
        }
        root = root->Next;
    }
    if (!root)
    {
        printf("Lich su di chuyen cua ban OKE\n");
    }
}
int main()
{
    PointerType *First, *root;
    First = NULL;
    ElementType data;
    FILE *f;
    f = fopen("log.txt", "r");
    if (!f)
    {
        printf("Khong the moi file!!\n");
        exit(1);
    }
    int chose;
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
            while (!feof(f))
            {
                if (fscanf(f, "%s %d %d\n", data.diadiem, &(data.gio), &(data.phut)) > 0)
                    First = InsertToLast(First, data);
            }
            break;
        case 2:
            Inthudata(First);
            break;
        case 3:
            printf("Hay nhap mot dia diem: ");
            __fpurge(stdin);
            fgets(data.diadiem, 40, stdin);
            __fpurge(stdin);
            data.diadiem[strlen(data.diadiem) - 1] = 0;
            Timkiem_vitri(First, data);
            break;
        case 4:
            do
            {
                printf("Hay nhap thoi gian ma ban muon kiem tra(gio:phut): ");
                while (scanf("%d%*c%d", &(data.gio), &(data.phut)) < 2)
                {
                    printf("Chua nhap du thong so ve thoi gian!!!\n");
                    __fpurge(stdin);
                }
                __fpurge(stdin);
                if (data.gio < 0 || data.phut < 0 || data.gio > 24 || data.phut > 60)
                {
                    printf("Khong dung dinh dang gio!!!\n");
                    continue;
                }
                else
                    break;
            } while (1);
            __fpurge(stdin);
            Timkiem_thoigian(First, data);
            break;
        case 5:
            printf("Hay nhap thoi gian dia dia can truy vet: ");
            __fpurge(stdin);
            scanf("%s %d %d", data.diadiem, &(data.gio), &(data.phut));
            __fpurge(stdin);
            warning(First, data);
            break;
        case 6:
            MakeNull(First);
            fclose(f);
            printf("\tKet thuc chuong trinh\n");
            chose = 0;
            break;
        default:
            printf("Chi duoc chon cac so tu %d - %d!!!\n", 1, MAX_CHOSE);
            chose = 1;
            break;
        }
    } while (chose);
    return 0;
}