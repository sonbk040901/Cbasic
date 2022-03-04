#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char *Chuan_hoa_ten(char *name, int mode)
{
    char *cut, **a, *Real;
    a = (char **)malloc(sizeof(char *) * 10);
    Real = (char *)malloc(sizeof(char) * 40);
    cut = strtok(name, " ");
    int i = 0;
    do
    {
        a[i] = cut;
        a[(i++) + 1] = NULL;
        cut = strtok(NULL, " ");
    } while (cut);
    switch (mode)
    {
    case 1: /*Viet hoa chu cai dau*/
        i = 0;
        while (a[i])
        {
            for (int j = 0; j < strlen(a[i]); j++)
            {
                if (j)
                    a[i][j] = tolower(a[i][j]);
                else
                    a[i][j] = toupper(a[i][j]);
            }
            if (i)
                strcat(Real, " ");
            strcat(Real, a[i++]);
        }
        free(a);
        return Real;
        break;
    case 2: /*Viet hoa tat ca chu cai*/
        i = 0;
        while (a[i])
        {
            for (int j = 0; j < strlen(a[i]); j++)
                a[i][j] = toupper(a[i][j]);
            if (i)
                strcat(Real, " ");
            strcat(Real, a[i++]);
        }
        free(a);
        return Real;
        break;
    case 3: /*Viet thuong tat ca cac chu cai*/
        i = 0;
        while (a[i])
        {
            for (int j = 0; j < strlen(a[i]); j++)
                a[i][j] = tolower(a[i][j]);
            if (i)
                strcat(Real, " ");
            strcat(Real, a[i++]);
        }
        free(a);
        return Real;
        break;
    default:
        free(a);
        free(Real);
        return NULL;
        break;
    }
}
int main()
{
    char a[40], *b;
    int mode;
    // FILE *f;
    // f = fopen("test.txt", "r+");
    // while (!feof(f))
    // {
    //     if (fscanf(f, "%s", a) > 0)
    //         fputs(a, stdout);
    // }
    // fseek(f, 0, SEEK_SET);
    // fputs("em yeu anh\nanh cung yeu anh\n", f);
    // printf("\n");
    // fclose(f);
    fgets(a, 40, stdin);
    a[strlen(a) - 1] = 0;
    scanf("%d", &mode);
    b = Chuan_hoa_ten(a, mode);
    if (b)
    {
        printf("%s\n", b);
        free(b);
    }
    else
        puts("Khong the chuan hoa ten");
    return 0;
}