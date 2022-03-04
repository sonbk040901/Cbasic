#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define MAX 100
#define MIN 6
typedef struct tudien
{
    char tu[MIN];
} CV;
void main()
{
    CV c[MAX];
    char str[MAX];
    char check, ch;
    int i, j = 0, k = 0;
    printf("Hay nhap mang cua ban: ");
    gets(str);
    __fpurge(stdin);
    printf("Hay nhap keyword: ");
    check = getchar();
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == 0)
        {
            c[k].tu[j] = 0;
            i++;
            k++;
            j = 0;
        }
        c[k].tu[j] = str[i];
        j++;
    }
    for (j = 0; j <= k; j++)
    {
        printf("%s ", c[j].tu);
    }
    printf("Dap an day con cho:\n");
    for (j = 0; j <= k; j++)
    {
        if (strrchr(c[j].tu, check))
        {
            puts(c[j].tu);
        }
    }
}