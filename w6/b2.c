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
typedef struct Address ElementType;
int get_data(FILE *f, ElementType list[])
{
    int i;
    for (i = 0; i < MAX && !feof(f); i++)
    {
        fgets(list[i].name, 40, f);
        fgets(list[i].phone, 15, f);
        fgets(list[i].email, 40, f);
    }
    return i;
}
int search(char *name, ElementType *key, ElementType list[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (strcmp(name, list[i].name) == 0)
            break;
    if (i == n)
        return 0;
    *key = list[i];
    return 1;
}
void Print_Data(FILE *f, ElementType data)
{
    fputs(data.name, f);
    fputs(data.phone, f);
    fputs(data.email, f);
}
void main()
{
    ElementType list[MAX];
    ElementType info;
    FILE *fin;
    FILE *fout;
    char name[40];
    fin = fopen("data.txt", "r");
    fout = fopen("data1.txt", "w+");
    int n = get_data(fin, list);
    puts("Hay nhap ten cua user can tim: ");
    fgets(name, 40, stdin);
    if (search(name, &info, list, n))
        Print_Data(fout, info);
    fclose(fin);
    fclose(fout);
}