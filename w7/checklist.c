#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define MAX 100
struct Address
{
    char name[40];
    char phone[15];
    char email[40];
};
typedef struct Address ElementType, Adr[MAX];
const ElementType zero = {"Not Found\n", "Not Found\n", "Not Found\n"};
ElementType Pop_Data(FILE *f)
{
    ElementType data;
    while (fgets(data.name, MAX, f))
    {
        fgets(data.phone, MAX, f);
        fgets(data.email, MAX, f);
        return data;
    }
}
void arrarr(Adr a, int x, Adr b, int y, FILE *f)
{
    int j;
    for (int i = 0; i < x; i++)
    {
        j = 0;
        while (strcmp(a[i].name, b[j].name) && j < y && ++j);
        if (j == y)
        {
            fputs(a[i].name, f);
            fputs(a[i].phone, f);
            fputs(a[i].email, f);
        }
    }
}
void arrarr1(Adr a, int x, Adr b, int y, FILE *f)
{
    int j;
    for (int i = 0; i < x; i++)
    {
        j = 0;
        while (j < y)
        {
            while (++j && strcmp(a[i].name, b[j - 1].name) && j < y)
                ;
            if (j < y && (strcmp(a[i].email, b[j - 1].email) || strcmp(a[i].phone, b[j - 1].phone)))
            {
                fputs(a[i].name, f);
                fputs(a[i].phone, f);
                fputs(a[i].email, f);
                fputs(b[j-1].name, f);
                fputs(b[j-1].phone, f);
                fputs(b[j-1].email, f);
            }
        }
    }
}
void main()
{
    FILE *fin;
    FILE *fout;
    fin = fopen("data.txt", "r");
    fout = fopen("data1.txt", "w+");
    Adr arr1, arr2;
    ElementType node;
    int i = 0, a = 0, b = 0, chose = 4;
    while (!feof(fin))
    {
        ++i;
        node = Pop_Data(fin);
        if (i % 2 == 0)
        {
            arr1[a++] = node;
        }
        if (i % 3 == 0)
        {
            arr2[b++] = node;
        }
    }
    do
    {
        printf("Hay nhap lua chon cua ban(0-1-2-3): ");
        scanf("%d", &chose);
        __fpurge(stdin);
        switch (chose)
        {
        case 1:
            fputs("Ket qua case1:\n\n", fout);
            arrarr(arr1, a, arr2, b, fout);
            fputs("\n", fout);
            break;
        case 2:
            fputs("Ket qua case2:\n\n", fout);
            arrarr(arr2, b, arr1, a, fout);
            fputs("\n", fout);
            break;
        case 3:
            arrarr1(arr1, a, arr2, b, fout);
            break;
        case 0:
            break;
        default:
            printf("%50cChi duoc nhap 0-1-2-3!!!\n", ' ');
            chose = 4;
            break;
        }
    } while (chose);
    fclose(fin);
    fclose(fout);
}