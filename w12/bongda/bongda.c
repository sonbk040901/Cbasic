#include "lkd.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define MAX_CHOSE 5
void menu(void)
{
    printf("\t\t\t|======================================================|\n");
    printf("\t\t\t|%25sMENU%25s|\n", " ", " ");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|  1  |   %-45s|\n", "In thong tin cac doi bong ");
    printf("\t\t\t|  2  |   %-45s|\n", "In thong tin lich thi dau");
    printf("\t\t\t|  3  |   %-45s|\n", "Cap nhat ket qua vong dau");
    printf("\t\t\t|  4  |   %-45s|\n", "Thong ke");
    printf("\t\t\t|  5  |   %-45s|\n", "Ket thuc chuong trinh");
    printf("\t\t\t|======================================================|\n");
}
int main()
{
    FILE *f;
    f = fopen("bongda.txt", "r");
    if (f == NULL)
    {
        printf("Khong the truy cap file!");
        exit(1);
    }
    int chose, n, k, x;
    char name[30];
    PointerType *First, *root;
    First = NULL;
    fscanf(f, "%d", &n);
    char **doi;
    doi = (char **)malloc(sizeof(char *) * n);
    k = n / 2;
    ElementType data;
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
            for (int i = 0; i < n; i++)
            {
                doi[i] = (char *)malloc(sizeof(char));
                fscanf(f, "%d   %s", &(data.id), data.ten);
                strcpy(doi[i], data.ten);
                data.banthang = 0;
                data.banthua = 0;
                data.diem = 0;
                First = InsertToLast(First, data);
            }
            printf("%-10s%-15s%-10s%-20s%-20s\n", "ID", "Tendoibong", "Diem", "Sobathang", "Sobanthua");
            root = First;
            for (int i = 0; i < n; i++)
            {
                printf("%-10d%-19s%-13d%-20d%-20d\n", root->data.id, root->data.ten, root->data.diem, root->data.banthang, root->data.banthua);
                root = root->Next;
            }
            for (int i = 0; i < n; i++)
            {
                printf("%s", doi[i]);
            }
            break;
        case 2:
            // for (int i = 0; i < k + 1; i++)
            // {
            //     fgets(name, 30, f);
            //     printf("%s", name);
            //     fscanf(f, "%d", &x);
            //     printf("%-4d");
            //     fscanf(f, "%d", &x);
            //     printf("%-4d");
            // }
            break;
        case 3:
            /* Lua chon thu ba */
            break;
        case 4:
            /* Lua chon thu tu */
            break;
        case 5:
            free(doi);
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