#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "bin.h"
#define MAX_CHOSE 6
void menu(void)
{
    printf("\t\t\t|======================================================|\n");
    printf("\t\t\t|%25sMENU%25s|\n", " ", " ");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|  1  |   %-45s|\n", "Nap tu dien");
    printf("\t\t\t|  2  |   %-45s|\n", "Noi dung tu dien");
    printf("\t\t\t|  3  |   %-45s|\n", "Them/sua tu");
    printf("\t\t\t|  4  |   %-45s|\n", "Dich cau Anh-Viet");
    printf("\t\t\t|  5  |   %-45s|\n", "Luu file tu dien");
    printf("\t\t\t|  6  |   %-45s|\n", "Ket thuc chuong trinh");
    printf("\t\t\t|======================================================|\n");
}
int main()
{
    FILE *fin = fopen("dict.txt", "r");
    // FILE *fout = fopen("")
    BinaryTree *tree;
    tree = NULL;
    int chose, i, j, k;
    ElementType x;
    char str[20][25];
    char mang[100];
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
            while (!feof(fin) && strcmp(x.anh, "NULL") && strcmp(x.viet, "NULL"))
            {
                x = PopData(fin);
                if (strcmp(x.anh, "NULL") && strcmp(x.viet, "NULL"))
                {
                    tree = InsertData(tree, x);
                    Fprint(stdout, x);
                }
            }
            break;
        case 2:
            PrintData(stdout, tree);
            break;
        case 3:
            printf("Hay nhap tu tieng anh ma ban muon them vao: ");
            scanf("%s", x.anh);
            __fpurge(stdin);
            tree = InsertData3(tree, &x);
            break;
        case 4:
            j = 0;
            k = 0;
            int n = 1;
            fgets(mang, 100, stdin);
            for (i = 0; i < strlen(mang); i++)
            {
                str[j][k++] = mang[i];
                if (mang[i + 1] == ' ' || mang[i + 1] == '\n')
                {
                    str[j][k] = 0;
                    k = 0;
                    j++;
                    n++;
                    i++;
                }
            }
            for (j = 0; j < n - 1; j++)
            {
                printf("%s\n", str[j]);
            }
            break;
        case 5:
            fclose(fin);
            FILE *fout = fopen("dict.txt", "w+");
            Print(fin, tree);
            Print(stdout, tree);
            fclose(fout);
            break;
        case 6:
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