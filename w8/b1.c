#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 100
typedef int ElementType;
struct BT
{
    ElementType value;
    struct BT *right;
    struct BT *left;
};
typedef struct BT BinaryTree;
BinaryTree *MakeTreeNull(ElementType x)
{
    BinaryTree *root;
    root = (BinaryTree *)malloc(sizeof(BinaryTree));
    root->left = NULL;
    root->right = NULL;
    root->value = x;
    return root;
}
BinaryTree *insert(BinaryTree *tree, ElementType x)
{
    if (tree == NULL)
    {
        return MakeTreeNull(x);
    }
    else
    {
        if (x > tree->value)
        {
            tree->right = insert(tree->right, x);
            return tree;
        }
        if (x < tree->value)
        {
            tree->left = insert(tree->left, x);
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
    printf("%d\n", tree->value);
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
BinaryTree *delete (BinaryTree *tree, ElementType x)
{
    if (tree != NULL)
    {
        if (tree->value == x)
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
            tree->value = Minleft(tree->right)->value;
            tree->right = delete (tree->right, tree->value);
            return tree;
        }
        if (x > tree->value)
        {
            tree->right = delete (tree->right, x);
            return tree;
        }
        else
        {
            tree->left = delete (tree->left, x);
            return tree;
        }
    }
}
int sizechu(BinaryTree *tree)
{
    if (tree == NULL)
        return 0;
    int a = sizechu(tree->left);
    int b = sizechu(tree->right);
    int c = (int)log10(tree->value) + 1;
    return a > b ? a > c ? a : c : b > c ? b : c;
}
// void printtree(BinaryTree *tree)
// {
//     int h = docao(tree);
// }
void main()
{
    BinaryTree *tree = NULL;
    int n /*m*/;
    ElementType x;
    puts("Hay nhap gia tri n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        tree = insert(tree, x);
    }
    // for (int i = 0; i < m; i++)
    // {
    //     scanf("%d", &x);
    //     tree = insert(tree, x);
    // }
    putchar('\n');
    printf("So nut cua cay la: %d\n", sonut(tree));
    printf("So luong nut la: %d\n", sola(tree));
    printf("Do cao cua cay la: %d\n", docao(tree));
    printf("Kich thuoc cua chu so la: %d\n", sizechu(tree));
    while (tree != NULL)
    {
        printf("Nhap gia tri cua node ma ban muon xoa: ");
        scanf("%d", &x);
        tree = delete (tree, x);
        printf("So nut cua cay la: %d\n", sonut(tree));
        printf("So luong nut la: %d\n", sola(tree));
        printf("Do cao cua cay la: %d\n", docao(tree));
        printf("Kich thuoc cua chu so la: %d\n", sizechu(tree));
    }
}