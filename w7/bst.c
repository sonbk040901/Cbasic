#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
typedef struct Address
{
    char name[40];
    char phone[15];
    char email[40];
} Address;
typedef Address ElementType;
typedef struct binaryTree
{
    ElementType data;
    struct binaryTree *right;
    struct binaryTree *left;
} binaryTree;
binaryTree *InsertData(binaryTree *tree, ElementType x)
{
    if (tree == NULL)
    {
        binaryTree *node;
        node = (binaryTree *)malloc(sizeof(binaryTree));
        node->data = x;
        node->right = NULL;
        node->left = NULL;
        return node;
    }
    else if (strcmp(tree->data.name, x.name) > 0)
    {
        tree->right = InsertData(tree->right, x);
        return tree;
    }
    else
    {
        tree->left = InsertData(tree->left, x);
        return tree;
    }
}
void Print(FILE *f, ElementType x)
{
    fputs(x.name, f);
    fputs(x.phone, f);
    fputs(x.email, f);
}
void PrintData(FILE *f, binaryTree *tree)
{
    if (tree != NULL)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            Print(f, tree->data);
            binaryTree *freeNode;
            freeNode = (binaryTree *)malloc(sizeof(binaryTree));
            freeNode = tree;
            tree = NULL;
            free(freeNode);
        }
        else
        {
            PrintData(f, tree->right);
            Print(f, tree->data);
            PrintData(f, tree->left);
        }
    }
}
void main()
{
    FILE *fin;
    FILE *fout;
    fin = fopen("data.txt", "r");
    fout = fopen("datasx.txt", "w+");
    ElementType x;
    binaryTree *tree = NULL;
    while (!feof(fin))
    {
        if (fgets(x.name, 40, fin))
        {
            fgets(x.phone, 15, fin);
            fgets(x.email, 40, fin);
            tree = InsertData(tree, x);
        }
    }
    PrintData(fout, tree);
    fclose(fin);
    fclose(fout);
}