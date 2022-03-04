#include "B1.h"
QUEUE *MakeNullQueue(void)
{
    QUEUE *New;
    New = (QUEUE *)malloc(sizeof(QUEUE));
    LinkList *root;
    root = (LinkList *)malloc(sizeof(LinkList));
    root->next = NULL;
    New->Rear = root;
    New->Front = root;
    return New;
}
int sizeQ(QUEUE *Q)
{
    int i = 0;
    LinkList *root;
    root = Q->Front;
    while (root != Q->Rear)
    {
        root = root->next;
        i++;
    }
    return i;
}
int isEmpty(QUEUE *Q)
{
    return (Q->Front == Q->Rear);
}
int isFull(QUEUE *Q)
{
    return (sizeQ(Q) == FULL);
}
LinkList *front(QUEUE *Q)
{
    if (!isEmpty(Q))
    {
        return Q->Front;
    }
    else
    {
        return NULL;
    }
}
void EnQueue(QUEUE *Q, BinaryTree x)
{
    if (!isFull(Q))
    {
        Q->Rear->next = (LinkList *)malloc(sizeof(LinkList));
        Q->Rear = Q->Rear->next;
        Q->Rear->data1 = x;
        Q->Rear->next = NULL;
    }
    else
    {
        printf("Full Queue!\n");
    }
}
BinaryTree DeQueue(QUEUE *Q)
{
    if (!isEmpty(Q))
    {
        BinaryTree x;
        LinkList *Head;
        Head = Q->Front;
        Q->Front = Q->Front->next;
        x = Q->Front->data1;
        free(Head);
        return x;
    }
    else
    {
        printf("Empty Queue!\n");
    }
}
void Print(QUEUE *Q) /*Ham nay tuy thuoc vao cau truc du lieu cua data*/
{
    /* code */
}


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
        if (strcmp(x.email, tree->data.email) < 0)
        {
            tree->right = InsertData(tree->right, x);
            return tree;
        }
        if (strcmp(x.email, tree->data.email) > 0)
        {
            tree->left = InsertData(tree->left, x);
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
        if (strcmp(x.email, tree->data.email) == 0)
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
        if (strcmp(x.email, tree->data.email) < 0)
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
    fputs(x.name, f);
    fputs(x.phone, f);
    fputs(x.email, f);
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
void PrintData_duyet_anh_em(FILE *f, BinaryTree tree)
{
    QUEUE *Q;
    Q = MakeNullQueue();
    EnQueue(Q, tree);
    do
    {
        BinaryTree root = DeQueue(Q);
        if (root.right != NULL)
        {
            EnQueue(Q, *(root.right));
        }
        if (root.left != NULL)
        {
            EnQueue(Q, *(root.left));
        }
        Fprint(f, root.data);
    } while (!isEmpty(Q));
}