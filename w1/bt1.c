#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
typedef struct sinhvien
{
    char name[100];
    int stt;
}SV;
void main()
{
    FILE *fout;
    char name[]="ducga.txt";
    if((fout=fopen(name, "w+"))==NULL)
    {
        printf("File ko xac dinh.\n");
        exit(1);
    }
    SV sv[100];
    int i;
    for(i=0;i<3;i++)
    {
        printf("Hay nhap stt sinh vien thu %d: ", i+1);
        scanf("%d", &sv[i].stt);
        __fpurge(stdin);
        printf("Hay nhap ten cua sinh vien nay: ");
        gets(sv[i].name);
        fprintf(fout,"%d\t%s\n", sv[i].stt, sv[i].name);
    }
    fclose(fout);
}