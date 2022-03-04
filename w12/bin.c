#include "bin.h"
#include <stdio_ext.h>
BinaryTree *MakeTreeNull(ElementType x)
{
    BinaryTree *root;
    root = (BinaryTree *)malloc(sizeof(BinaryTree));
    root->left = NULL;
    root->right = NULL;
    root->data = x;
    return root;
}
BinaryTree *InsertData(BinaryTree *tree, ElementType x)
{
    if (tree == NULL)
    {
        return MakeTreeNull(x);
    }
    else
    {
        if (strcmp(x.anh, tree->data.anh) < 0)
        {
            tree->right = InsertData(tree->right, x);
            return tree;
        }
        if (strcmp(x.anh, tree->data.anh) > 0)
        {
            tree->left = InsertData(tree->left, x);
            return tree;
        }
    }
    return tree;
}
BinaryTree *InsertData3(BinaryTree *tree, ElementType *x)
{
    char luachon;
    if (tree == NULL)
    {
        printf("Hay nhap nghia cua tu tieng anh %s: ", x->anh);
        scanf("%s", x->viet);
        __fpurge(stdin);
        return MakeTreeNull(*x);
    }
    else
    {
        if (strcmp(x->anh, tree->data.anh) == 0)
        {
            printf("Bi trung tu da co, ban co muon thay doi thong tin(y/n)? ");
            scanf("%c", &luachon);
            __fpurge(stdin);
            if (luachon == 'y')
            {
                printf("Hay nhap nghia cua tu tieng anh %s: ", x->anh);
                scanf("%s", x->viet);
                strcpy(tree->data.viet, x->viet);
                __fpurge(stdin);
            }
            else
            {
                return tree;
            }
        }
        if (strcmp(x->anh, tree->data.anh) < 0)
        {
            tree->right = InsertData3(tree->right, x);
            return tree;
        }
        if (strcmp(x->anh, tree->data.anh) > 0)
        {
            tree->left = InsertData3(tree->left, x);
            return tree;
        }
    }
    return tree;
}
int sonut(BinaryTree *tree)
{
    if (tree == NULL)
        return 0;
    int a = sonut(tree->left);
    int b = sonut(tree->right);
    return a + b + 1;
}
int sola(BinaryTree *tree)
{
    if (tree != NULL)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            return 1;
        }
        else
        {
            return sola(tree->left) + sola(tree->right);
        }
    }
    return 0;
}
int docao(BinaryTree *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int a, b;
        a = docao(tree->left);
        b = docao(tree->right);
        return a > b ? ++a : ++b;
    }
}
BinaryTree *Minleft(BinaryTree *tree)
{
    BinaryTree *root;
    root = tree;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}
BinaryTree *Delete(BinaryTree *tree, ElementType x)
{
    if (tree != NULL)
    {
        if (strcmp(x.anh, tree->data.anh) == 0)
        {
            if (tree->left == NULL && tree->right == NULL)
            {
                free(tree);
                return NULL;
            }
            if (tree->left == NULL)
            {
                BinaryTree *root;
                root = tree->right;
                free(tree);
                return root;
            }
            if (tree->right == NULL)
            {
                BinaryTree *root;
                root = tree->left;
                free(tree);
                return root;
            }
            tree->data = Minleft(tree->right)->data;
            tree->right = Delete(tree->right, tree->data);
            return tree;
        }
        if (strcmp(x.anh, tree->data.anh) < 0)
        {
            tree->right = Delete(tree->right, x);
            return tree;
        }
        else
        {
            tree->left = Delete(tree->left, x);
            return tree;
        }
    }
}
void Fprint(FILE *f, ElementType x)
{
    fprintf(f, "%s %s\n", x.anh, x.viet);
}
void PrintData(FILE *f, BinaryTree *tree)
{
    if (tree != NULL)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            Fprint(f, tree->data);
            BinaryTree *freeNode;
            freeNode = (BinaryTree *)malloc(sizeof(BinaryTree));
            freeNode = tree;
        }
        else
        {
            PrintData(f, tree->right);
            Fprint(f, tree->data);
            PrintData(f, tree->left);
        }
    }
}
void Print(FILE *f, BinaryTree *tree)
{
    if (tree != NULL)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            Fprint(f, tree->data);
            BinaryTree *freeNode;
            freeNode = (BinaryTree *)malloc(sizeof(BinaryTree));
            freeNode = tree;
        }
        else
        {
            Fprint(f, tree->data);
            Print(f, tree->right);
            Print(f, tree->left);
        }
    }
}
ElementType PopData(FILE *f)
{
    ElementType x = {"NULL", "NULL"};
    if (fscanf(f, "%s", x.anh))
        fscanf(f, "%s", x.viet);
    return x;
}
void PrintData_duyet_anh_em(FILE *f, BinaryTree *tree);