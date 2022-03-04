#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define MAX_CHOSE 5
void menu(void)
{
    printf("\t\t\t|======================================================|\n");
    printf("\t\t\t|%25sMENU%25s|\n", " ", " ");
    printf("\t\t\t|------------------------------------------------------|\n");
    printf("\t\t\t|  1  |   %-45s|\n", "Lua chon thu nhat");
    printf("\t\t\t|  2  |   %-45s|\n", "Lua chon thu hai");
    printf("\t\t\t|  3  |   %-45s|\n", "Lua chon thu ba");
    printf("\t\t\t|  4  |   %-45s|\n", "Lua chon thu tu");
    printf("\t\t\t|  5  |   %-45s|\n", "Ket thuc chuong trinh");
    printf("\t\t\t|======================================================|\n");
}
int main()
{
    int chose;
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
            /* Lua chon thu nhat */
            break;
        case 2:
            /* Lua chon thu hai */
            break;
        case 3:
            /* Lua chon thu ba */
            break;
        case 4:
            /* Lua chon thu tu */
            break;
        case 5:
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