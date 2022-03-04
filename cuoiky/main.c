#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "lkd.h"
#include <ctype.h>
#define MAX_CHOSE 5
int somaytoida = 0;
void menu(void)
{
    printf("\t\t\t|======================================================|\n");
    printf("\t\t\t|%25sMENU%25s|\n", " ", " ");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|  1  |   %-45s|\n", "Load Data Files");
    printf("\t\t\t|  2  |   %-45s|\n", "Update CPU info");
    printf("\t\t\t|  3  |   %-45s|\n", "Update RAM info");
    printf("\t\t\t|  4  |   %-45s|\n", "Search");
    printf("\t\t\t|  5  |   %-45s|\n", "Quit");
    printf("\t\t\t|======================================================|\n");
}
int main()
{
    FILE *f;
    char namefile[30], namecpu[30];
    int chose;
    int n, idmay, dungluongram;
    ElementType data;
    PointerType *First, *root;
    First = NULL;
    int thoatcase;
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
            thoatcase = 0;
            printf("Hay nhap ten file ban muon mo: ");
            fgets(namefile, 30, stdin);
            namefile[strlen(namefile) - 1] = 0;
            f = fopen(namefile, "r");
            if (!f)
            {
                puts("File khong ton tai!!!");
                break;
            }
            fscanf(f, "%d", &n);
            __fpurge(stdin);
            for (int i = 0; i < n; i++)
            {
                if (somaytoida >= 20)
                {
                    printf("Danh sach da day khong them duoc!\n");
                    thoatcase = 1;
                    break;
                }
                fscanf(f, "%s   %d/n", (data.tencpu), &(data.dungluong));
                First = InsertToLast(First, data);
                somaytoida++;
            }
            root = First;
            while (root)
            {
                printf("%s  %d\n", root->data.tencpu, root->data.dungluong);
                root = root->Next;
            }
            if (thoatcase)
            {
                break;
            }
            fclose(f);
            break;
        case 2:
            printf("Hay nhap id cua may ma ban muon cap nhat: ");
            strcpy(namecpu, " ");
            do
            {
                scanf("%d", &idmay);
                __fpurge(stdin);
                if (strcmp(namecpu, "I3") && strcmp(namecpu, "I5") && strcmp(namecpu, "I7"))
                {
                    printf("Hay nhap ten moi cho CPU: ");
                    scanf("%s", namecpu);
                    namecpu[0] = toupper(namecpu[0]);
                    __fpurge(stdin);
                }
                if (idmay < 1 || idmay > somaytoida)
                {
                    printf("Nhap sai id may!\n");
                    continue;
                }
                if (namecpu[0] != 'I' || (namecpu[1] != '3' && namecpu[1] != '5' && namecpu[1] != '7') && strcmp(namecpu, "STOP"))
                {
                    printf("Nhap sai hay nhap lai!\n");
                    continue;
                }
                root = First;
                if (idmay != 1)
                    for (int i = 0; i < idmay - 1; i++)
                    {
                        root = root->Next;
                    }
                else
                {
                    strcpy(First->data.tencpu, namecpu);
                }
                strcpy(root->data.tencpu, namecpu);
            } while (idmay < 1 || idmay > somaytoida || (namecpu[0] != 'I' || (namecpu[1] != '3' && namecpu[1] != '5' && namecpu[1] != '7')) && strcmp(namecpu, "STOP"));
            for (int i = idmay + 1; i <= somaytoida && strcmp(namecpu, "STOP"); i++)
            {
                printf("Hay tiep tuc nhap ten cho may id %d: ", i);
                __fpurge(stdin);
                scanf("%s", namecpu);
                __fpurge(stdin);
                if (strcmp(namecpu, "I3") && strcmp(namecpu, "I5") && strcmp(namecpu, "I7") && strcmp(namecpu, "STOP"))
                {
                    i--;
                    printf("Nhap sai ten!!!\n");
                    continue;
                }
                root = root->Next;
                strcpy(root->data.tencpu, namecpu);
            }
            root = First;
            while (root)
            {
                printf("%s  %d\n", root->data.tencpu, root->data.dungluong);
                root = root->Next;
            }
            break;
        case 3:
            printf("Hay nhap id cua may ma ban muon cap nhat: ");
            dungluongram = 0;
            do
            {
                scanf("%d", &idmay);
                __fpurge(stdin);
                if (dungluongram != 1 && dungluongram != 2 && dungluongram != 4 && dungluongram != 8 && dungluongram != 16 && dungluongram != 32)
                {
                    printf("Hay nhap dung luong moi cho RAM: ");
                    scanf("%d", &dungluongram);
                    __fpurge(stdin);
                }
                if (idmay < 1 || idmay > somaytoida)
                {
                    printf("Nhap sai id may!\n");
                    continue;
                }
                if (dungluongram != 1 && dungluongram != 2 && dungluongram != 4 && dungluongram != 8 && dungluongram != 16 && dungluongram != 32 && dungluongram != 999)
                {
                    printf("Nhap sai dung luong RAM hay nhap lai!\n");
                    continue;
                }
                root = First;
                if (idmay != 1)
                    for (int i = 0; i < idmay - 1; i++)
                    {
                        root = root->Next;
                    }
                else
                {
                    First->data.dungluong = dungluongram;
                }
                root->data.dungluong = dungluongram;
            } while (idmay < 1 || idmay > somaytoida || (dungluongram != 1 && dungluongram != 2 && dungluongram != 4 && dungluongram != 8 && dungluongram != 16 && dungluongram != 32 && dungluongram != 999));
            for (int i = idmay + 1; i <= somaytoida && dungluongram != 999; i++)
            {
                printf("Hay tiep tuc nhap dung cho may id %d: ", i);
                __fpurge(stdin);
                scanf("%d", &dungluongram);
                __fpurge(stdin);
                if (dungluongram != 1 && dungluongram != 2 && dungluongram != 4 && dungluongram != 8 && dungluongram != 16 && dungluongram != 32 && dungluongram != 999)
                {
                    i--;
                    printf("Nhap sai dung luong RAM!!!\n");
                    continue;
                }
                root = root->Next;
                root->data.dungluong = dungluongram;
            }
            root = First;
            while (root)
            {
                printf("%s  %d\n", root->data.tencpu, root->data.dungluong);
                root = root->Next;
            }
            break;
        case 4:
            printf("Hay nhap du lieu ma ban muon tim kiem: ");
            
            break;
        case 5:
            MakeNull(First);
            printf("\tKet thuc chuong trinh\n");
            chose = 0;
            break;
        default:
            printf("Chi duoc chon cac so tu %d - %d!!!\n", 1, MAX_CHOSE);
            chose = 1;
            break;
        }
    } while (chose);
    return 0;
}