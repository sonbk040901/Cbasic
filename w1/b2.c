#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void main()
{
    FILE *in, *out;
    int n;
    char *f;
    char *namefile="~/Cbasic/w1/in.txt";
    char *namefile1="~/Cbasic/w1/out.txt";
    in=fopen(namefile, "a+");
    out=fopen(namefile1, "w+");
    f=malloc(MAX*sizeof(char));
    fprintf(in,"Day la mot dong text.\n");
    fclose(in);
    in=fopen(namefile, "r");
    printf("So luong ky tu can copy la:");
    scanf("%d", &n);
    fgets(f,n,in);
    fprintf(out, "Noi dung: %s", f);
    fclose(in);
    fclose(out);
    free(f);
}