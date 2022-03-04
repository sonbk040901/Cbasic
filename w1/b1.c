#include<stdio.h>
#include<stdio_ext.h>
#include<string.h>
#include<stdlib.h>
#define MAX 20
void main()
{
    char *str, a, b;
    str=malloc(MAX*sizeof(char));
    printf("Hay nhap vao mot string:\n");
    scanf("%s", str);
    __fpurge(stdin);
    printf("Hay nhap vao ky tu can thay the:");
    a=getchar();
    __fpurge(stdin);
    printf("Hay nhap vao ky tu sau khi thay the:");
    b=getchar();
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==a)
        str[i]=b;
    }
    puts(str);
    free(str);
}