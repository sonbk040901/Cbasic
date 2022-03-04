#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
void main(int arg, char *namef[])
{
    FILE *fin, *fout;
    char *str, name1[] = "filetext";
    int i = 0;
    str = malloc(MAX * sizeof(char));
    if ((fin = fopen(name1, "r")) == NULL || (fout = fopen(namef[1], "w+")) == NULL)
    {
        printf("Loi tao file!\n");
        exit(1);
    }
    do
    {
        i++;
        fgets(str, MAX, fin);
        fprintf(fout, "%d\t", i);
        fputs(str, fout);
    } while (!feof(fin));
    free(str);
    fclose(fin);
    fclose(fout);
}