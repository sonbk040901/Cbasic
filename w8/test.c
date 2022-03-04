#include <stdio.h>
#include <stdlib.h>
static int chose;
typedef int ElementType;
struct BT
{
    ElementType data;
    struct BT *rightNode;
    struct BT *leftNode;
};
typedef struct BT BinaryTree;
BinaryTree *MakeData(int x)
{
    BinaryTree *NewNode;
    NewNode = (BinaryTree *)malloc(sizeof(BinaryTree));
    NewNode->data = x;
    NewNode->leftNode = NULL;
    NewNode->rightNode = NULL;
    return NewNode;
}
BinaryTree *insert(BinaryTree *tree, ElementType key, ElementType x)
{
    if (tree != NULL)
        if (tree->data == key)
        {
            if (chose)
            {
                if (tree->leftNode != NULL)
                {
                    tree->leftNode->data = x;
                    return tree;
                }
                else
                {
                    tree->leftNode = MakeData(x);
                    return tree;
                }
            }
            else
            {
                if (tree->rightNode != NULL)
                {
                    tree->rightNode->data = x;
                    return tree;
                }
                else
                {
                    tree->rightNode = MakeData(x);
                    return tree;
                }
            }
        }
        else
        {
            tree->leftNode = insert(tree->leftNode, key, x);
            tree->rightNode = insert(tree->rightNode, key, x);
            return tree;
        }
}
void printTree(BinaryTree *tree)
{
    if (tree != NULL)
    {
        printTree(tree->leftNode);
        printf("data:%d ", tree->data);
        printTree(tree->rightNode);
    }
}
void freeTree(BinaryTree *tree)
{
    if (tree != NULL)
    {
        freeTree(tree->leftNode);
        freeTree(tree->rightNode);
        free(tree);
    }
}
int main()
{
    int n;
    ElementType x, key;
    BinaryTree *tree = NULL;
    puts("Nhap so phan tu ban muon nhap vao:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (tree == NULL)
        {
            puts("Gia tri ma ban muon chen vao:");
            scanf("%d", &x);
            tree = MakeData(x);
        }
        else
        {
            puts("Hay nhap vao gia tri cua node ma ban muon chen vao ben duoi:");
            scanf("%d", &key);
            puts("Ban muon chen vao trai hay phai(trai: 1; phai: 0)");
            scanf("%d", &chose);
            puts("Gia tri ma ban muon chen vao:");
            scanf("%d", &x);
            tree = insert(tree, key, x);
        }
    }
    printTree(tree);
    putchar('\n');
    freeTree(tree);
    return 0;
}