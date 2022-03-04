#include<stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
typedef struct elementtype
{
    char name[20];
    char phone[15];
    char email[20];
} adr;
typedef struct addresslist
{
    adr data;
    struct addresslist
        *prev;
    struct addresslist
        *next;
} adrl;
adr nhapthongtin()
{
    adr infomation;
    puts("Hay nhap ten:");
    __fpurge(stdin);
    gets(infomation.name);
    __fpurge(stdin);
    puts("Hay nhap so dien thoai cua:");
    gets(infomation.phone);
    puts("Hay nhap email cua:");
    __fpurge(stdin);
    gets(infomation.email);
    return infomation;
}
int isEmpty(adrl *check)
{
    return check == NULL;
}
adrl *MakeData(adrl *new, adr x)
{
    new = (adrl *)malloc(sizeof(adrl));
    new->data = x;
    new->prev = NULL;
    return new;
}
adrl *MakeArray(adrl *new, adrl *first)
{
    new->next = first;
    first->prev = new;
    return new;
}
adrl *InserToHead(adrl *first, adr infomation)
{
    if (isEmpty(first))
    {
        first=(adrl *)malloc(sizeof(adrl));
        first->data = infomation;
        first->next = NULL;
        first->prev = NULL;
        return first;
    }
    else
    {
        adrl *node;
        node = MakeData(node, infomation);
        return MakeArray(node, first);
    }
}
void Printdata(adr x)
{
    puts(x.name);
    puts(x.phone);
    puts(x.email);
}
void Print(adrl *first)
{
    adrl *root = first;
    while (!isEmpty(root))
    {
        Printdata(root->data);
        root = root->next;
    }
}
void FreeData(adrl *first)
{
    adrl *root, *to_free;
    while (!isEmpty(root))
    {
        to_free = root;
        free(to_free);
        root = root->next;
    }
}