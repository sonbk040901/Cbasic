#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Address
{
    char name[40];
    char phone[15];
    char email[40];
};
typedef struct Address ElementType, Adr;
ElementType Pop_Data(FILE *f, int *i)
{
    ElementType data;
    while (fgets(data.name, MAX, f))
    {
        (*i)++;
        fgets(data.phone, MAX, f);
        fgets(data.email, MAX, f);
        printf("%s", data.name);
        return data;
    }
}
void Print(FILE *f, Adr x)
{
    fputs(x.name, f);
    fputs(x.phone, f);
    fputs(x.email, f);
}
void Bin_Search(FILE *f, Adr a[], int lower, int highter, char key[])
{
    if (lower == highter)
    {
        if (strcmp(a[lower].name, key) == 0)
        {
            Print(f, a[lower]);
        }
    }
    else
    {
        int mid = (lower + highter) / 2;
        if (strcmp(a[mid].name, key) == 0)
        {
            Print(f, a[mid]);
        }
        Bin_Search(f, a, lower, mid, key);
        Bin_Search(f, a, mid + 1, highter, key);
    }
}
void main()
{
    FILE *fin;
    FILE *fout;
    int i = 0;
    char key[40];
    ElementType search;
    fin = fopen("datasx.txt", "r");
    fout = fopen("data1.txt", "w+");
    Adr Arr[MAX];
    while (!feof(fin))
    {
        Arr[i] = Pop_Data(fin, &i);
    }
    puts("Hay nhap ten user ban muon tim thong tin: ");
    fgets(key, 40, stdin);
    Bin_Search(fout, Arr, 0, i - 1, key);
    fclose(fin);
    fclose(fout);
}