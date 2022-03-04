#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX 100
typedef struct Address
{
    char name[40];
    char phone[15];
    char email[40];
}Address;
typedef Address ElementType;
char *locten(char *hovaten, char *mssv)
{
    char ten[10], ho[7], *mailhust;
    mailhust = (char *)malloc(sizeof(char) * 50);
    for (int i = strlen(hovaten) - 1; i >= 0; i--)
    {
        if (isupper(hovaten[i]))
        {
            strcpy(ten, &hovaten[i]);
            ten[strlen(ten) - 1] = 0;
            ten[0] = tolower(ten[0]);
            break;
        }
    }
    int j = -1;
    for (int i = 0; i < strlen(hovaten) - 1; i++)
    {
        if (isupper(hovaten[i]))
        {
            ho[++j] = tolower(hovaten[i]);
        }
    }
    ho[j] = 0;
    strcat(mailhust, ten);
    strcat(mailhust, ".");
    strcat(mailhust, ho);
    strcat(mailhust, mssv);
    strcat(mailhust, "@sis.hust.edu.vn");
    return mailhust;
}
void main()
{
    FILE *fin;
    FILE *fout;
    char tensv[40];
    char mssv[8];
    int i;
    ElementType data;
    fin = fopen("dataVN02.txt", "r");
    fout = fopen("data.txt", "w+");
    srand((unsigned)time(NULL));
    while (!feof(fin))
    {
        if (fgets(mssv, 9, fin))
        {
            fgets(data.name, 40, fin);
            strcpy(data.name, data.name + 1);
            i = 8;
            data.phone[0] = 48;
            data.phone[1] = 57;
            while (i)
            {
                data.phone[10 - i--] = rand() % 10 + 48;
            }
            data.phone[10] = 0;
            strcpy(data.email, locten(data.name, mssv + 2));
            fprintf(fout, "%s%s\n%s\n", data.name, data.phone, data.email);
        }
    }
    fclose(fin);
    fclose(fout);
}