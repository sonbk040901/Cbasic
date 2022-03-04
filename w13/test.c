#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include "linked.h"
int main()
{
    FILE *fin = fopen("data.txt", "r");
    FILE *fout = fopen("danhsach.txt", "w+");
    PointerType *First;
    First = NULL;
    ElementType dl;
    for (int i = 0; i < 10; i++)
    {
        fgets(dl.name, 40, fin);
        fgets(dl.phone, 15, fin);
        fgets(dl.email, 40, fin);
        First = InsertToHead(First, dl);
    }
    Print(First);
    fclose(fin);
    fclose(fout);
    return 0;
}