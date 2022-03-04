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
const ElementType zero = {"Not Found\n", "Not Found\n", "Not Found\n"};
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
ElementType Bin_Search(Adr a[], int lower, int highter, char key[])
{
    if (lower == highter)
    {
        printf("check...\n");
        return strcmp(a[lower].name, key) == 0 ? a[lower] : zero;
    }
    int mid = (lower + highter) / 2;
    if (strcmp(a[mid].name, key) == 0)
    {
        puts("Tim thay!");
        return a[mid];
    }
    else if (strcmp(a[mid].name, key) > 0)
    {
        printf("Bin_Search(a, %d, %d, key)\n", lower, mid - 1);
        return Bin_Search(a, lower, mid - 1, key);
    }
    else
    {
        printf("Bin_Search(a, %d, %d, key)\n", mid + 1, highter);
        return Bin_Search(a, mid + 1, highter, key);
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
    printf("Bin_Search(a, %d, %d, key)\n", 0, i - 1);
    search = Bin_Search(Arr, 0, i - 1, key);
    fprintf(fout, "Name: %sPhone: %sEmail: %s", search.name, search.phone, search.email);
    fclose(fin);
    fclose(fout);
}