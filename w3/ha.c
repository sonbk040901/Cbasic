#include<stdio.h>
#include<stdlib.h>
#define SUCCESS 0
#define FAIL 1
#define MAX_ELEMENT 20
// cau truc cua so danh ba
typedef struct phoneaddress_t
{
    char name[20];
    char tell[11];
    char email[25];
}phoneaddress;
int main (int b, char* name1[]){
    int n;
    FILE *fp;
    fp = fopen(name1[1],"w+");
    if(fp == NULL){
        printf("khong the mo file");
        exit(1);
    }
    phoneaddress pp[100];
    printf("Nhap vao so luong danh ba:");
    scanf("%d",&n);
    char enter;
    scanf("%c",&enter);
    for(int i=0;i<n;i++){
        printf("Nhap ten nguoi thu %d:",i+1);
        gets(pp[i].name);
        printf("Nhap vao so dien thoai nguoi thu %d: ",i+1);
        gets(pp[i].tell);
        printf("Nhap vao email nguoi thu %d: ",i+1);
        gets(pp[i].email);
    }
    fwrite(pp,sizeof(char),MAX_ELEMENT,fp);
    fclose(fp);
    return 0;
}