#include "bin.h"
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
        if (strcmp(x.key, tree->data.key) < 0)
        {
            tree->right = InsertData(tree->right, x);
            return tree;
        }
        if (strcmp(x.key, tree->data.key) > 0)
        {
            tree->left = InsertData(tree->left, x);
            return tree;
        }
        tree->data.dem++;
        return tree;
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
        if (strcmp(x.key, tree->data.key) == 0)
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
        if (strcmp(x.key, tree->data.key) < 0)
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
    fputs(x.key, f);
    fprintf(f, ": %d\n", x.dem);
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
            tree = NULL;
            free(freeNode);
        }
        else
        {
            PrintData(f, tree->right);
            Fprint(f, tree->data);
            PrintData(f, tree->left);
        }
    }
}