#include "bin.h"
BinaryTree *MakeTreeNode(ElementType x)
{
    BinaryTree *root;
    root = (BinaryTree *)malloc(sizeof(BinaryTree));
    root->left = NULL;
    root->right = NULL;
    root->data = x;
    return root;
}
int SupperCmp(ElementType x, ElementType y, int mode /*Chon che do lam viec cho compare*/)
{
    switch (mode)
    {
    case 1:
        return strcmp(x.name, y.name);
        break;
    case 2:
        return strcmp(x.phone, y.phone);
        break;
    case 3:
        return strcmp(x.email, y.email);
        break;
    default:
        puts("Fail!! Khong the sap xep!");
        exit(1);
        break;
    }
}
BinaryTree *InsertData(BinaryTree *tree, ElementType x, int mode /*Chon che do lam viec cho compare*/)
//Phai khai bao nut goc bang NULL luc dau
{
    /*Nho goi ham nay phai la tree = InsertData(tree, x, mode)*/

    if (tree == NULL)
    {
        return MakeTreeNode(x);
    }
    else
    {
        if (SupperCmp(x, tree->data, mode) > 0)
        {
            tree->right = InsertData(tree->right, x, mode);
            return tree;
        }
        if (SupperCmp(x, tree->data, mode) < 0)
        {
            tree->left = InsertData(tree->left, x, mode);
            return tree;
        }
        return tree;
    }
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
    if (tree)
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
BinaryTree *Min(BinaryTree *tree)
{
    BinaryTree *root;
    root = tree;
    while (root->left)
    {
        root = root->left;
    }
    return root;
}
BinaryTree *Max(BinaryTree *tree)
{
    BinaryTree *root;
    root = tree;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
BinaryTree *Delete(BinaryTree *tree, ElementType x, int mode /*Chon che do lam viec cho compare*/)
{
    /*Nho goi ham nay phai la tree = Delete(tree, x, mode)*/
    if (tree)
    {
        /*Buoc co so*/
        if (SupperCmp(x, tree->data, mode) == 0)
        {
            if (tree->left == NULL && tree->right == NULL) //Truong hop nut la nut la
            {
                free(tree);
                return NULL;
            }
            if (tree->left == NULL) //Truong hop nut chi co nut con ben phai
            {
                BinaryTree *root;
                root = tree->right;
                free(tree);
                return root;
            }
            if (tree->right == NULL) //Truong hop nut chi co con ben trai
            {
                BinaryTree *root;
                root = tree->left;
                free(tree);
                return root;
            }
            tree->data = Min(tree->right)->data; //Truong hop nut co du ca hai nut con trai va phai
            tree->right = Delete(tree->right, tree->data, mode);
            // tree->data =*Max(tree->left)->data;
            // tree->left = Delete(tree->left, tree->data, mode)
            return tree;
        }
        /*Buoc de quy*/
        if (SupperCmp(x, tree->data, mode) > 0)
        {
            tree->right = Delete(tree->right, x, mode);
            return tree;
        }
        else
        {
            tree->left = Delete(tree->left, x, mode);
            return tree;
        }
    }
    return NULL;
}
void Fprint(FILE *f, ElementType x)
{
    fputs(x.name, f);
    fputs(x.phone, f);
    fputs(x.email, f);
}
void PrintData(FILE *f, BinaryTree *tree)
{
    if (tree)
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
            PrintData(f, tree->left);
            Fprint(f, tree->data); /*Thay doi vi tri cua goi ham nay len tren hoac xuong de duoc in ra data theo tien to hoac hau to*/
            PrintData(f, tree->right);
        }
    }
}
void PrintDataVip(FILE *f, BinaryTree *tree)
{
    if (tree)
    {
        PrintDataVip(f, tree->left);
        Fprint(f, tree->data); /*Thay doi vi tri cua goi ham nay len tren hoac xuong de duoc in ra data theo tien to hoac hau to*/
        PrintDataVip(f, tree->right);
    }
}
BinaryTree *BinarySearch(BinaryTree *tree, ElementType key, int mode /*Chon che do lam viec cho compare*/)
{
    if (tree)
    {
        if (SupperCmp(key, tree->data, mode) == 0)
        {
            return tree;
        }
        if (SupperCmp(key, tree->data, mode) < 0)
        {
            return BinarySearch(tree->left, key, mode);
        }
        return BinarySearch(tree->right, key, mode);
    }
    return tree;
}

void PrintData_duyet_anh_em(FILE *f, BinaryTree *tree);