#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#define MAX 1
typedef struct phoneaddress
{
    char name[20];
    char telephone[20];
    char email[100];
} phone;
void main(int a, char *b[])
{
    phone info[MAX];
    int i, j, k, check;
    FILE *fout=fopen(b[1], "w+");
    if(fout==NULL)
    {
        printf("File not found!\n");
        exit(1);
    }
    for (i = 0; i < MAX; i++)
    {
        printf("\t\t\tHAY NHAP THONG TIN CHO NGUOI DUNG THU %i\n", i + 1);
        printf("Hay nhap ten user: ");
        fgets(info[i].name, 20, stdin);
        info[i].name[strlen(info[i].name) - 1] = 0;
        printf("Hay nhap phonenumber cua %s: ", info[i].name);
        do
        {
            __fpurge(stdin);
            fgets(info[i].telephone, 20, stdin);
            info[i].telephone[strlen(info[i].telephone) - 1] = 0;
            for (k = 0; k < strlen(info[i].telephone); k++)
            {
                if (isdigit(info[i].telephone[k]) == 0)
                {
                    printf("So dien thoai chi duoc la 10 chu so!\n");
                    break;
                }
            }
        } while (k != 10);
        printf("Hay nhap emailaddress cua %s: ", info[i].name);
        do
        {
            fgets(info[i].email, 100, stdin);
            info[i].email[strlen(info[i].email) - 1] = 0;
            ;
            if (strstr(info[i].email, "@gmail.com") == NULL && strstr(info[i].email, "@email.com") == NULL)
                printf("Email phai co duoi la @gmail.com hoac @email.com!\n");
        } while (strstr(info[i].email, "@gmail.com") == NULL && strstr(info[i].email, "@email.com") == NULL);
    }
    for(i=0;i<MAX;i++)
    {
        fwrite(info[i].name, sizeof(char), strlen(info[i].name), fout);
        fputc('\t', fout);
        fwrite(info[i].telephone, sizeof(char), 10, fout);
        fputc('\t', fout);
        fwrite(info[i].email, sizeof(char), strlen(info[i].email), fout);
        fputc('\n', fout);
    }
}