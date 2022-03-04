#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Address
{
    char name[40];
    char phone[15];
    char email[40];
};
typedef struct Address ElementType;
const ElementType zero = {"Not Found\n", "Not Found\n", "Not Found\n"};
struct Pointer /*Struct dinh nghia mang*/
{
    ElementType v;
    struct Pointer *Next;
};
typedef struct Pointer point;
point *Insert_ToHead(point *first, ElementType x) /*Ham them phan tu vao dau mang gia tri*/
{
    point *pointer;
    pointer = (point *)malloc(sizeof(point));
    pointer->v = x;
    pointer->Next = first;
    return pointer;
}
ElementType Pop_Data(FILE *f)
{
    ElementType *data;
    data = (ElementType *)malloc(sizeof(ElementType));
    fgets(data->name, MAX, f);
    fgets(data->phone, MAX, f);
    fgets(data->email, MAX, f);
    return *data;
}
point *Search(point *First, char *key, ElementType *data)
{
    point *root1;
    point *root2;
    root1 = First;
    while (root1 != NULL && strcmp(root1->v.name, key))
    {
        root2 = root1;
        root1 = root1->Next;
    }
    if (root1 != NULL)
    {
        *data = root1->v;
        root2->Next = root1->Next;
        First = Insert_ToHead(First, root1->v);
        free(root1);
    }
    else
        *data = zero;
    return First;
}
point *Search2(point *First, char *key, ElementType *data)
{
    point *root1;
    point *root2;
    root1 = First;
    while (root1 != NULL && strcmp(root1->v.name, key))
    {
        root2 = root1;
        root1 = root1->Next;
    }
    if (root1 != NULL)
    {
        *data = root1->v;
        ElementType temp;
        temp = root1->v;
        root1->v = root2->v;
        root2->v = temp;
    }
    else
        *data = zero;
    return First;
}
void Print_Data(FILE *f, ElementType data)
{
    fprintf(f, "Name: %sPhone number: %sEmail address: %s", data.name, data.phone, data.email);
}
void FREE(point *First)
{
    point *root, *freeNode;
    root = First;
    while (root != NULL)
    {
        freeNode = root;
        root = root->Next;
        free(freeNode);
    }
}
// void Print(FILE *f, point *mang) /*Ham in ra gia tri trong mang*/
// {
//     point *pointer;
//     pointer = (point *)malloc(sizeof(point));
//     pointer = mang;
//     while (pointer != NULL)
//     {
//         Print_Data(f, pointer->v);
//         pointer = pointer->Next;
//     }
//     putchar('\n');
// }
void main()
{
    char name[MAX];
    ElementType data;
    point *Arr = NULL;
    FILE *fin;
    FILE *fout;
    fin = fopen("data.txt", "r");
    fout = fopen("data1.txt", "w+");
    puts("Hay nhap ten cua nguoi ban can tim: ");
    fgets(name, MAX, stdin);
    while (!feof(fin))
    {
        Arr = Insert_ToHead(Arr, Pop_Data(fin));
    }
    fclose(fin);
    Arr = Search2(Arr, name, &data);
    // Print(fout, Arr);
    Print_Data(fout, data);
    FREE(Arr);
    fclose(fout);
}