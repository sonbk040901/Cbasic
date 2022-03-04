#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
void main()
{
    FILE *fin, *fout;
    char *str, name1[] = "filetext";
    str = malloc(MAX * sizeof(char));
    char namef[] = "newfile";
    if ((fin = fopen(name1, "r")) == NULL || (fout = fopen(namef, "w+")) == NULL)
    {
        printf("Loi file!\n");
        exit(1);
    }
    do
    {
        fgets(str, MAX, fin);
        fprintf(fout, "%ld\t", strlen(str));
        for (int i = 0; i < strlen(str); i++)
            if (isalpha(str[i]))
                if (isupper(str[i]))
                    str[i] = tolower(str[i]);
                else
                    str[i] = toupper(str[i]);
        fputs(str, fout);
    } while (!feof(fin));
    free(str);
    fclose(fin);
    fclose(fout);
}