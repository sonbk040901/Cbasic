#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define MAX_CHOSE 7
#define MAX 100
typedef struct Node
{
    char name;
    struct directory *thumuccon;
} Node;
typedef struct directory
{
    int file[MAX];
    Node thumuc[MAX];
} directory;
void menu()
{
    printf("\t\t\t|======================================================|\n");
    printf("\t\t\t|%25sMENU%25s|\n", " ", " ");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|  1  |   %-45s|\n", "Create new directory");
    printf("\t\t\t|  2  |   %-45s|\n", "Create new file in a directory");
    printf("\t\t\t|  3  |   %-45s|\n", "Create sub directory");
    printf("\t\t\t|  4  |   %-45s|\n", "Delete a directory");
    printf("\t\t\t|  5  |   %-45s|\n", "Delete a file");
    printf("\t\t\t|  6  |   %-45s|\n", "Print list of files and subdirectories");
    printf("\t\t\t|  7  |   %-45s|\n", "Quit");
    printf("\t\t\t|======================================================|\n");
}
int tontaithumuc(directory Now, char key)
{
    int i = 0;
    while (Now.thumuc[i].name != '0')
    {
        if (Now.thumuc[i].name == key)
        {
            return 1;
        }
        i++;
    }
    return 0;
}
void taothumuc(directory *Now, char key)
{
    int i = 0;
    while (Now->thumuc[i].name != '0')
        i++;
    Now->thumuc[i].name = key;
}
void thumucdangco(directory *Now)
{
    int i = 0;
    printf("Thu muc dang ton tai trong thu muc hien hanh la: ");
    while (Now->thumuc[i].name != '0')
    {
        printf("%c  ", Now->thumuc[i].name);
        i++;
    }
    printf("\n");
}
void filedangco(directory *Now)
{
    int i = 0;
    printf("Cac file trong thu muc hien hanh la: ");
    i = 0;
    while (Now->file[i])
    {
        printf("%d  ", Now->file[i]);
        i++;
    }
    printf("\n");
}
void themthumuc(Node *Now, char *key)
{
    if (tontaithumuc(*(Now->thumuccon), *key))
    {
        puts("Invalid");
        *key = '0';
    }
    else
    {
        taothumuc(Now->thumuccon, *key);
    }
}
void MakeNullDir(directory *Now)
{
    for (int i = 0; i < MAX; i++)
    {
        Now->thumuc[i].name = '0';
        Now->file[i] = 0;
    }
}

int tontaifile(directory Now, int namef)
{
    int i = 0;
    while (Now.file[i])
    {
        if (Now.file[i] == namef)
            return 1;
        i++;
    }
    return 0;
}
void themfile(Node *Now, int namef)
{
    int i;
    if (namef != 0)
        if (tontaifile(*(Now->thumuccon), namef))
        {
            i = 0;
            int n = 0;
            while (Now->thumuccon->file[i])
            {
                n = n > Now->thumuccon->file[i] ? n : Now->thumuccon->file[i];
                i++;
            }
            themfile(Now, n + 1);
        }
        else
        {
            i = 0;
            while (Now->thumuccon->file[i])
                i++;
            Now->thumuccon->file[i] = namef;
            printf("Thu muc hien hanh la: %c\n", Now->name);
        }
}
void taothumuccon(Node *Now)
{
    char tenthumuc;
    int i;
    do
    {
        scanf("%c", &tenthumuc);
        i = 0;
        while (Now->thumuccon->thumuc[i].name != '0')
        {
            Node *////
        }

    } while (1);
}
int main(void)
{
    Node D;
    D.name = 'E';
    D.thumuccon = (directory *)malloc(sizeof(directory));
    MakeNullDir(D.thumuccon);
    int chose, namef;
    char namedir, tenthumuccon;
    int i;
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
            do
            {
                scanf("%c", &namedir);
                __fpurge(stdin);
                themthumuc(&D, &namedir);
            } while (namedir != '0');
            thumucdangco(D.thumuccon);
            break;
        case 2:
            do
            {
                scanf("%d", &namef);
                __fpurge(stdin);
                themfile(&D, namef);
            } while (namef);
            filedangco(D.thumuccon);
            break;
        case 3:
            taothumuccon(&D);
            break;
        case 4:
            /* Lua chon thu tu */
            break;
        case 5:
            /* Lua chon thu tu */
            break;
        case 6:
            /* Lua chon thu tu */
            break;
        case 7:
            printf("\tKet thuc chuong trinh\n");
            chose = 0;
            break;
        default:
            printf("Chi duoc chon cac so tu %d - %d!!!\n", 1, MAX_CHOSE);
            chose = 1;
            break;
        }
    } while (chose);
    free(D.thumuccon);
    return 0;
}