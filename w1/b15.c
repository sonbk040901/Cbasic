#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define MAX 20
int replace_char(char *str, char c1, char c2)
{
    int returnvalue = 0;
    for (int i = 0; i < strlen(str); i++)
        if (*(str + i) == c1)
        {
            *(str + i) = c2;
            returnvalue++;
        }
    return returnvalue;
}
int main(int argc, char const *argv[])
{
    char *str, x, y;
    str = (char *)malloc(sizeof(char) * MAX);
    gets(str);
    __fpurge(stdin);
    x = getchar();
    __fpurge(stdin);
    y = getchar();
    if (replace_char(str, x, y))
        puts(str);
    else
        printf("Khong ton tai ky tu %c trong string nhap vao!!!\n", x);
    return 0;
}
